#include <iostream>
#include <algorithm>
#define int long long
using namespace std;

int n;

bool check(int c){
    int leqC = 0;
    for(int i=1; i<=n; i++){
        leqC+=min(n, c/i);
    }

    return leqC>=((n*n)+1)/2;
}

int firstTrue(int lo, int hi) {
	for (hi ++; lo < hi; ) {
		int mid = lo+(hi-lo)/2;
		if (check(mid)) hi = mid;
		else lo = mid+1;
	}
	return lo;
}

signed main(){
    cin>>n;
    int ans = firstTrue(1, n*n);
    cout<<ans;
}