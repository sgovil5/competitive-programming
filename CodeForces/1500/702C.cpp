#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main(){
  ll n, m; cin>>n>>m;
  vector<ll> cities(n), towers(m);
  for(ll i=0; i<n; i++) cin>>cities[i];
  for(ll i=0; i<m; i++) cin>>towers[i];
  towers.push_back(1e18);
  sort(begin(towers), end(towers)); sort(begin(cities), end(cities));

  ll r = 0;

  ll tIndex = 0, cIndex=0;

  for(;cIndex<n; cIndex++){
    while(tIndex<m){
      if(abs(towers[tIndex]-cities[cIndex]) >= abs(towers[tIndex+1]-cities[cIndex]) && tIndex < m){
        tIndex++;
      } else break;
    }
    r = max(abs(towers[tIndex]-cities[cIndex]), r);
  }
  cout<<r;
  return 0;
}