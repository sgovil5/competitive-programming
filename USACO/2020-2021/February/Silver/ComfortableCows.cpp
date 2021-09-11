#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define f first
#define s second

const int MX = 3000;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0 , -1};

bool exists[MX][MX];

int n;

bool isComfy(int x, int y){
  int num = 0;
  for(int k=0; k<4; k++) if(exists[x+dx[k]][y+dy[k]]) num++;
  return num==3;
}

int main(){
  cin>>n;
  
  for(int i=0; i<MX; i++) for(int j=0; j<MX; j++) exists[i][j] = false;

  int required = 0;
  for(int i=1; i<=n; i++){
    int x, y; cin>>x>>y; x+=500, y+=500;

    queue<pair<int, int>> q;
    q.push({x,y});

    while(!q.empty()){
      pair<int, int> p = q.front(); q.pop();

      if(!exists[p.f][p.s]){
        required++; exists[p.f][p.s]= true;
        if(isComfy(p.f, p.s)){
          for(int k=0; k<4; k++){
            if(!exists[p.f+dx[k]][p.s+dy[k]]){
              q.push({p.f+dx[k], p.s+dy[k]});
            }
          }
        }

        for(int k=0; k<4; k++){
          int xx=p.f+dx[k], yy=p.s+dy[k];
          if(exists[xx][yy]){
            if(isComfy(xx, yy)){
              for(int l=0; l<4; l++){
                if(!exists[xx+dx[l]][yy+dy[l]]){
                  q.push({xx+dx[l], yy+dy[l]});
                }
              }
            }
          }
        }
      }
    }
    cout<<required-i<<endl;
  }
}