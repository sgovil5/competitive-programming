#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int n, x;
vector<pair<int,int>> a; //val, pos

int main() {
  cin>>n>>x;
  for(int i=0; i<n; i++){
    int ai; cin>>ai;
    a.push_back({ai, i});
  }
  sort(begin(a), end(a));

  bool possible = false;
  tuple<int,int,int> ans;

  for(int i=0; i<n; i++){
    if(possible) break;
    int left = 0, right = n-1;
    while(left!=right){
      int tempSum = a[left].f+a[right].f+a[i].f;
      if(left!=i && right!=i && tempSum==x){
        possible = true;
        ans = {a[left].s, a[right].s, a[i].s};
        break;
      }
      else if(tempSum<x){
        left++;
      }
      else right--;
    }
  }

  if(possible){
    cout<<get<0>(ans)+1<<" ";
    cout<<get<1>(ans)+1<<" ";
    cout<<get<2>(ans)+1<<endl;
  } else{
    cout<<"IMPOSSIBLE";
  }
} 
