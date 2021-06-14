#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

#define f first
#define s second

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<pair<int,int>> p,q;
        for(int i=0; i<n; i++){
            int a,b; cin>>a>>b;
            p.push_back({a,b});
        }
        for(int i=0; i<n; i++){
            int a,b; cin>>a>>b;
            q.push_back({a,b});
        }
        p.push_back(p[0]), q.push_back(q[0]);

        vector<double> pslopes, qslopes;
        for(int i=0; i<n; i++){
            double dY = p[i+1].s-p[i].s;
            double dX = p[i+1].f-p[i].f;
            pslopes[i] = dY/dX;
        }
        for(int i=0; i<n; i++){
            double dY = q[i+1].s-q[i].s;
            double dX = q[i+1].f-q[i].f;
            qslopes[i] = dY/dX;
        }

        sort(begin(pslopes), end(pslopes));
        sort(begin(qslopes), end(qslopes));

        bool ok = true;
        for(int i=0; i<n; i++){
            if(pslopes[i]!=qslopes[i]) ok = false; 
        }
        cout<<(ok?"YES":"NO")<<endl;
    }
}