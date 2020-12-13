#include <bits/stdc++.h>
using namespace std;
ifstream fin("herding.in");
ofstream fout("herding.out");

int main(){
  int arr[3];
  for(int i=0; i<3; i++) fin>>arr[i];
  int min;
  sort(arr,arr+3);
  if(arr[1]-arr[0]==2||arr[2]-arr[1]==2) min = 1;
  else if(arr[0]+1==arr[1]&& arr[1]+1==arr[2]) min = 0;
  else min = 2;
  int max_output = max(arr[2]-arr[1],arr[1]-arr[0]);
  fout<<min<<"\n"<<max_output-1;
}
