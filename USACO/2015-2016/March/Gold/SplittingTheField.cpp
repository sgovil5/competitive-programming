/* Approach:
Calculate the minY and maxY for each point from the left and right.
Then break the fence into two pieces at each point and calculate area accordingly and update minArea
Repeat the process for the X values by swapping points[i].f and points[i].s
*/

#include <bits/stdc++.h>
using namespace std;
ifstream fin("split.in");
ofstream fout("split.out");

// Using long longs to fit big numbers
// Got destroyed without it :pensive:
#define int long long
#define f first
#define s second

int n;
vector<pair<int,int>> points; //x,y
vector<pair<int,int>> leftVals; //min,max
vector<pair<int,int>> rightVals; //min, max
// IMPORTANT lmao
int minArea = 1e18;

signed main() {
  fin>>n;
  for(int i=0; i<n; i++){
    int x,y;
    fin>>x>>y;
    points.push_back({x,y});
  }
  // Do both x and y
  for(int s=0; s<2; s++){
    leftVals.clear();
    rightVals.clear();
    // Swap x and y to reuse code
    for(int i=0; i<n; i++) swap(points[i].f, points[i].s);
    sort(begin(points), end(points));
    // Calculate min and max of Y(and X) for each point from left to right
    int minY= 1e18, maxY = 0;
    for(int i=0; i<n-1; i++){
      minY = min(minY,points[i].s);
      maxY = max(maxY, points[i].s);
      leftVals.push_back({minY,maxY});
    }
    // Calculate min and max of Y(and X) for each point from the right to left
    minY = 1e18, maxY = 0;
    for(int i=n-1; i>=1; i--){
      minY = min(minY,points[i].s);
      maxY = max(maxY, points[i].s);
      rightVals.push_back({minY,maxY});
    }
    // Loop through every point
    for(int i=0; i<n-1; i++){
      int area;
      // Deal for i being n-1. Don't know if it's necessary
      if(i==n-1){
        area = (points[n-2].f-points[0].f) * (leftVals[n-2].s-leftVals[n-2].f);
      }
      else{
      // Calculate area
        int r1 = (points[i].f-points[0].f) * (leftVals[i].s-leftVals[i].f);
        int r2 = (points[n-1].f-points[i+1].f) * (rightVals[n-i-2].s-rightVals[n-i-2].f);
        area = r1+r2;
      }
      minArea = min(minArea, area);
    }
  }
  // Find total area
  int totMinY = 1e18, totMaxY = 0;
  for(int i=0; i<n; i++){
    totMinY = min(totMinY, points[i].s);
    totMaxY = max(totMaxY, points[i].s);
  }
  int totArea = (points[n-1].f-points[0].f) * (totMaxY- totMinY);
  fout<<totArea-minArea;
}
