#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll n,k;
vector<ll> v;

bool check(ll sum){
  ll rangesUsed = 1;
  ll currSum = 0;
  /*
  Loop through every value in array
  Check if it fits in current range
  if not, increment rangesUsed and start new one
  */
  for(int i=0; i<n; i++){
    if(currSum+v[i]<=sum){
      currSum+=v[i];
    }
    else{
      rangesUsed++;
      currSum = v[i];
    }
  }
  return rangesUsed<=k;
}

ll fstTrue(ll lo, ll hi) {
    for (hi ++; lo < hi; ) {
        ll mid = (lo+hi)/2;
        check(mid) ? hi = mid : lo = mid+1;
    }
    return lo;
}

int main() {
  cin>>n>>k;
  for(ll i=0; i<n; i++){
    int x;
    cin>>x;
    v.push_back(x);
  }
  ll maxNum = 0;
  for(int i=0; i<n; i++){
    maxNum = max(maxNum, v[i]);
  }
  cout<<fstTrue(maxNum, 1e18);
}
