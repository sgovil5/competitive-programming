#include <bits/stdc++.h>
using namespace std;
ifstream fin("cardgame.in");
ofstream fout("cardgame.out");

int main(){
  int n; fin>>n;
  set<int> elsieHigh, elsieLow, bessie, v;
  for(int i=0; i<n/2; i++){
    int x; fin>>x;
    elsieHigh.insert(x); v.insert(x);
  }
  for(int i=0; i<n/2; i++){
    int x; fin>>x;
    elsieLow.insert(x); v.insert(x);
  }
  for(int i=1; i<=2*n; i++){
    if(v.find(i)==v.end()) bessie.insert(i); 
  }

  int ans = 0;

  set<int>::reverse_iterator rit;
  for(rit = elsieHigh.rbegin(); rit!=elsieHigh.rend(); rit++){
    if(*bessie.rbegin() > *rit){
      ans++;
      bessie.erase(*bessie.rbegin());
    }
  }

  for(auto elem: elsieLow){
    if(bessie.lower_bound(elem)!=bessie.begin()){
      ans++;
      bessie.erase(--bessie.lower_bound(elem));
    }
    else if(*bessie.begin()<elem) ans++;
  }

  fout<<ans<<endl;
}
