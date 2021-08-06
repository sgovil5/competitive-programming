#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

void setIO(string fileName = "") {
	ios_base::sync_with_stdio(0); cin.tie(0);
	if((int)fileName.size()) {
		freopen((fileName+".in").c_str(), "r", stdin);
		freopen((fileName+".out").c_str(), "w", stdout);
	}
}

#define f first
#define s second

int c, n;
multiset<int> chickens;
vector<pair<int,int>> cows;

bool cmp(pair<int, int>& a, pair<int, int>& b){
    return a.s<b.s;
}

int main(){
    setIO("helpcross");
    cin>>c>>n;
    for(int i=0; i<c; i++){
        int x; cin>>x;
        chickens.insert(x);
    }
    for(int i=0; i<n; i++){
        int a,b; cin>>a>>b;
        cows.push_back({a,b});
    }
    sort(begin(cows), end(cows), cmp);

    int ans = 0;
    for(int i=0; i<n; i++){
        int a=cows[i].f, b=cows[i].s;
        if(chickens.lower_bound(a)!=chickens.end() && *chickens.lower_bound(a)<=b){
            ans++;
            chickens.erase(chickens.lower_bound(a));
        }
    }

    cout<<ans;
}