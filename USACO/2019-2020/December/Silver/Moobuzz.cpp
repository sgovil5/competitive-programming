#include <bits/stdc++.h>
using namespace std;
ifstream fin("moobuzz.in");
ofstream fout("moobuzz.out");

using ll = long long;

ll n;

bool check(ll num){
  ll place = (num/3) + (num/5) - (num/15);
  return ((num-place)>=n);
}

ll fstTrue(ll lo, ll hi) {
  for (hi ++; lo < hi; ) {
    ll mid = (lo+hi)/2;
    check(mid) ? hi = mid : lo = mid+1;
  }
  return lo;
}

int main(){
  fin>>n;
  ll hi = 1e18;
  fout<<fstTrue(1, hi);
}
