#include <bits/stdc++.h>
using namespace std;
ifstream fin("stacking.in");
ofstream fout("stacking.out");

int main() {
  int n, k;
  fin>>n>>k;
  int prefix[n+1];
  for(int i=0; i<=n; i++) prefix[i] = 0;
  for(int i=0; i<k; i++){
    int a,b;
    fin>>a>>b;
    a--;
    prefix[a]++, prefix[b]--;
  }
  int arr[n]; arr[0] = prefix[0];
  for(int i=1; i<n; i++){
    arr[i] = prefix[i]+ arr[i-1];
  }
  sort(arr, arr+n);
  fout<<arr[n/2];
}
