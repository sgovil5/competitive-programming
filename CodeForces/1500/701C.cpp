#include <iostream>
#include <map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int n, ans;
string s;
set<char> chars;
map<char, int> vis;

int main(){
    cin>>n>>s;
    for(char c: s) chars.insert(c);
    
    ans = n;
    for(int i=0, j=0; i<n; i++){
        while(j<n && vis.size()<chars.size()){
            vis[s[j]]++;
            j++;
        }

        if(vis.size()==chars.size()){
            ans = min(ans, j-i);
        }

        if(--vis[s[i]]==0){
            vis.erase(s[i]);
        }
    }

    cout<<ans<<endl;
}