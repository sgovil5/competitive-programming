#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ll n,q;
  cin>>n>>q;
  ll arr[n];
  for(ll i=0; i<n; i++){
    cin>>arr[i];
  }
  ll prefix[n+1];
  prefix[0] = 0;
  for(ll i=1; i<=n; i++){
    prefix[i] = prefix[i-1]+arr[i-1];
  }
  while(q--){
    ll l,r;
    cin>>l>>r;
    l++, r++;
    cout<<prefix[r-1]-prefix[l-1]<<endl;
  }
}
