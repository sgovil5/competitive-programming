#include <bits/stdc++.h>
using namespace std;

int main() {
  string n;
  cin>>n;
  int ans  = 0;
  for(int i= n.size()-1; i>=0; i--){
    if(n[i]=='4'){
      ans+=pow(2,(n.size()-1-i));
    }
    else{
      ans+=2*pow(2, n.size()-1-i);
    }
  }
  cout<<ans;
  return 0;
}
