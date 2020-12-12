#include <bits/stdc++.h>
using namespace std;
ifstream fin("lifeguards.in");
ofstream fout("lifeguards.out");

int main(){
  int n;
  fin>>n;
  int start[n+1];
  int stop[n+1];
  for(int i=0; i<n; i++){
    int st,sp;
    fin>>st>>sp;
    start[i] = st, stop[i] = sp;
  }  
  int maxTime = 0;
  for(int remove=0; remove<n; remove++){
    bool arr[1001];
    fill(arr,arr+1001,false);
    for(int i=0; i<n; i++){
      if(i!=remove){
        for(int j=start[i]; j<stop[i]; j++){
          arr[j] = true;
        } 
      }
    }
    int ctr = 0;
    for(int i=0; i<1001; i++){
      if(arr[i]) ctr++;
    }
    maxTime = max(ctr,maxTime);
  }
  fout<<maxTime;
}
