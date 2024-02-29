#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin>>n;

    vector<string> grid(2);
    cin>>grid[0]>>grid[1];
    
    set<string> possible_paths;
    map<string, int> path_count;

    string s = grid[0] + grid[1][n-1];
    possible_paths.insert(s);
    path_count[s]++;

    for (int i=1; i<n; i++) {
        s[n-i] = grid[1][n-i-1];
        path_count[s]++;
        if(grid[1][n-i-1] == '0') {
            possible_paths.insert(s);
        }
    }

    string smallest_path = *possible_paths.begin();
    int count = path_count[smallest_path];

    cout<<smallest_path<<endl;
    cout<<count<<endl;
}


int main() {
    int t; cin>>t;
    while(t--) {
        solve();
    }
}