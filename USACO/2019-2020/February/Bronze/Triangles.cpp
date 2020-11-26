#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
ifstream fin("triangles.in");
ofstream fout("triangles.out");

int main(){
  int n;
  fin>>n;
  int points[n][n];
  for(int i=0; i<n; i++){
    fin>>points[i][0]>>points[i][1];
  }
  int max_area=0;
  for(int i=0; i<n; i++){
    int x1 = points[i][0];
    int y1 = points[i][1];
    for(int j=i+1; j<n; j++){
      int x2 = points[j][0];
      int y2 = points[j][1];
      for(int k=j+1; k<n; k++){
        int x3 = points[k][0];
        int y3 = points[k][1];
        if((x1-x2==0||x2-x3==0||x3-x1==0)&&(y1-y2==0||y2-y3==0||y3-y1==00)){
          int temp = max(abs(x1-x2),abs(x2-x3)) * max(abs(y1-y2),abs(y2-y3));
          max_area = max(max_area,temp);
        }
      }
    }
  }
  fout<<max_area;
}
