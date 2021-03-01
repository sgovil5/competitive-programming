#include <bits/stdc++.h>
using namespace std;
ifstream fin("shuffle.in");
ofstream fout("shuffle.out");

const int MX = 1e5+1;

int n, t=1, ans=0; 
//where t is the current "time"
int a[MX], timeVis[MX]={0}; 
//where timeVis is the "time" that a cow was visited
bool curr_stack[MX]={false}; 
// represents when a cow is currently part of the cycle we are checking for

void dfs(int node){
  timeVis[node] = t++, curr_stack[node] = true;
  int next_node = a[node];
  if(curr_stack[next_node]){
    // We have found a cycle and thus the number of cows we have visited during the cycle = the number of cows that are guaranteed to have cows
    ans+=t-timeVis[next_node];
  } 
  else if(!timeVis[next_node]){
    dfs(next_node);
  }
  curr_stack[node] = false;
}

int main(){
  fin>>n;
  for(int i=1; i<=n; i++) fin>>a[i];
  for(int i=1; i<=n; i++){
    if(!timeVis[i]) dfs(i);
  }
  fout<<ans;
}
