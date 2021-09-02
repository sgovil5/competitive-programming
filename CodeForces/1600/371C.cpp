#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;
using ll = long long;

ll reqB=0, reqS=0, reqC=0;
ll amtB, amtS, amtC;
ll costB, costS, costC;
ll money;

bool check(ll x){
    ll totB = max((ll) 0, (x*reqB)-amtB);
    ll totS = max((ll) 0, (x*reqS)-amtS);
    ll totC = max((ll) 0, (x*reqC)-amtC);
    ll tot = totB*costB+totS*costS+totC*costC;
    return tot<=money;
}

ll lastTrue(ll lo, ll hi) {
	for (--lo; lo < hi; ) {
		ll mid = lo+(hi-lo+1)/2;
		if (check(mid)) lo = mid;
		else hi = mid-1;
	}
	return lo;
}

int main(){
    string s; cin>>s;
    for(int i=0; i<s.length(); i++){
        if(s[i]=='B') reqB++;
        if(s[i]=='S') reqS++;
        if(s[i]=='C') reqC++;
    }
    cin>>amtB>>amtS>>amtC;
    cin>>costB>>costS>>costC;
    cin>>money;

    cout<<lastTrue(0, 2e12);
    return 0;
}
