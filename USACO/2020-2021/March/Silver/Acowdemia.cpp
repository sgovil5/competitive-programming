#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long n; long long k, l;
vector<int> v;

bool check(long long h){
    if(v[n-h]+k<h) return false;

    long long sum = 0;
    for(int i=n-h; i<n; i++){
        sum+=max(0LL, h-v[i]);
    }
    return sum<=k*l;
}

long long lastTrue(long long lo, long long hi) {
	for (--lo; lo < hi; ) {
		long long mid = lo+(hi-lo+1)/2;
		if (check(mid)) lo = mid;
		else hi = mid-1;
	}
	return lo;
}

int main(){
    cin>>n>>k>>l;
    for(int i=0; i<n; i++){
        long long x; cin>>x;
        v.push_back(x);
    }
    sort(begin(v), end(v));

    cout<<lastTrue(0, n+1);

}   