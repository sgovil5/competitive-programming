// Bruh why did I spend 2 hours to solve this
#include <bits/stdc++.h>
using namespace std;

int getLower(int x){
  return 12*((x-1)/12);
}

int getUpper(int x){
  if(x==0) return 0;
  return 12*(((x-1)/12)+1);
}

int main() {
  int n,k;
  cin>>n>>k;

  int yr[n];
  yr[0]=0;
  for(int i=1; i<=n; i++){
    cin>>yr[i];
  }
  sort(yr, yr+n+1);

  int maxDist[n];
  for(int i=0; i<n; i++){
    maxDist[i] = max(0, getLower(yr[i+1])-getUpper(yr[i]));
  }
  int dist = getUpper(yr[n]);
  sort(maxDist, maxDist+n);
  for(int i= n-1; i>(n-k); i--) dist-=maxDist[i];

  cout<<dist;
}
