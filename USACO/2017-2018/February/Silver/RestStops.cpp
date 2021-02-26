#include <bits/stdc++.h>
using namespace std;
ifstream fin("reststops.in");
ofstream fout("reststops.out");

using ll = long long;

int main() {
  //Input
  ll l, n, rf, rb;
  fin>>l>>n>>rf>>rb;

  //Create stops and sort
  vector<pair<ll,ll>> stops;
  for(int i=0; i<n; i++){
    ll x,c;
    fin>>x>>c;
    stops.push_back({x,c});
  }
  sort(begin(stops), end(stops));
  
  // Calculate max utility for stops from right to left
  ll maxStops[n];
  maxStops[n-1] = n-1;
  for(ll i=n-2; i>=0; --i){
    if(stops[i].second > stops[maxStops[i+1]].second){
      maxStops[i] = i;
    }
    else maxStops[i] = maxStops[i+1];
  }

  ll bessieRestTime = 0;
  ll utility = 0;
  for(ll i=0; i<n; i++){
    if(i==maxStops[i]){
      ll bessieArrive = ((stops[i].first) * rb) + bessieRestTime;
      ll farmerArrive = ((stops[i].first) * rf);
      ll disparity = farmerArrive - bessieArrive;
      utility+=(stops[i].second * disparity);
      bessieRestTime+=disparity;
    }
  }

  fout<<utility;
}
