#include<bits/stdc++.h>
using namespace std;

void solve() {
    long long n; cin>>n;
    long long ans = pow(2, floor(log2(n)));
    cout<<fixed<<setprecision(0)<<ans<<endl;
}

int main() {
    int t; cin>>t;
    while(t--){
        solve();
    }
}