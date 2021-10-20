#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin("clocktree.in");
ofstream fout("clocktree.out");

// void setIO(string fileName = "") {
// 	ios_base::sync_with_stdio(0); cin.tie(0);
// 	if((int)fileName.size()) {
// 		freopen((fileName+".in").c_str(), "r", stdin);
// 		freopen((fileName+".out").c_str(), "w", stdout);
// 	}
// }

const int MX = 2505;

int n;
int t[MX], temp[MX];
vector<int> adj[MX];

int dfs(int curr, int parent){
    for(auto u: adj[curr]){
        if(u!=parent){
            temp[u]++;
            temp[curr] += 12-dfs(u,curr);
            temp[curr] = (temp[curr]-1)%12+1;
        }
    }
    temp[parent]++;
    return temp[curr];
}

int main(){
    fin>>n;
    for(int i=1; i<=n; i++) fin>>t[i];

    for(int i=1; i<n; i++){
        int a, b; fin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int ans = 0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++) temp[j] = t[j];

        dfs(i, -1);
        if(temp[i]==12 || temp[i]==1) ans++;
    }
    fout<<ans;
}