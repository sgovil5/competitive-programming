#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n, q;
string s;

int main(){
    cin>>n>>s>>q;
    
    for(int tc=0; tc<q; tc++){
        int m; char c; cin>>m>>c;

        int left = 0, right = 0, ans = 0;

        while(left<n && right<n){
            while(right<n){
                if(s[right]!=c){
                    if(m==0) break;
                    m--;
                }
                right++;
            }
            ans = max(ans, right-left);
            if(s[left++]!=c) m++;
        }
        cout<<ans<<endl;
    }
    return 0;
}