#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int MX = 1e5+5;

int n,q;
string s;
int min_since_prev[26];
int prefix[MX], suffix[MX];

int main(){
    cin>>n>>q>>s;

    // Calculate Prefix
    prefix[0] = 0;
    for(int i=0; i<26; i++) min_since_prev[i] = -1;
    for(int i=1; i<=n; i++){
        prefix[i] =  prefix[i-1];
        int cur = s[i-1]-'A';
        if(min_since_prev[cur] < cur) prefix[i]++;
        for(int c=0; c<26; c++) min_since_prev[c] = min(min_since_prev[c], cur);
        min_since_prev[cur] = cur;
    }

    // Calculate Suffix
    suffix[n+1] = 0;
    for(int i=0; i<26; i++) min_since_prev[i] = -1;
    for(int i=n; i>=1; i--){
        suffix[i] = suffix[i+1];
        int cur = s[i-1]-'A';
        if(min_since_prev[cur]<cur) suffix[i]++;
        for(int c=0; c<26; c++) min_since_prev[c] = min(min_since_prev[c], cur);
        min_since_prev[cur] = cur;
    }

    for(int i=0; i<q; i++){
        int a, b; cin>>a>>b;
        cout<<prefix[a-1]+suffix[b+1]<<endl;
    }
}