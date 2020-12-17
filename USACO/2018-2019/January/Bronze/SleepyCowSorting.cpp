#include <bits/stdc++.h>
using namespace std;
ifstream fin("sleepy.in");
ofstream fout("sleepy.out");

int n;
vector<int> v;
int main() {
  fin>>n;
  for(int i=0; i<n; i++){
    int x;
    fin>>x;
    v.push_back(x);
  }
  int counter=  1;
  for(int i=n-2; i>=0; i--){
    if(v[i]<v[i+1]) counter++;
    else break;
  }
  fout<<n-counter;
}
