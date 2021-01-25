#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll binpow(ll a, ll b, ll mod){
  a%=mod;
  ll res = 1;
  while(b>0){
    if(b%2==1) res = res* a % mod;
    a = a * a%mod;
    b/=2;
  }
  return res;
}

int main() {
  ll n;
  cin>>n;
  for(int i=0; i<n; i++){
    ll a,b;
    cin>>a>>b;
    cout<<binpow(a,b,1e9+7)<<endl;
  }
}
