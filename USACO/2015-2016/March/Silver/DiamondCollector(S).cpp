#include <bits/stdc++.h>
using namespace std;
ifstream fin("diamond.in");
ofstream fout("diamond.out");

int main() {
  int n,k;
  fin>>n>>k;
  int arr[n];
  for(int i=0; i<n; i++){
    fin>>arr[i];
  }
  sort(arr, arr+n);
  int fitLeft[n];
  int l=0, r = 0;
  for( ;l<n; l++){
    while(r<n && arr[r]<=arr[l]+k) r++;
    fitLeft[l] = r-l;
  }
  int maxRight[n+1];
  maxRight[n] = 0;
  for(int i = n-1; i>=0; i--){
    maxRight[i] = max(maxRight[i+1], fitLeft[i]);
  }
  int ans = 0;
  for(int i=0; i<n; i++){
    ans = max(maxRight[i+fitLeft[i]]+fitLeft[i], ans);
  }
  fout<<ans;
}
