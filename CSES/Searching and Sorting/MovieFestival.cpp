#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int n;
vector<pair<int,int>> v; //end, start

int main(){
  cin>>n;
  for(int i=0; i<n; i++){
    int a,b;
    cin>>a>>b;
    v.push_back({b,a});
  }
  sort(begin(v), end(v));
  int count = 1;
  int maxEnd = v[0].f;
  for(int i=1; i<n; i++){
    if(v[i].s>=maxEnd){
      count++;
      maxEnd = v[i].f;
    }
  }
  cout<<count<<endl;
}
