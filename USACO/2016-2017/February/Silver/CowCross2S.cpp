#include <iostream>
#include <vector>
using namespace std;

const int MX = 1e5+5;

int n,k,b;
bool broken[MX] = {false};
int psum[MX] = {0};

void setIO(string fileName = "") {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	if((int)fileName.size()) {
		freopen((fileName+".in").c_str(), "r", stdin);
		freopen((fileName+".out").c_str(), "w", stdout);
	}
}

int main(){
  setIO("maxcross");

  cin>>n>>k>>b;
  for(int i=0; i<b; i++){
    int x; cin>>x;
    broken[x] = true;
  }

  for(int i=1; i<=n; i++){
    psum[i] = psum[i-1];
    if(broken[i]) psum[i]++;
  }

  int minAmt = 1e9;
  for(int i=1; i<=n-k+1; i++){
    minAmt = min(minAmt, psum[i+k-1]-psum[i-1]);
  }

  cout<<minAmt;
}