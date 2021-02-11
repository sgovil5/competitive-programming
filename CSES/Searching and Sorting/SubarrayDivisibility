#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  ll n;
  cin>>n;
  ll prefix[n+1];
  prefix[0] = 0;
  // Calculate prefix
  for(ll i=1; i<=n; i++){
    ll x;
    cin>>x;
    prefix[i] = (prefix[i-1]+x)%n;
  }
  map<ll, ll> m; //val, count of val
  for(ll i=0; i<=n; i++) m[(prefix[i]+n)%n]++;
  // Calculate ans
  ll ans = 0;
  for(auto i: m){
    ans+=((i.second-1)*(i.second))/2;
  }
  cout<<ans;
}
