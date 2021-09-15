#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Cow{
  int index, x, y;
};

bool sortEast(const Cow& a, const Cow& b){
  return a.y<b.y;
}

bool sortNorth(const Cow&a, const Cow&b){
  return a.x<b.x;
}

int s;
vector<Cow> east, north;

vector<int> adj[1005];
bool stopped[1005]={false}, vis[1005]={false};
int children[1005] = {0};

void dfs(int node){
  vis[node] = true;

  for(auto u: adj[node]){
    children[node]++;
    if(!vis[u]) dfs(u);
    children[node]+=children[u];
  }
}

int main(){
  cin>>s;
  for(int i=0; i<s; i++){
    char c; int x, y;
    cin>>c>>x>>y;
    if(c=='E') east.push_back({i, x, y});
    else north.push_back({i, x, y});
  }

  sort(begin(east), end(east), sortEast);
  sort(begin(north), end(north), sortNorth);

  for(auto e: east){
    for(auto n: north){
      int timeE = n.x-e.x, timeN = e.y-n.y;
      if(timeE>0 && timeN>0 && !stopped[e.index] && !stopped[n.index]){ //check if greater than or equal to
        if(timeE > timeN){
          stopped[e.index]=true;
          adj[n.index].push_back(e.index);
        }
        else if(timeN > timeE){
          stopped[n.index]=true;
          adj[e.index].push_back(n.index);
        }
      }
    }
  }

  for(int i=0; i<s; i++){
    if(!vis[i]) dfs(i);
  }

  for(int i=0; i<s; i++) cout<<children[i]<<endl;
}