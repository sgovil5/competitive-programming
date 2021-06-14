#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, l;
vector<int> stations;

bool check(int dist){
    int used = 0, maxConsidered = 0;
    
    cout<<dist<<endl;

    for(int i=0; i<n; i++){
        if(maxConsidered<stations[i]){
            used+=stations[i]-max(maxConsidered, stations[i]-dist);
        }
        if(maxConsidered<l){
            used+=min(l, stations[i]+dist);
            maxConsidered = max(maxConsidered, min(stations[i]+dist, l));
        }
        cout<<i<<" "<<stations[i]<<" "<<maxConsidered<<" "<<used<<endl;
    }
    cout<<"\n";
    return used>=m;
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
    cin>>n>>m>>l;
    for(int i=0; i<n; i++){
        int x; cin>>x; x--;
        stations.push_back(x);
    }
    sort(begin(stations), end(stations));
    int ans = firstTrue(0, 10);
    cout<<ans;
}