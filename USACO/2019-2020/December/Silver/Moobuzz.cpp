#include <iostream>
using namespace std;
using ll = long long;

int n;

void setIO(string fileName = "") {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	if((int)fileName.size()) {
		freopen((fileName+".in").c_str(), "r", stdin);
		freopen((fileName+".out").c_str(), "w", stdout);
	}
}

bool check(ll c){
  ll numMoo = 0;
  numMoo+=(c-1)/3;
  numMoo+=(c-1)/5;
  numMoo-=(c-1)/15;
  return c-numMoo<=n;
}

int lastTrue(ll lo, ll hi) {
	for (--lo; lo < hi; ) {
		ll mid = lo+(hi-lo+1)/2;
		if (check(mid)) lo = mid;
		else hi = mid-1;
	}
	return lo;
}


int main(){
  setIO("moobuzz");
  cin>>n;
  ll ans = lastTrue(1, 2e9);
  cout<<ans<<endl;
}