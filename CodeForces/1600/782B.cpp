#include <bits/stdc++.h>
using namespace std;
#define int long long
#define eps 0.0000001
using ld = double;

const int MXN = 1e5;
int n, x[MXN], v[MXN];

bool check(ld t){
  ld l = 0, r = 3e9;
  for(int i=0; i<n; i++){
    l = max(l, x[i] - v[i]*t);
    r = min(r, x[i] + v[i]*t);
  }
  return l+eps>=r;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  cin>>n;
  for(int i=0; i<n; i++) cin>> x[i];
  for(int i=0; i<n; i++) cin>>v[i];
  double lo=0, hi=1e9/2+1, ans=0;
  while(lo+eps<=hi){
    double t=(lo+hi)/2.0;
    if(check(t)) lo=t+eps, ans=t;
    else hi=t-eps;
  }
  cout << setprecision(10) << ans;
}
