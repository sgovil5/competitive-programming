#include <bits/stdc++.h>
using namespace std;

const int MX = 1e5+5;

string s, t, ans="";
int q;
bool works[19][19];
int sfreq[19]={0}, tfreq[19]={0};

int main() {
  cin>>s>>t>>q;

  // calculate frequencies
  for(char x: s) sfreq[x-'a']++;
  for(char x: t) tfreq[x-'a']++;

  // Init lookup table to not visited & not working
  for(int i=0; i<19; i++) {
    for(int j=0; j<19; j++) {
      works[i][j] = false;
    }
  }

  // create lookup table
  for(char i='a'; i<='r'; i++){
    for(char j=i; j<='r'; j++){
      //turn s to char arr
      vector<char> sarr;
      for(int k=0; k<s.length(); k++){
        if(s[k]==i || s[k]==j) sarr.push_back(s[k]);
      }

      // turn t to char arr
      vector<char> tarr;
      for(int k=0; k<t.length(); k++){
        if(t[k]==i || t[k]==j) tarr.push_back(t[k]);
      }
      
      // convert char vectors to strings
      string sstring(sarr.begin(), sarr.end());
      string tstring(tarr.begin(), tarr.end());

      // check if equal, and update lookup table
      if(sstring.compare(tstring)==0){
        works[i-'a'][j-'a'] = true;
      }
    }
  }
  
  //loop thru every query
  while(q--){
    string query; cin>>query;
    bool flag = true;

    // compute sum of wanted letters in both s and t to make sure they are the same length
    int sSum= 0, tSum=0;
    for(char x: query){
      sSum+=sfreq[x-'a'];
      tSum+=tfreq[x-'a'];
    }

    if(sSum!=tSum) flag = false;

    // go through every pair of letters in the query to make sure each pair of 2 works
    for (int i=0; i<query.length(); i++){
      for (int j=i+1; j<query.length(); j++){
        if(!works[query[i]-'a'][query[j]-'a']) flag = false;
      }
    }
    if(flag) ans+="Y";
    else ans+="N";
  }
  
  cout<<ans;
  
}
