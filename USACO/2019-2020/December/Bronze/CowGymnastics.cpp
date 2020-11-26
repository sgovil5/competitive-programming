#include <fstream>
#include <iostream> 
using namespace std;
ifstream fin("gymnastics.in");
ofstream fout("gymnastics.out");

int k,n;
int arr[11][21];

int findPos(int c1, int K){
  int ans;
  for(int i=0; i<n; i++){
    if(arr[K][i]==c1) ans = i;
  }
  return ans;
}

int main(){
  fin>>k>>n;
  
  for(int i=0; i<k; i++){
    for(int j=0; j<n; j++){
      fin>>arr[i][j];
    }
  }
  int numPairs = 0;
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      bool possible = true;
      for(int l = 0; l<k; l++){
        if(findPos(i,l)>=findPos(j, l)) possible = false;
      }
      if(possible) numPairs++;
    }
  }
  fout << numPairs;
  return 0;
}
