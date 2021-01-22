#include <bits/stdc++.h>
using namespace std;
ifstream fin("highcard.in");
ofstream fout("highcard.out");

int n;
set<int> bessie;
set<int> elsie;

int main() {
  fin>>n;
  for(int i=1; i<=n; i++){
    int x;
    fin>>x;
    elsie.insert(x);
  }
  for(int i=1; i<=2*n; i++){
    if(elsie.count(i)==0) bessie.insert(i);
  }
  int counter = 0;
  for(set<int>::iterator it=elsie.begin(); it!=elsie.end(); ++it){
    int val = *it;
    if(bessie.upper_bound(val)!=bessie.end()&&*bessie.upper_bound(val)>val){
      counter++;
      elsie.erase(val);
      bessie.erase(*bessie.upper_bound(val));
    }
    else if(bessie.upper_bound(val)==bessie.end()){
      elsie.erase(val);
      bessie.erase(bessie.begin());
    }
  }
  fout<<counter;
}
