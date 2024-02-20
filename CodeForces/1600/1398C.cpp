#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
void solve() {
    ll n; cin>>n;
    vector<ll> v, psum;
    set<ll> vals;
    map<ll, ll> valCount;
    psum.push_back(0);
    for (ll i=1; i<=n; i++) {
        char x; cin>>x;
        psum.push_back(psum[i-1] + (x-'0'));
        ll psumDiff = psum[i] - i;
        if(vals.find(psumDiff) != vals.end()) {
            valCount[psumDiff]++;
        } else {
            valCount[psumDiff] = 1;
            vals.insert(psumDiff);
        }
    }
    
    if(vals.find(0) != vals.end()) {
        valCount[0]++;
    } else {
        valCount[0] = 1;
    }
 
    ll count = 0;
    for (auto elem: vals) {
        valCount[elem]--;
        count += valCount[elem] + ((valCount[elem]) * (valCount[elem]-1))/2;
    }
    cout<<count<<endl;
}
 
int main(){
    ll t; cin>>t;
    while(t--){
        solve();
    }
}