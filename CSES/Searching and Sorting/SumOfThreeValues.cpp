#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,x;
  cin>>n>>x;
  int arr[n];
  int sorted[n];
  for(int i=0; i<n; i++){
    cin>>arr[i];
    sorted[i] = arr[i];
  }
  sort(sorted, sorted+n);
  bool isPossible = false;
  int left=0, right=n-1, iVal;
  for(int i=0; i<n; i++){
    left = 0, right = n-1;
    while(left<right){
      if(left!=i&&right!=i&&sorted[left]+sorted[right]==x-sorted[i]){
        iVal = i;
        i=n;
        isPossible = true;
        break;
      }
      else if(sorted[left]+sorted[right]<x-sorted[i]) left++;
      else right--;
    }
  }
  if(!isPossible) cout<<"IMPOSSIBLE";
  else{
    int leftVal, rightVal, iAns;
    for(int i=0; i<n; i++){
      if(sorted[iVal]==arr[i]){
        iAns = i+1;
        break;
      }
    }
    for(int i=0; i<n; i++){
      if(i+1!=iAns&&sorted[left] == arr[i]){
        leftVal = i+1;
        break;
      }
    }
    for(int i=0; i<n; i++){
      if(i+1!=iAns&&sorted[right]==arr[i]&&i+1!=leftVal){
        rightVal = i+1;
        break;
      }
    }
    cout<<leftVal<<" "<<rightVal<<" "<<iAns;
  }
}
