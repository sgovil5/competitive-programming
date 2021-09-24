#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int grid[1005][1005];

int main(){
  cin>>n;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin>>grid[i][j];
    }
  }

  int sumHor = 0;

  // loop through every column
  for(int i=0; i<n; i++){
    // start from the first index
    int sum1 = 0;
    for(int j=0; j<n; j+=2){
      sum1+=grid[i][j];
    }

    //start from the next index
    int sum2 = 0;
    for(int j=1; j<n; j+=2){
      sum2+=grid[i][j];
    }

    sumHor+=max(sum1, sum2);
  }

  int sumVer = 0;

  // loop through every column
  for(int i=0; i<n; i++){
    // start from the first index
    int sum1 = 0;
    for(int j=0; j<n; j+=2){
      sum1+=grid[j][i];
    }

    //start from the next index
    int sum2 = 0;
    for(int j=1; j<n; j+=2){
      sum2+=grid[j][i];
    }

    sumVer+=max(sum1, sum2);
  }

  cout<<max(sumVer, sumHor);
}