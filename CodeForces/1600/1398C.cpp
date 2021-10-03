#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

void solve(){
    int n; string s; cin>>n>>s;
    vector<int> prefix(n+1, 0);
    for(int i=1; i<=n; i++) prefix[i] = s[i-1]-'0';

    for(int i=1; i<=n; i++) prefix[i]+=prefix[i-1];

    map<int, ll> m;
    for(int i=0; i<=n; i++) m[prefix[i]-i]++;

    ll ans = 0;
    for(auto elem: m){
        if(elem.second>0) ans+=((elem.second)*(elem.second-1))/2;
    }
    cout<<ans<<endl;
}

int main(){
    int tc; cin>>tc;
    while(tc--) solve();
    return 0;
}