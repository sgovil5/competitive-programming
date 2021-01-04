#include <bits/stdc++.h>
using namespace std;
ifstream fin("pairup.in");
ofstream fout("pairup.out");

int n;
vector<pair<int,int>> v; // time, num
int main() {
  fin>>n;
  for(int i=0; i<n; i++){
    int t,n;
    fin>>n>>t;
    v.push_back({t,n});
  }
  sort(begin(v), end(v));
  int left = 0, right = n-1;
  int maxTime = 0;
  while(right>=left){
    if(v[right].second==0) right--;
    if(v[left].second==0) left++;
    int time = v[left].first+v[right].first;
    maxTime = max(maxTime, time);
    v[left].second--, v[right].second--;
  }
  fout<<maxTime;
}
