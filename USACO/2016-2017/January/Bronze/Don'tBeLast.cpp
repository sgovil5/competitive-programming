#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;
ifstream fin("notlast.in");
ofstream fout("notlast.out");
int main() {
  map<string,int> m;
  int n;
  fin>>n;
  m["Bessie"]=0,m["Elsie"]=0,m["Daisy"]=0, m["Gertie"]=0, m["Annabelle"]=0, m["Maggie"]=0, m["Henrietta"]=0;
  for(int i=0; i<n; i++){
    string x;
    int prod;
    fin>>x>>prod;
    m[x]+=prod;
  }
  int min_prod=10e8;
  int sec_min=10e8;
  string min_name;
  string sec_name;
  for(pair<string,int> x:m){
    if(x.second<min_prod){
      sec_min = min_prod;
      min_prod = x.second;
    }
    else if(x.second <sec_min &&x.second!= min_prod){
      sec_min = x.second;
    }
  }
  string ans;
  vector<string> vect;
  if(sec_min==min_prod) ans = "Tie";
  else{
    for(pair<string,int> x:m){
      if(x.second == sec_min){
        vect.push_back(x.first);
      }
    }
    if(vect.size()>1){
      ans="Tie";
    }
    else if(vect.size()==1) ans = vect[0];
    else if(vect.size()==0) ans = "Tie";
  }
  fout<<ans;
}
