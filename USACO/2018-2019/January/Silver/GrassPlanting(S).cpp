#include <bits/stdc++.h>
using namespace std;
ifstream fin("planting.in");
ofstream fout("planting.out");

int n;
map<int,int> adj;

int main() {
  fin>>n;
  for(int i=0; i<n-1; i++){
    int a,b;
    fin>>a>>b;
    adj[a]++;
    adj[b]++;
  }
  int ans = 0;
  for(int i=1; i<=n; i++){
    int sum = adj[i];
    ans = max(sum, ans);
  }
  fout<<ans+1;
}
