#include <fstream>
using namespace std;
ifstream fin("swap.in");
ofstream fout("swap.out");

int n,k;

bool arrEqual(int orig[], int arr[]){
  bool ans = true;
  for(int i =0; i<n; i++){
    if(orig[i]!=arr[i]) ans = false;
  }
  return ans;
}

int main(){
  fin>>n>>k;
  int a1,a2,b1,b2;
  fin>>a1>>a2>>b1>>b2;
  int arr[n];
  int orig[n];
  for(int i=0; i<n; i++){
    arr[i] = i+1;
    orig[i] = arr[i];
  }
  int j = 0;
  while(j<k){
    for(int i=0; i<(a2-a1+1)/2; i++){
      swap(arr[i+a1-1], arr[a2-i-1]);
    }
    for(int i=0; i<(b2-b1+1)/2; i++){
      swap(arr[i+b1-1], arr[b2-i-1]);
    }
    j++;
    if(arrEqual(orig, arr)){
      int x = j;
      for(int l=0; l<k%x; l++){
        for(int i=0; i<(a2-a1+1)/2; i++){
          swap(arr[i+a1-1], arr[a2-i-1]);
        }
        for(int i=0; i<(b2-b1+1)/2; i++){
          swap(arr[i+b1-1], arr[b2-i-1]);
        }
      }
      break;
    }
  }
  for(int i=0; i<n; i++) fout<<arr[i]<<endl;
}
