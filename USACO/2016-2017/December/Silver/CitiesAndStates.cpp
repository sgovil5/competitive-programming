#include <bits/stdc++.h>
using namespace std;
ifstream fin("citystate.in");
ofstream fout("citystate.out");

int main(){
  int n;
  fin>>n;
  map<string, int> m;
  vector<string> list;
  int ans =0;
  for(int i=0; i<n; i++){
    string c,s;
    fin>>c>>s;
    c = c.substr(0,2);
    if(c!=s) ans+=m[s+c];
    m[c+s]++;
  }
  fout<<ans;
}
