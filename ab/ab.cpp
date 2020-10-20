#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char const *argv[])
{
    int rez = 0;
    string line;
    ifstream in ("adunare.in");
    if (in.is_open())
    {
        while (getline(in, line))
        {
            rez += stoi(line);
        }
    }
    in.close();

    ofstream ot ("adunare.out");
    if (ot.is_open())
    {
       ot << rez;
       ot.close();
    }

}
