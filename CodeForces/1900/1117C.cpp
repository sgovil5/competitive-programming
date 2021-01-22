#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MXN = 1e5+2;
ll totx, toty, n;
string s;
//Prefix sums
ll px[MXN], py[MXN];

bool check(ll days){
  ll x = totx;
  ll y = toty;
  //Compute how much the wind is going to shave off from the distance we need to travel
  x-= (days/n) * px[n] + px[days%n];
  y-= (days/n) * py[n] + py[days%n];
  //return false if the distance left to travel after the computation of the wind
  // is more than the number of days we allotted
  //BRUH I FCKIN THOUGHT ABS(X+Y) = ABS(X)+ABS(Y). Welp there goes 3 hours down the drain
  // Codicon orz
  return abs(x) + abs(y) <=days;
}

//Binary search
ll fstTrue(ll lo, ll hi) {
    // returns hi+1 if no x satisfies f
    for (hi ++; lo < hi; ) {
        ll mid = (lo+hi)/2;
        check(mid) ? hi = mid : lo = mid+1;
    }
    return lo;
}

int main() {
  ll x1, y1, x2, y2;
  cin>>x1>>y1>>x2>>y2;
  totx = x2 - x1, toty = y2 - y1;
  cin>>n>>s;
  // Calculate prefix sums
  px[0] = 0, py[0] = 0;
  for(ll i=1; i<=n; i++){
    px[i] = px[i-1], py[i] = py[i-1];
    if(s[i-1]=='U') py[i]++;
    else if(s[i-1]=='D') py[i]--;
    else if(s[i-1]=='R') px[i]++;
    else if(s[i-1]=='L') px[i]--;
  }
  ll ans = fstTrue(1, 1e18);
  if(ans==1000000000000000001) cout<<-1;
  else cout<<ans;
}
