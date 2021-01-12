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
  // Sorting like this ensures that when we visit a cow, the number of cows it has stopped has been already calculated
  int stops[1001]={0};
  // Loop at every pair of cows
  for(int i=0; i<north.size(); i++){
    for(int j=0; j<east.size(); j++){
      // Check that the cows haven't been stopped before and make sure that the pairs can intersect
      if(!north[i].isStopped&&!east[j].isStopped&&north[i].x>east[j].x&&east[j].y>north[i].y){
        // In this case the north cow stops the east cow
        if(north[i].x-east[j].x>east[j].y-north[i].y){
          stops[north[i].index]+=stops[east[j].index]+1;
          east[j].isStopped=true;
        }
        // The opposite as above
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
