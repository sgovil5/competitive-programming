#include <bits/stdc++.h>
using namespace std;
ifstream fin("where.in");
ofstream fout("where.out");

struct PCL{
  int i1, j1, i2, j2;
};

const int MXN = 21;
int n;
string grid[MXN];
bool visited[MXN][MXN];
vector<PCL> locations;

const int xd[4] = {0,1,0,-1}, yd[4] = {1,0,-1,0};

void floodfill(int i, int j, char letter, int i1, int j1, int i2, int j2){
  if(i<i1||i>i2||j<j1||j>j2||visited[i][j]||letter!=grid[i][j]) return;
  visited[i][j] = true;
  // BRUH I forgot to do "i+" or "j+" in the floodfill and spent 3 hours debugging
  for(int k=0; k<4; k++) floodfill(i + xd[k], j + yd[k], letter, i1, j1, i2, j2);
}

bool checkPCL(int i1, int j1, int i2, int j2){
  int letters = 0;
  // Set visited in specific range to false
  for(int i=i1; i<=i2; i++){
    for(int j=j1; j<=j2; j++){
      visited[i][j] = false;
    }
  }
  int distinct[26]={0};
  // Check every value in the range
  for(int i=i1; i<=i2; i++){
    for(int j=j1; j<=j2; j++){
      if(!visited[i][j]){
        char c = grid[i][j];
        // If letter has not appeared before, increment count of letters
        if(distinct[c-'A']==0) letters++;
        //If we haven't visited before, it must mean that its a separate contiguous region
        distinct[c-'A']++;
        floodfill(i,j,c,i1, j1, i2, j2);
      }
    }
  }
  if(letters!=2) return false;
  bool one = false, many = false;
  // Loop through the array to see if there is one contiguous area of one letter and many contiguous area of the second letter
  for(int i=0; i<26; i++){
    if(distinct[i]==1) one = true;
    if(distinct[i]>1) many = true;
  }
  return one && many;
}

// Check if a PCL is inside another
bool insidePCL(int x, int y){
  return locations[x].i1 >= locations[y].i1 
    && locations[x].i2 <= locations[y].i2
    && locations[x].j1 >= locations[y].j1
    && locations[x].j2 <= locations[y].j2;
}

// Check if specific range doesn't contain any PCLs inside of it
bool PCL_maximal(int x)
{
  for (int i=0; i<locations.size(); i++)
    if (i!=x && insidePCL(x,i)) return false;
  return true;
}


int main(){
  fin>>n;
  for(int i=0; i<n; i++){
    fin>>grid[i];
  }
  // Check every location
  for(int i1=0; i1<n; i1++){
    for(int j1=0; j1<n; j1++){
      for(int i2=i1; i2<n; i2++){
        for(int j2=j1; j2<n; j2++){
          if(checkPCL(i1,j1,i2,j2)){
            locations.push_back({i1,j1,i2,j2});
          }
        }
      }
    }
  }
  int ans = 0;
  for(int i=0; i<locations.size(); i++){
    if(PCL_maximal(i)){
      ans++;
    }
  }
  fout<<ans;
}
