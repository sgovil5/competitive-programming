#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  double flowers[n];
  for(int i=0; i<n; i++){
    cin>>flowers[i];
  }
  int count = 0;
  for(int i=0; i<n; i++){
    for(int j=i; j<n; j++){
      float rangeSum = 0;
      for(int k=i; k<=j; k++){
        rangeSum+=flowers[k];
      }
      float average = rangeSum/(j-i+1);
      bool hasAverage = false;
      for(int k=i; k<=j; k++){
        if(flowers[k]==average){
          hasAverage = true;
        }
      }
      if(hasAverage) count++;
    }
  }
  cout<<count;
}
