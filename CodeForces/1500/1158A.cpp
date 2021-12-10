#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  ll n,m;
  ll sumB = 0, sumG = 0;
  vector<ll> b,g;
  cin>>n>>m;
  for(ll i=0; i<n; i++){
    ll x; cin>>x;
    sumB+=x;
    b.push_back(x);
  }
  for(ll j=0; j<m; j++){
    ll x; cin>>x;
    sumG+=x;
    g.push_back(x);
  }
  sort(begin(b), end(b)), sort(begin(g), end(g));

  if(b[n-1]>g[0]) cout<<-1<<endl;
  else if(b[n-1]==g[0]){
    ll ans = sumG + (m * (sumB-b[n-1]));
    cout<<ans;
  }
  else if(b[n-1]<=g[0]){
    ll ans = b[n-1] + sumG + (b[n-2]*(m-1)) + ((sumB-b[n-1]-b[n-2]) * m);
    cout<<ans;
  }
  
  return 0;
} 
