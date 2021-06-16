#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define l first
#define r second

void setIO(string fileName = "") {
	ios_base::sync_with_stdio(0); cin.tie(0);
	if((int)fileName.size()) {
		freopen((fileName+".in").c_str(), "r", stdin);
		freopen((fileName+".out").c_str(), "w", stdout);
	}
}

int n;
vector<pair<int,int>> v;

int main(){
    setIO("lifeguards");
    cin>>n;
    for(int i=0; i<n; i++){
        int a,b; cin>>a>>b;
        v.push_back({a,b});
    }
    sort(begin(v), end(v));

    int tot = 0;
    int left = v[0].l, right = v[0].r;
    for(int i=0; i<n; i++){
        tot+=max(0,right - left);
        left = max(v[i+1].l, right);
        right = max(v[i+1].r, right);
    }

    int minAlone = tot;
    v.push_back({v[n-1].r, v[n-1].r});
    left = 0, right = 0;
    for(int i=0; i<n; i++){
        left = max(v[i].l, right);
        right = max(v[i].r, right);
        int currAlone = min(v[i+1].l-left, right - left);
        minAlone = min(currAlone, minAlone);
    }
    cout<<tot-max(minAlone, 0);
}