// Parity of the number of Cs and Os must be odd
// Parity of the number of Os and Ws must be even
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

const int MX = 2e5+5;

string s; int q;
int freqc[MX]={0}, freqw[MX]={0}, freqo[MX]={0};

int main(){
  cin>>s>>q;
  string ans = "";
  for(int i=1; i<=s.length(); i++){
    freqc[i] = freqc[i-1];
    freqw[i] = freqw[i-1];
    freqo[i] = freqo[i-1];
    if(s[i-1]=='C') freqc[i]++;
    else if (s[i-1]=='W') freqw[i]++;
    else if (s[i-1]=='O') freqo[i]++;
  }
  while(q--){
    int a,b; cin>>a>>b;
    if((((freqc[b]-freqc[a-1]) + (freqo[b]-freqo[a-1]))%2==1) && ((freqw[b]-freqw[a-1]) + (freqo[b]-freqo[a-1]))%2==0){
      ans+="Y";
    }
    else ans+="N";
  }
  cout<<ans;
}
