#include <bits/stdc++.h>
using namespace std;
ifstream fin("diamond.in");
ofstream fout("diamond.out");

int arr[50003];
int fit[50003] = {1};
int fitRight[50003];

int main(){
  //Setup
  int n,k; fin>>n>>k;
  for(int i=0; i<n; i++) fin>>arr[i];
  sort(arr, arr+n);

  // Calculate how many each starting point can hold
  for(int i=0; i<n; i++) fit[i]=1;
  int l = 0, r = 0;
  for( ;l<n; l++){
    while(r<n && arr[r]<=arr[l]+k) r++;
    fit[l] = r-l;
  }
  
  // Create array to calculate max of the 2nd collection
  fitRight[n] = 0;
  for(int i=n-1; i>=0; i--) fitRight[i] = max(fitRight[i+1], fit[i]);
  
  // Calculate answer
  int maxAns = 0;
  for(int i=0; i<n; i++){
    int ans=fit[i] + fitRight[i+fit[i]];
    maxAns = max(maxAns, ans);
  }
  fout<<maxAns;
}
