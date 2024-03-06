#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n; cin>>n;
    string s; cin>>s;
    string t = s;
    if(s[0] > s[s.length()-1]) {
        //reverse the string
        reverse(s.begin(), s.end());
        cout<<s+t<<endl;
    }
    else cout<<s<<endl;

}

int main() {
    int t; cin>>t;
    while(t--) {
        solve();
    }
}