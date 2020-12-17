#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;
ifstream fin("cowtip.in");
ofstream fout("cowtip.out");
int n;
int arr[10][10];

bool done(){
  bool ans = true;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(arr[i][j]==1) ans = false;
    }
  }
  return ans;
}

int main(){
  fin>>n;
  for(int i=0; i<n; i++){
    string s;
    fin>>s;
    for(int j=0; j<n; j++){
      arr[i][j] = (int) s[j] - '0';
    }
  }
  int counter = 0;
  while(!done()){
    int maxr, maxc;
    bool found= false;
    for(int i=n-1; i>=0; i--){
      for(int j=n-1; j>=0; j--){
        if(arr[i][j]==1){
          maxc = j;
          maxr = i;
          found=true;
          if(found) break;
        }
      }
      if(found) break;
    }
    for(int i=0; i<=maxr; i++){
      for(int j=0; j<=maxc; j++){
        if(arr[i][j]==1) arr[i][j]=0;
        else arr[i][j]=1;
      }
    }
    counter++;
  }
		
  fout<<counter;
}
