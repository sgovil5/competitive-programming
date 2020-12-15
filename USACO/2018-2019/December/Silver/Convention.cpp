#include <bits/stdc++.h>
using namespace std;
ifstream fin("convention.in");
ofstream fout("convention.out");

int n,m,c;
int arrivals[100003];

bool check(int time){
  int bus = 1;
  int pickupIndex = 0;
  for(int i=0; i<n; i++){
    if(arrivals[i]-arrivals[pickupIndex]>time||i+1-pickupIndex>c){
      bus++;
      pickupIndex = i;
    }
  }
  return bus<=m;
}

int fstTrue(int lo, int hi){
  for(hi++; lo<hi;){
    int mid = (lo+hi)/2;
    check(mid) ? hi = mid : lo = mid+1;
  }
  return lo;
}

int main() {
  fin>>n>>m>>c;
  for(int i=0; i<n; i++){
    fin>>arrivals[i];
  }
  sort(arrivals, arrivals+n);
  fout<<fstTrue(0,1000000000);
}
