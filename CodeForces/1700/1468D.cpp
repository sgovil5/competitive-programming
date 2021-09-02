#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int tc;
ll n, m, a, b;
ll catch_time, max_bombs;
vector<ll> bombs;

bool check(ll num){
    int total_time = 1;
    for(int i=num-1; i>=0; i--){
        if(total_time+bombs[i]>catch_time) return false;
        else total_time++;
    }
    return true;
}

ll lastTrue(ll lo, ll hi) {
	for (--lo; lo < hi; ) {
		ll mid = lo+(hi-lo+1)/2;
		if (check(mid)) lo = mid;
		else hi = mid-1;
	}
	return lo;
}

void solve(){
    cin>>n>>m>>a>>b;
    bombs.clear();
    for(int i=0; i<m; i++){
        int cracker; cin>>cracker;
        bombs.push_back(cracker);
    }
    sort(begin(bombs), end(bombs));
    
    max_bombs = min((ll) bombs.size(), abs(b-a)-1);

    if(a<b){
        catch_time=b-1;
    } else{
        catch_time=n-b;
    }

    cout<<lastTrue(0, max_bombs)<<endl;
}

int main(){
    cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}