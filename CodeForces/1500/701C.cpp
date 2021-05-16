#include <iostream>
#include <set>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int n;
string s;
set<char> letters;

int main(){
    cin>>n>>s;
    for(int i=0; i<n; i++) letters.insert(s[i]);

    int len[1000001]={0};
    for(auto c: letters){
        int last = -1;
        for(int i=0; i<n; i++){
            if(s[i]==c) last = i;
            if(last!=-1) len[i] = max(len[i], i-last+1); 
            else len[i] = (int) 1e9; 
        }
    }

    int ans = 1e9;
    for(int i=0; i<n; i++){
        ans = min(ans, len[i]);
    }

    cout<<ans;
}