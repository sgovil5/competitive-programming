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

int c,n;
vector<pair<int,int>> cows;
multiset<int> chickens;

int main(){
    setIO("helpcross");
    cin>>c>>n;
    for(int i=0; i<c; i++){
        int x; cin>>x;
        chickens.insert(x);
    }
    for(int i=0; i<n; i++){
        int a,b; cin>>a>>b;
        cows.push_back({b,a});
    }
    sort(begin(cows), end(cows));

    int count = 0;
    for(int i=0; i<n; i++){
        auto it = chickens.lower_bound(cows[i].s);
        if(it!=chickens.end() &&*it<=cows[i].f){
            count++;
            chickens.erase(it);
        }
    }
    cout<<count<<endl;
}