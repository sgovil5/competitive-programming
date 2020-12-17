#include <bits/stdc++.h>
using namespace std;
ifstream fin("outofplace.in");
ofstream fout("outofplace.out");

int main(){
  int n;
  vector<int> v, s;
  fin>>n;
  for(int i=0; i<n; i++){
    int x;
    fin>>x;
    v.push_back(x), s.push_back(x);
  }
  sort(begin(s), end(s));
  int ctr = 0;
  for(int i=0; i<n; i++){
    if(s[i]!=v[i]) ctr++;
  }
  fout<<ctr-1;
}
