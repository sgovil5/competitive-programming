#include <bits/stdc++.h>
using namespace std;

struct Cow{
  char dir;
  int startx, starty;
  int posx ,posy ;
  bool done ;
};

int n;
vector<Cow> v;

int main() {
  bool grid[350][350];
  for(int i=0; i<350; i++){
    for(int j=0; j<350; j++){
      grid[i][j] = false;
    }
  }
  int timevisited[350][350];
  for(int i=0; i<350; i++){
    for(int j=0; j<350; j++){
      timevisited[i][j] = 0;
    }
  }
  cin>>n;
  for(int i =0; i<n; i++){
    char c;
    int x,y;
    cin>>c>>x>>y;
    v.push_back({c,x,y,x,y,false});
  }
  for(int i=1; i<=101; i++){
    for(int j=0; j<n; j++){
      if(v[j].done==false && v[j].dir=='E'){
        v[j].posx++;
        if(grid[v[j].posx][v[j].posy]==true&&timevisited[v[j].posx][v[j].posy]>0){
          v[j].done = true;
        }
        grid[v[j].posx][v[j].posy] = true;
      }
      else if(v[j].done==false && v[j].dir=='N'){
        v[j].posy++;
        if(grid[v[j].posx][v[j].posy]==true&&timevisited[v[j].posx][v[j].posy]>0){
          v[j].done = true;
        }
        grid[v[j].posx][v[j].posy] = true;
      }
    }
    for(int j=0; j<350; j++){
      for(int k=0; k<350; k++){
        if(grid[j][k]==true){
          timevisited[j][k]++;
        }
      }
    }
  }
  for(int i=0; i<n; i++){
    if(v[i].dir=='E'){
      if(v[i].posx>100) cout<<"Infinity"<<endl;
      else cout<<v[i].posx - v[i].startx<<endl;
    }
    else{
      if(v[i].posy>100) cout<<"Infinity"<<endl;
      else cout<<v[i].posy-v[i].starty<<endl;
    }
  }
}
