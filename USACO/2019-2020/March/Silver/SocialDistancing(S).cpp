#include <bits/stdc++.h>
using namespace std;
ifstream fin("socdist.in");
ofstream fout("socdist.out");

using ll = long long;

ll n,m;
vector<pair<ll,ll>> ranges;

bool check(ll d){
  ll currCow = ranges[0].first;
  ll cowsPlaced = 1;
  // Go through every range
  for(int i=0; i<m; i++){
    // Check if new cow will fit given distance in current range
    while(ranges[i].first<=currCow+d && currCow+d<=ranges[i].second){
      cowsPlaced++;
      currCow+=d;
    }
    // Move to the next range
    if(ranges[i+1].first>=currCow+d){
      currCow = ranges[i+1].first;
      cowsPlaced++;
    }
  }
  return cowsPlaced>=n;
}

ll lstTrue(ll lo, ll hi) {
  for (lo --; lo < hi; ) {
    ll mid = (lo+hi+1)/2;
    check(mid) ? lo = mid : hi = mid-1;
  }
  return lo;
}

int main(){
  fin>>n>>m;
  for(int i=0; i<m; i++){
    ll a,b;
    fin>>a>>b;
    ranges.push_back({a,b});
  }
  sort(begin(ranges), end(ranges));
  fout<<lstTrue(1, 1e18);
}
