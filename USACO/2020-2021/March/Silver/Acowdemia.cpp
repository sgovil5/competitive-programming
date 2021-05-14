#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

using ll = long long;

int n,k,l;
vector<int> c;

bool ok(int h){
    // If the h'th paper from the right(backwards) can't reach h no matter what then we're screwed anyway 😞
    if(c[n-h]+k<h) return false;
    // Calculate the sum of all the new required journals to make sure that papers can reach h  🥴
    ll sum = 0;
    for(int i=n-1; i>=n-h; i--){
        // If current citations are already greater than h then we don't need to consider them 😕
        if(c[i]<h) sum+=(h-c[i]);
    }
    // I LOVE getting CUCKED by Long Longs 🙃
    return sum<=(ll)k*l;
}

int bSearch(int lo, int hi) {
	while(lo + 1 < hi){
        int mid = (lo+hi)/2;
        if(ok(mid)) lo = mid;
        else hi = mid;
    }
    return lo;
}

int main(){
    cin>>n>>k>>l;
    for(int i=0; i<n; i++){
        int x; cin>>x;
        c.push_back(x);
    }
    sort(begin(c), end(c));

    // Binary Search 🤪
    int ans = bSearch(0, n+1);
    cout<<ans;
}