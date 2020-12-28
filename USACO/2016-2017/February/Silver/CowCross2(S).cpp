#include <bits/stdc++.h>
using namespace std;
ifstream fin("maxcross.in");
ofstream fout("maxcross.out");

int main() {
  int n,k,b;
  fin>>n>>k>>b;
  bool broken[100002]={false};
  for(int i=1; i<=b; i++){
    int broke;
    fin>>broke;
    broken[broke] = true;
  }
  int prefix[n+1];
  prefix[0] = 0;
  for(int i=1; i<=n; i++){
    prefix[i] = prefix[i-1];
    if(!broken[i]) prefix[i]++; 
  }
  for(int i=1; i<=n; i++){
    prefix[i]=i-prefix[i];
  }
  int minFix = 1e9;
  for(int i=1; i<=n-k; i++){
    int fix = prefix[i+k]-prefix[i];
    minFix = min(minFix, fix);
  }
  fout<<max(minFix, 0);
}
