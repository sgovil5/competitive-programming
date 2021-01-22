#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,t;
  cin>>n>>t;
  int arr[n];
  for(int i=0; i<n; i++){
    cin>>arr[i];
  }
  int left = 0, right = 0, sum = 0;
  int maxBooks = 0;
  for(right =0; right<n; right++){
    sum+=arr[right];
    while(sum > t && left<right){
      sum-=arr[left];
      left++;
    }
    if(sum<=t){
      maxBooks = max(maxBooks,right-left+1);
    }
  }
  cout<<maxBooks;
}
