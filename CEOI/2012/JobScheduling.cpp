#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define f first
#define s second

const int MX = 1e5+5;

int n, d, m;
vector<pair<int,int>> v;

bool check(int machines){
    int currDay = v[0].f;
    vector<int> filled(MX, 0);

    for(int i=0; i<m; i++){
        currDay = max(currDay, v[i].f);
        if(filled[currDay]>=machines) currDay++;
        if(currDay-d>v[i].f) return false;
        filled[currDay]++;
    }

    return true;
}

int firstTrue(int lo, int hi) {
	hi++;
	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		if (check(mid)) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	return lo;
}

int main(){
    cin>>n>>d>>m;
    for(int i=0; i<m; i++){
        int x; cin>>x;
        v.push_back({x, i});
    }
    sort(begin(v), end(v));

    int req = firstTrue(1, MX);

    cout<<req<<endl;

    vector<int> ans[MX];

    int currDay = 0;
    for(int i=0; i<m; i++){
        currDay = max(currDay, v[i].f);
        int sz = ans[currDay].size();
        if(sz>=req){
            currDay++;
        }
        ans[currDay].push_back(v[i].s);
    }

    for(int i=1; i<=n; i++){
        for(int val: ans[i]){
            cout<<val+1<<" ";
        }
        cout<<0<<endl;
    }
}