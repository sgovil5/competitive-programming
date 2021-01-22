#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m;
  cin>>n>>m;
  vector<int> cities;
  for(int i=0; i<n; i++){
    int x;
    cin>>x;
    cities.push_back(x);
  }
  sort(cities.begin(), cities.end());
  set<int> towers;
  for(int i=0; i<m; i++){
    int x;
    cin>>x;
    towers.insert(x);
  }
  int minR = 0;
  for(int i=0; i<n; i++){
    auto it = towers.lower_bound(cities[i]);
    int r;
    if(cities[i]<*towers.begin()){
      r = abs(*towers.begin()-cities[i]);
    }
    else if(it==towers.end()){
      r = abs(cities[i]-*towers.rbegin());
    }
    else{
      r = min(abs(cities[i]-*it),abs(cities[i]-*prev(it)));
    }
    minR = max(r, minR);
  }
  cout<<minR;
}
