#include <iostream>
#include <vector>
using namespace std;

const int xd[4] = {1,0,-1,0};
const int yd[4] = {0,1,0,-1};

int t;
int n,m;
char arr[51][51];
bool vis[51][51];

void ff(int i, int j){
  // Check conditions
  if(i<0 || i>=n || j<0 || j>=m || vis[i][j] || arr[i][j] == '#') return;

  // Visit current location and try next ff on surroundings
  vis[i][j] = true;
  for(int k=0; k<4; k++) ff(i+xd[k], j+yd[k]);
}

int main() {
  cin>>t;
  while(t--){
    // Input
    cin>>n>>m;
    
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        cin>>arr[i][j];
      }
    }

    //Reset Visited
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        vis[i][j] = false;
      }
    }

    // Set final result variable
    bool possible = true;

    // Place Walls around B and ensure that no G is neighboring to B
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        if(arr[i][j]=='B'){
          for(int k=0; k<4; k++){
            if(i+xd[k]>=0 && i+xd[k]<n && j+yd[k]>=0 && j+yd[k]<m){
              if(arr[i+xd[k]][j+yd[k]]=='G') possible = false;
              if(arr[i+xd[k]][j+yd[k]]=='.') arr[i+xd[k]][j+yd[k]] = '#';
            }
          }
        }
      }
    }
    // Reset possible for some reason idk it somehow works don't ask me
    if(!possible) cout<<"No"<<endl;
    else{ 
      possible = true;
      // Floodfill from the last square and see if you can reach all Gs
      /*
        This is actually a really good idea since you can ensure that you 
        don't have to reset the visited array for each G and thus you won't
        exceed the time limit. Sad that I didn't think of this one, but I will
        keep in mind for future problems.
      */
      ff(n-1, m-1);
      for(int i = 0; i<n; i++){
        for(int j=0; j<m; j++){
          if(arr[i][j]=='G' && !vis[i][j]){
            possible = false;
            break;
          }
        }
      }
      // Output
      cout<<(possible ? "Yes" : "No")<<endl;
    }
  }
  // I'm confused as to how return 0 makes the grader give u a verdict faster lmao
  return 0;
}
