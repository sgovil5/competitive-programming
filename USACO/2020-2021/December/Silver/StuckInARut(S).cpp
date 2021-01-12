#include <bits/stdc++.h>
using namespace std;

struct Cow{
  int index;
  bool isStopped;
  int x,y;
};

bool sortByX(const Cow& x, const Cow& y) { return x.x < y.x; }
bool sortByY(const Cow&x, const Cow&y){ return x.y < y.y; }

int n;
vector<Cow> north;
vector<Cow> east;

int main() {
  cin>>n;
  for(int i=0; i<n; i++){
    char d;
    int x,y;
    cin>>d>>x>>y;
    if(d=='E') east.push_back({i,false,x,y});
    else north.push_back({i,false,x,y});
  }
  sort(begin(east), end(east), sortByY);
  sort(begin(north), end(north), sortByX);
  int stops[1001]={0};
  for(int i=0; i<north.size(); i++){
    for(int j=0; j<east.size(); j++){
      if(!north[i].isStopped&&!east[j].isStopped&&north[i].x>east[j].x&&east[j].y>north[i].y){
        if(north[i].x-east[j].x>east[j].y-north[i].y){
          stops[north[i].index]+=stops[east[j].index]+1;
          east[j].isStopped=true;
        }
        else if(north[i].x-east[j].x<east[j].y-north[i].y){
          stops[east[j].index]+=stops[north[i].index]+1;
          north[i].isStopped=true;
        }
      }
    }
  }
  for(int i=0; i<n; i++){
    cout<<stops[i]<<endl;
  }
}
