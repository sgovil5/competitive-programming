#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define f first
#define s second

void setIO(string fileName = "") {
	ios_base::sync_with_stdio(0); cin.tie(0);
	if((int)fileName.size()) {
		freopen((fileName+".in").c_str(), "r", stdin);
		freopen((fileName+".out").c_str(), "w", stdout);
	}
}

int l, n, rf, rb;
vector<pair<long long,long long>> v; //tastiness, position

int main(){
  setIO("reststops");
  cin>>l>>n>>rf>>rb;
  for(int i=0; i<n; i++){
    long long p, t; cin>>p>>t;
    v.push_back({t, p});
  }
  sort(begin(v), end(v));

  long long score = 0;
  long long mxPos=0,currTime=0;
  for(int i=n-1; i>=0; i--){
    if(v[i].s>mxPos){
      currTime+=(v[i].s-mxPos)*rb;
      score+=((rf*v[i].s)-currTime)*v[i].f;
      currTime = rf*v[i].s;
      mxPos = v[i].s;
    }
  }
  cout<<score<<endl;
}