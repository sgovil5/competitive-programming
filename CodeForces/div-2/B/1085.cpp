#include <bits/stdc++.h>
using namespace std;
//BRUH THIS WAS A VERY MISLABELED PROBLEM
int main() {
  int n,k;
  cin>>n>>k;
  vector<int> p;
  for(int i=1; i<k; i++){
    if(n%i==0) p.push_back(i);
  }
  int x=1e9;
  for(auto i: p){
    x = min(x, ((k*n)/i)+i);
  }
  cout<<x;
}
