#include <bits/stdc++.h>
using namespace std;
ifstream fin("traffic.in");
ofstream fout("traffic.out");

struct Sensor{
  string t;
  int lo,hi;
};

int n;
vector<Sensor> v;

int main(){
  fin>>n;
  for(int i=0; i<n; i++){
    string s;
    int st, sp; //start,stop;
    fin>>s>>st>>sp;
    v.push_back({s,st,sp});
  }
  int minIn=-1e9,maxIn = 1e9;
  for(int i=n-1; i>=0; i--){
    if(v[i].t=="none") {
      minIn = max(minIn,v[i].lo); 
      maxIn = min(maxIn,v[i].hi);
    }
    if(v[i].t=="off") {
      minIn+=v[i].lo; 
      maxIn+=v[i].hi;
    }
    if(v[i].t=="on"){
      minIn-=v[i].hi;
      maxIn-=v[i].lo;
      minIn = max(0, minIn);
    }
  }
  int minOut=-1e9,maxOut = 1e9;
  //Find out
  for(int i=0; i<n; i++){
    if(v[i].t=="none") {
      minOut = max(minOut,v[i].lo); 
      maxOut = min(maxOut,v[i].hi);
    }
    if(v[i].t=="on") {
      minOut+=v[i].lo; 
      maxOut+=v[i].hi;
    }
    if(v[i].t=="off"){
      minOut-=v[i].hi;
      maxOut-=v[i].lo;
      minOut = max(0, minOut);
    }
  }
  fout<<minIn<<" "<<maxIn<<"\n"<<minOut<<" "<<maxOut;
}
