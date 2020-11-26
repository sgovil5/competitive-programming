#include <iostream>
#include <fstream>
#include <set>
#include <string>
using namespace std;
ifstream fin("whereami.in");
ofstream fout("whereami.out");
int n;
string s;
int main(){
  fin>>n;
  fin>>s;
  int ans;
  for(int i=0; i<n; i++){
    set<string> size;
    for(int j=0; j<n-i; j++){
      string input = "";
      for(int k=j; k<=j+i; k++){
        input+=s[k];
      }
      size.insert(input);
    }
    if(size.size()==(s.size()-i+1)){
      ans = i;
      break;
    }
  }
  fout<<ans;
}
