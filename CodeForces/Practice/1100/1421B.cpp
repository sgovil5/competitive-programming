
#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int t;
    cin >> t;
    while(t--){
        int n,ans=0;
        cin >> n;
        string s[n+5];
        vector< pair<int,int> >vp;
        for(int i=0;i<n;i++){
            cin >> s[i];
        }
        if(s[0][1]=='0' && s[1][0]=='0'){
            if(s[n-2][n-1]=='0'){
                ans++;
                vp.push_back({n-1,n});
            }
            if(s[n-1][n-2]=='0'){
                ans++;
                vp.push_back({n,n-1});
            }
        }
        else if(s[0][1]=='1' && s[1][0]=='1'){
            if(s[n-2][n-1]=='1'){
                ans++;
                vp.push_back({n-1,n});
            }
            if(s[n-1][n-2]=='1'){
                ans++;
                vp.push_back({n,n-1});
            }
        }
        else if(s[0][1]=='0' && s[1][0]=='1'){
            if(s[n-2][n-1]=='1' && s[n-1][n-2]=='1'){
                ans++;
                vp.push_back({2,1});
            }
            else if(s[n-2][n-1]=='0' && s[n-1][n-2]=='0'){
                ans++;
                vp.push_back({1,2});
            }
            else if(s[n-2][n-1]=='0'){
                ans+=2;
                vp.push_back({2,1});
                vp.push_back({n-1,n});
            }
            else if(s[n-2][n-1]=='1'){
                ans+=2;
                vp.push_back({1,2});
                vp.push_back({n-1,n});
            }
        }
        else if(s[0][1]=='1' && s[1][0]=='0'){
            if(s[n-2][n-1]=='1' && s[n-1][n-2]=='1'){
                ans++;
                vp.push_back({1,2});
            }
            else if(s[n-2][n-1]=='0' && s[n-1][n-2]=='0'){
                ans++;
                vp.push_back({2,1});
            }
            else if(s[n-2][n-1]=='0'){
                ans+=2;
                vp.push_back({1,2});
                vp.push_back({n-1,n});
            }
            else if(s[n-2][n-1]=='1'){
                ans+=2;
                vp.push_back({2,1});
                vp.push_back({n-1,n});
            }
        }
        cout << ans << endl;
        for(int i=0;i<ans;i++){
            cout << vp[i].first << " " << vp[i].second << endl;
        }
    }
    return 0;
}
