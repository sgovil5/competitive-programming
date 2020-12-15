#include <bits/stdc++.h>
using namespace std;
ifstream fin("taming.in");
ofstream fout("taming.out");

int n;
int arr[101];

int main(){
  fin>>n;
  for(int i=0; i<n; i++){
    fin>>arr[i];
  }
  bool isPossible = true;
  for(int i=n-1; i>=0; i--){
    if(arr[i]!=0||arr[i]!=-1){
      for(int j=arr[i]; j>=0; j--){
        if((arr[i-j] != arr[i]-j)&&(arr[i-j]!=-1)){
          isPossible = false;
        }
        else{
          arr[i-j] = arr[i]-j;
        }
      }
    }
  }
  int m=0, M=0;
  if(arr[0]>0) isPossible = false;
  else if(arr[0]==-1) m++;
  for(int i=0; i<n; i++){
    if(arr[i]==0) M++, m++;
    if(arr[i]==-1) M++;
  }
  if(isPossible){
    fout<<m<<" "<<M;
  }
  else fout<<-1;
}
