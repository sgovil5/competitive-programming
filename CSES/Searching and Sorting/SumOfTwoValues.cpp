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
  int left = 0, right = n-1;
  while(left<right){
    if(sorted[left]+ sorted[right] == x) break;
    else if(sorted[left]+ sorted[right] < x) left++;
    else right --;
  }
  if(left >= right) cout<<"IMPOSSIBLE";
  else{
    int leftVal, rightVal;
    for(int i=0; i<n; i++){
      if(sorted[left] == arr[i]){
        leftVal = i+1;
        break;
      }
    }
    for(int i=0; i<n; i++){
      if(sorted[right]==arr[i]&&i+1!=leftVal){
        rightVal = i+1;
        break;
      }
    }
    cout<<leftVal<<" "<<rightVal;
  }
}
