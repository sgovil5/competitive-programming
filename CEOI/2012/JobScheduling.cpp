#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MXN = 1e5+5;

int N, D, M;
vector<pair<int,int>> jobs; // day, index
vector<int> ans[MXN];

bool check(int machines){
    // Filled[i] represents how many tasks are processed on day i
    vector<int> filled(MXN, 0);
    int currDay = 0;
    for(int i=0; i<M; i++){
        currDay = max(currDay, jobs[i].first);
        if(filled[currDay]>=machines) currDay++; 
        if(currDay>jobs[i].first+D) return false;
        filled[currDay]++;
    }
    return true;
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
    cin>>N>>D>>M;
    for(int i=0; i<M; i++){
        int x; cin>>x;
        jobs.push_back({x, i+1});
    }
    sort(jobs.begin(), jobs.end());

    int numMachines = firstTrue(0, MXN); 

    cout<<numMachines<<endl;
    
    int currDay = 0;
    for(int i=0; i<M; i++){
        currDay = max(currDay, jobs[i].first);
        if(ans[currDay].size()>=numMachines) currDay++;
        ans[currDay].push_back(jobs[i].second);
    }

    for(int i=1; i<=N; i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<0<<endl;
    }
    return 0;
}