#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

// Template to move direction
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
// 3000 because bounds may exceed 1000
int present[3000][3000];

int main() {
  int n, totalCows = 0;
  cin>>n;
  queue<pair<int,int>> q;
  for(int initCows = 1; initCows<= n; initCows++){
    int a,b;
    cin>>a>>b;
    // Make sure bounds don't go negative
    a+=500, b+=500;
    q.push({a,b});

    auto evaluate = [&](int x, int y){
      // If cow doesn't exist, we don't have need to check it neighbors
      if(!present[x][y]) return;
      int numAdj = 0;
      // Count num adjacent cows
      for(int d = 0; d<4; d++){
        if(present[x+dx[d]][y+dy[d]]) ++numAdj;
      }

      if(numAdj==3){
        // Find adjacent cow that doesn't exist to make cow uncomfortable
        for(int d=0; d<4; d++){
          pair<int,int> next = {x+dx[d], y+dy[d]};
          // Add given cow to queue for processing
          if(!present[next.f][next.s]) q.push(next);
        }
      }
    };
    // BFS
    while(!q.empty()){
      pair<int,int> curr = q.front();
      q.pop();
      // If the cow already exists, we have already processed it
      if(!present[curr.f][curr.s]){
        // Add a new cow
        ++totalCows;
        present[curr.f][curr.s] = true;
        // Evaluate current cow and neighboring cows to make sure that none are comfortable
        evaluate(curr.f, curr.s);
        for(int d=0; d<4; d++) evaluate(curr.f+dx[d], curr.s+dy[d]);
      }
    }
    // Output because we need to find how many cows were added and total cows carryover from previous iterations
    cout<<totalCows - initCows<<endl;
  }
}
