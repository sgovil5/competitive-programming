#include <bits/stdc++.h>
using namespace std;
ifstream fin("haybales.in");
ofstream fout("haybales.out");

int main(){
  int n,q;
  fin>>n>>q;
  vector<int> pos;
  for(int i=0; i<n; i++){
    int x;
    fin>>x;
    pos.push_back(x);
  }
  sort(pos.begin(), pos.end());
  for(int i=0; i<q; i++){
    int a,b;
    fin>>a>>b;
    fout<<upper_bound(pos.begin(), pos.end(), b)-lower_bound(pos.begin(), pos.end(), a)<<endl;
  }
}
