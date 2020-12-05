#include <bits/stdc++.h>
using namespace std;
ifstream fin("guess.in");
ofstream fout("guess.out");

int n;
vector<set<string>> traits;

int main(){
  fin>>n;
  traits.resize(n);
  for(int i=0; i<n; i++){
    string name;
    int k;
    fin>>name>>k;
    for(int j=0; j<k; j++){
      string s;
      fin>>s;
      traits[i].insert(s);
    }
  }
  int maxSame = 0;
  for(int i=0; i<n; i++){
    for(int j = i+1; j<n; j++){
      set<string> s;
      merge(traits[i].begin(),traits[i].end(),traits[j].begin(), traits[j].end(),inserter(s, s.begin()));
      int same = traits[i].size()+traits[j].size()-s.size();
      maxSame = max(same, maxSame);
    }
  }
  fout<<maxSame+1;
}
