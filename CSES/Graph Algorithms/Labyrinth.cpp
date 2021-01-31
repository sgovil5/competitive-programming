// Interestingly, we have to "invert" x and y because coordinates are techincally (y,x)
#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
typedef pair<int,int> pii;

int n,m;
const int MX = 1002;
bool vis[MX][MX];
char parent[MX][MX];
string grid[MX];
queue<pii> q;
pii b;

// Check if point in grid is a valid location to move to
bool validLocation(int x, int y){
  return (x>=0 && x<n && y>=0 && y<m && grid[x][y]!='#');
}

int main() {
  // Input
  cin>>n>>m;
  for(int i=0; i<n; i++) cin>>grid[i];
  // Find A and push to queue
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(grid[i][j]=='A') q.push({i,j});
      if(grid[i][j]=='B') b={i,j};
    }
  }
  // Set up BFS
  vis[q.front().f][q.front().s] = true;
  parent[q.front().f][q.front().s] = 'Z';
  //Start BFS
  while(!q.empty()){
    pii curr = q.front();
    q.pop();
    //Check up
    if(validLocation(curr.f-1, curr.s) && !vis[curr.f-1][curr.s]){
      vis[curr.f-1][curr.s] = true;
      parent[curr.f-1][curr.s] = 'U';
      q.push({curr.f-1, curr.s});
    }
    // Check down
    if(validLocation(curr.f+1, curr.s) && !vis[curr.f+1][curr.s]){
      vis[curr.f+1][curr.s] = true;
      parent[curr.f+1][curr.s] = 'D';
      q.push({curr.f+1, curr.s});
    }
    // Check left
    if(validLocation(curr.f, curr.s-1) && !vis[curr.f][curr.s-1]){
      vis[curr.f][curr.s-1] = true;
      parent[curr.f][curr.s-1] = 'L';
      q.push({curr.f, curr.s-1});
    }
    // Check right
    if(validLocation(curr.f, curr.s+1) && !vis[curr.f][curr.s+1]){
      vis[curr.f][curr.s+1] = true;
      parent[curr.f][curr.s+1] = 'R';
      q.push({curr.f, curr.s+1});
    }
  }
  if(!vis[b.f][b.s]) cout<<"NO";
  else{
    cout<<"YES"<<endl;
    // Set up dist calculation
    int dist = 0;
    vector<char> path;
    pii curPos = b;
    char currPar = parent[curPos.f][curPos.s];
    // Calculate dist and trace path
    while(currPar!='Z'){
      path.push_back(currPar);
      if(currPar=='D') curPos = {curPos.f-1, curPos.s};
      else if(currPar=='U') curPos = {curPos.f+1, curPos.s};
      else if(currPar=='L') curPos = {curPos.f, curPos.s+1};
      else if(currPar=='R') curPos = {curPos.f, curPos.s-1};
      currPar = parent[curPos.f][curPos.s];
      dist++;
    }
    // Output
    cout<<dist<<endl;
    for(int i=dist-1; i>=0; i--){
      cout<<path[i];
    }
  }
}
