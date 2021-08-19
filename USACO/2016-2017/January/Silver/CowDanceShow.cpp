#include <iostream>
#include <vector>
#include <set>
using namespace std;

void setIO(string fileName = "") {
	ios_base::sync_with_stdio(0); cin.tie(0);
	if((int)fileName.size()) {
		freopen((fileName+".in").c_str(), "r", stdin);
		freopen((fileName+".out").c_str(), "w", stdout);
	}
}

int n, tmax;
vector<int> cows;

bool check(int k){
    multiset<int> m;
    int time = 0, currCow = k;
    for(int i=0; i<k; i++) m.insert(cows[i]);

    while(currCow<n){
        time = *m.begin();
        m.erase(m.begin());
        m.insert(cows[currCow]+time);
        currCow++;
    }

    return *--m.end()<=tmax;
}

int firstTrue(int lo, int hi) {
	for (hi ++; lo < hi; ) {
		int mid = lo+(hi-lo)/2;
		if (check(mid)) hi = mid;
		else lo = mid+1;
	}
	return lo;
}

int main(){
    setIO("cowdance");
    cin>>n>>tmax;
    for(int i=0; i<n; i++){
        int d; cin>>d;
        cows.push_back(d);
    }

    int ans = firstTrue(1, n);
    cout<<ans;
}