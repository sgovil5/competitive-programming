#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++) {
        cin>>v[i];
    }
    
    vector<int> leftMex(n);
    set<int> leftVis;
    int currLeftMex = 0;
    for(int i=0; i<n; i++) {
        leftVis.insert(v[i]);
        while(leftVis.count(currLeftMex)) {
            currLeftMex++;
        }
        leftMex[i] = currLeftMex;
    }

    vector<int> rightMex(n);
    set<int> rightVis;
    int currRightMex = 0;
    for(int i=n-1; i>=0; i--) {
        rightVis.insert(v[i]);
        while(rightVis.count(currRightMex)) {
            currRightMex++;
        }
        rightMex[i] = currRightMex;
    }
    
    int possible = false;
    for (int i=0; i<n; i++) {
        if(leftMex[i] == rightMex[i]) {
            possible = true;
        }
    }

    if(!possible) cout<<-1<<endl;
    else {
        int l1 = 1, r2 = n;
        int l2, r1;
        for(int i=0; i<n; i++) {
            if(leftMex[i] == rightMex[i]) {
                r1 = i+1;
                l2 = i+2;
                break;
            }
        }
        cout<<2<<endl;
        cout<<l1<<" "<<r1<<endl;
        cout<<l2<<" "<<r2<<endl;
    }
}

int main() {
    int t; cin>>t;
    while(t--) {
        solve();
    }
}