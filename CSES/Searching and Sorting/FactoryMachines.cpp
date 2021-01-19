#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n,t;
ll arr[200001];
 
bool works(ll time){
  ll sum=0;
  bool ans = false;
  for(ll i=0; i<n; i++){
    sum = min(sum + (time/arr[i]), t);
  }
  if(sum>=t) ans = true;
  return ans;
}
 
ll fstTrue(ll lo, ll hi){
  for (hi ++; lo < hi; ) {
    ll mid = (lo+hi)/2;
    works(mid) ? hi = mid : lo = mid+1;
  }
  return lo;
}
 
int main() {
  cin>>n>>t;
  for(ll i=0; i<n; i++){
    cin>>arr[i];
  }
  sort(arr,arr+n);
  cout<<fstTrue(0,1000000000000000000);
  return 0;
}
