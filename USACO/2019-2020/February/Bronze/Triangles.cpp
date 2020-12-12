#include <bits/stdc++.h>
using namespace std;
ifstream fin("triangles.in");
ofstream fout("triangles.out");

int main(){
  int n;
  fin>>n;
  int arr[n][2];
  for(int i=0; i<n; i++){
    fin>>arr[i][0]>>arr[i][1];
  }
  int max_area = 0;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      for(int k=0; k<n; k++){
        int area=0;
        if(arr[k][0]-arr[i][0]==0&&arr[j][1]-arr[i][1]==0){
          area = abs(arr[k][1]-arr[i][1])*abs(arr[j][0]-arr[i][0]);
        }
        max_area = max(max_area,area);
      }
    }
  }
  fout<<max_area;
}
