#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.1415926535897932384626
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define fo(i, n) for(i=1;i<=n;i++)

#define pb push_back

typedef vector<int> vi;

const int N = 300001;
const int oo = INT_MAX;
int a[N];

int n;
int solution() {

    
    si(n);
    // current value
    int i = 1;
    int x = 0;

    // prev value
    int pv = 0;
    int pvi = 0;

    // max value
    int mx = 0;
    int mxi = 0;

    // prev max value
    int pmx = 0;
    int pmxi = 0;

    // potential answer
    int pc = 0;
    int pci = 0;

    bool nope = true;
    fo(i,n) {
       
        si(x);


        if ((mxi + 1 == i) && (x < mx)) {
            pc = mx;
            pci = mxi;
        }

        if (x > mx) {
            mx = x;
            mxi = i;
            if((i != 1) && (pv < mx))
                pc = x;
                pci = i;
        }

        if ( x == mx) {
            mx = x;
            mxi = i;
        }

        if((i != 1) && (pv != x)) {
            nope = false;
        }

        pv = x;
        pvi = i;
       
       if(i == 1){
            mx = x;
            mxi = i;
       }

        
        
    }
    if (nope) {
        return -1;
    } else {
        return pci;
    }


}

int main() {
    
    int t = 1;
    si(t);
    vi sol;
    while(t--) {
        sol.pb(solution());
    }

    for(auto& val : sol) {
        pi(val);
    }

    return 0;
}
