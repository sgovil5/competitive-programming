#include <iostream>
#include <vector>
using namespace std;

void setIO(string fileName = "") {
	ios_base::sync_with_stdio(0); cin.tie(0);
	if((int)fileName.size()) {
		freopen((fileName+".in").c_str(), "r", stdin);
		freopen((fileName+".out").c_str(), "w", stdout);
	}
}

const int dx[4] = {1, 0 , -1, 0}, dy[4] = {0, 1, 0, -1};

int n,k, connected, state =1;
int grid[105][15];
bool vis[105][15];
vector<pair<int,int>> region;

void ff(int i, int j){
    if(i<=0 || i>n || j<=0 || j>10) return;
    vis[i][j] = true;
    region.push_back({i,j});
    connected++;

    for(int d=0; d<4; d++){
        int ii = i+dx[d], jj= j+dy[d];
        if(!vis[ii][jj] && grid[ii][jj]==grid[i][j]) ff(ii, jj);
    }
}

void gravity(int c) {
	vector<int> colors;
	for (int i=1; i<=n; i++) {
		if (grid[i][c] != 0) colors.push_back(grid[i][c]);
		grid[i][c] = 0;
	}
	for (int i=0; i<colors.size(); i++) {
		grid[n-colors.size()+1+i][c] = colors[i];
	}
}

int main(){
    setIO("mooyomooyo");
    cin>>n>>k;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=10; j++){
            char digit;
            cin>>digit;
            grid[i][j]= digit - '0';
        }
    }

    while(state!=0){
        state = 0;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=10; j++){
                if(!vis[i][j] && grid[i][j]!=0){
                    connected = 0;
                    ff(i, j);
                    if(connected>=k){
                        state++;
                        for(auto elem: region){
                            grid[elem.first][elem.second] = 0;
                        }
                    }
                    region.clear();
                }
            }
        }

        for(int i=1; i<=10; i++) gravity(i);
        for(int i=1; i<=n; i++){
            for(int j=1; j<=10; j++) vis[i][j] = false;
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=10; j++) cout<<grid[i][j];
        cout<<endl;
    }
}