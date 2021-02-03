#include <bits/stdc++.h>
using namespace std;
ifstream fin("pails.in");
ofstream fout("pails.out");

#define f first
#define s second
#define pii pair<int,int>

int x,y,k,m;
queue<pair<pii, int>> q; //pii for pails, int for depth
set<pii> used;
int main() {
  fin>>x>>y>>k>>m;
  int minAns = 1e9;
  // Do BFS
  q.push({{0,0},0});
  while(!q.empty() && q.front().s<=k){
    pair<pii, int> currNode = q.front();
    minAns = min(abs(m-(currNode.f.f+currNode.f.s)), minAns);
    q.pop();
    used.insert({currNode.f.f, currNode.f.s});
    // Fill pail 1
    if(used.count({x, currNode.f.s})==0){
      q.push({{x,currNode.f.s}, currNode.s+1});
    }
    // Fill pail 2
    if(used.count({currNode.f.f, y})==0){
      q.push({{currNode.f.f, y}, currNode.s+1});
    }
    // Empty pail 1
    if(used.count({0, currNode.f.s})==0){
      q.push({{0, currNode.f.s}, currNode.s+1});
    }
    // Empty pail 2
    if(used.count({currNode.f.f, 0})==0){
      q.push({{currNode.f.f, 0}, currNode.s+1});
    }
    // Pour pail 1 into pail 2
    if(currNode.f.f+currNode.f.s<=y && used.count({0, currNode.f.f+currNode.f.s}) == 0){
      q.push({{0, currNode.f.f+currNode.f.s}, currNode.s+1});
    }
    if(currNode.f.f+currNode.f.s>y && used.count({currNode.f.f-(y-currNode.f.s), y}) == 0){
      q.push({{currNode.f.f-(y-currNode.f.s), y}, currNode.s+1});
    }
    // Pour pail 2 into pail 1
    if(currNode.f.f+currNode.f.s<=x && used.count({currNode.f.f+currNode.f.s, 0}) == 0){
      q.push({{currNode.f.f+currNode.f.s, 0}, currNode.s+1});
    }
    if(currNode.f.f+currNode.f.s>x && used.count({x, currNode.f.s-(x-currNode.f.f)})==0){
      q.push({{x, currNode.f.s-(x-currNode.f.f)}, currNode.s+1});
    }
  }
  fout<<minAns;
}
