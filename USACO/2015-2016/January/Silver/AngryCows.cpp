#include <bits/stdc++.h>
using namespace std;
ifstream fin("angry.in");
ofstream fout("angry.out");

int n, k;
vector<int> v;

bool check(int r){
  int currCows = 0;
  for(int currIndex=0; currIndex<n; currIndex++){
    auto ind = lower_bound(v.begin(), v.end(), v[currIndex]+2*r);
    v[ind-v.begin()]==v[currIndex]+2*r ?  ind = ind : ind = prev(ind);
    currCows++;

    currIndex = ind-v.begin();
  }

  return currCows<=k;
}

int firstTrue(int lo, int hi) {
	hi++;
	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		if (check(mid)) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	return lo;
}

int main(){
  fin>>n>>k;
  for(int i=0; i<n; i++){
    int x; fin>>x;
    v.push_back(x);
  }
  sort(v.begin(), v.end());

  fout<<firstTrue(1, 1e9+5);
}
