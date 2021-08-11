#include <bits/stdc++.h>
using namespace std;
ifstream fin("mountains.in");
ofstream fout("mountains.out");

#define int long long

struct Mountain{
  // left and right x coordinates of the base at y = 0
  int left, right;
};

bool cmp(const Mountain& a, const Mountain& b){
  if(a.left==b.left) return a.right>b.right;
  return a.left<b.left;
}

int n;
vector<Mountain> v;

signed main(){
  // Input
  fin>>n;
  for(int i=0; i<n; i++){
    int x,y;
    fin>>x>>y;
    // Convert to look at bases instead of peaks
    v.push_back({ x-y, x+y});
  }
  sort(begin(v), end(v), cmp);
  // Two Pointers
  int seen=0;
  int l = 0, r = 0;
  for(l=0; l<n; l++){
    while(v[l].right>=v[r].right && r<n){
      r++;
    }
    if(v[l].right<v[r].right){
      seen++;
      l = r;
      l--;
    }
  }
  fout<<seen+1;
}
