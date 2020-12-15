#include <bits/stdc++.h>
using namespace std;
ifstream fin("angry.in");
ofstream fout("angry.out");

int n,k;
int pos[50005];

bool check(int radius){
  int cows = 1;
  int leftNotExploded = pos[0];
  for(int i=0; i<n; i++){
    if(leftNotExploded +2 *radius<pos[i]){
      cows++;
      leftNotExploded = pos[i];
    }
  }
  return cows<=k;
}

int fstTrue(int lo, int hi){
  for (hi ++; lo < hi; ) {
        int mid = (lo+hi)/2;
        check(mid) ? hi = mid : lo = mid+1;
    }
    return lo;
}

int main() {
  fin>>n>>k;
  for(int i=0; i<n; i++){
    fin>>pos[i];
  }
  sort(pos, pos+n);
  fout<<fstTrue(0,1000000000);
}
