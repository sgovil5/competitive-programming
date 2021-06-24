#include <iostream>
using namespace std;

const int MX = 505;
const int xd[4] = {1,0,-1,0}, yd[4] = {0,1,0,-1};
int m, n;
int grid[MX][MX];
bool waypoint[MX][MX], vis[MX][MX];

void setIO(string fileName = "") {
	ios_base::sync_with_stdio(0); cin.tie(0);
	if((int)fileName.size()) {
		freopen((fileName+".in").c_str(), "r", stdin);
		freopen((fileName+".out").c_str(), "w", stdout);
	}
}

void ff(int i , int j, int minD){
    if(i<0 || i>=m || j<0 || j>=n || vis[i][j]) return;
    vis[i][j] = true;

    for(int d=0; d<4; d++){
        int ii = i+xd[d], jj = j+yd[d];
        if(!vis[ii][jj] && abs(grid[i][j] - grid[ii][jj])<=minD) ff(ii, jj, minD); 
    }
}

bool check(int minD){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++) vis[i][j] = false;
    }

    // Find location of waypoint to start ff
    int iWay, jWay;
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            if(waypoint[i][j]) iWay = i, jWay = j;
        }
    }

    bool possible = true;
    ff(iWay, jWay, minD);
    for(int i=0; i<m; i++){
        for(int j = 0; j<n; j++){
            if(waypoint[i][j] && !vis[i][j]) possible = false;
        }
    }

    return possible;
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
    setIO("ccski");
    cin>>m>>n;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++) cin>>grid[i][j];
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            int x; cin>>x;
            if(x==1) waypoint[i][j] = true;
            else waypoint[i][j] = false;
        }
    }

    int ans = firstTrue(0, 1e9+5);
    cout<<ans<<endl;
}