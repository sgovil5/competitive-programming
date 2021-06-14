#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    int n,m; cin>>n>>m;
    vector<string> grid(n); 
    for(string& row: grid) cin>>row;

    auto valid = [&](int i, int j){
        return 0<=i && i<n && 0<=j && j<m && grid[i][j] == 'C';
    };

    set<vector<pair<int,int>>> pairs;
    int ans = 0;

    for(int i =0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] == 'G'){
                vector<pair<int,int>> v;
                int dx[]{1,0,-1,0};
			    int dy[]{0,1,0,-1};

                for(int d=0; d<4; d++){
                    int ii = i+dx[d], jj = j+dy[d];
                    if(valid(ii,jj)) v.push_back({ii,jj});
                }

                if(v.size()>2){
                    ans++;
                    continue;
                }
                if(v.size()==2){
                    sort(begin(v), end(v));
                    pairs.insert(v);
                }
            }
        }
    }
    cout<<pairs.size()+ans<<endl;
}