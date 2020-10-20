#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <chrono>

using namespace std;
using namespace std::chrono; 

void extractIntFromLine(string line, vector<int> &v) {
    stringstream ss(line);
    int nb;
    while (ss >> nb)
    {
       v.push_back(nb);
    }
    
}

void extractTerms(int &n, int &m, string line) {
    vector<int> lineNumbers;
    extractIntFromLine(line, lineNumbers);
    n = lineNumbers[0];
    m = lineNumbers[1];
}



void rangeMode(int st, int dr, vector<int> freq, vector<int> &results) {

        if(st + 1 == dr) {
            results.push_back(1);
            return;

        }

        map<int,int> m;
        for(int i = st + 1; i<dr; i++) {
            m[i] = count(freq.begin(), freq.end(), i);
        }

        int who;
        int howMany = 0;
        for(map<int, int>::iterator it = m.begin(); it != m.end(); ++it ) {
            if(it->second > howMany) {
                who = it->first;
                howMany = it->second;
            }
            if(it->second == howMany && it->first < who) {
                who = it->first;
                howMany = it->second;
            }
        }

        results.push_back(who);
        
}

void ask(string line, vector<int> freq, vector<int> &results) {
    vector<int> bounds;
    extractIntFromLine(line, bounds);
    rangeMode(bounds[0], bounds[1], freq, results);
}


int main()
{   
    
    auto start = high_resolution_clock::now(); 
    string line;
    int lc = 1;
    int n;
    int m;
    vector<int> freq;
    vector<int> results;
    ifstream i("rangemode.in");
    if (i.is_open())
    {
        
        while (getline(i, line))
        {
           
           if(lc == 1) {
               extractTerms(n, m, line);
           } else if (lc == 2)
           {
               extractIntFromLine(line, freq);
           } else {
               ask(line, freq, results);
           }
            lc++;
        }
        
    }
    i.close();

    ofstream o("rangemode.out");
    if(o.is_open()) {
        for (auto& it : results) {
            o << it << endl;
        }
        o.close();
    }
    auto stop = high_resolution_clock::now(); 
     auto duration = duration_cast<microseconds>(stop - start); 
  
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl; 
         return 0;
    
}