#include <iostream>
#include <map>
#include <string>
using namespace std;

#define int long long

signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string x; cin>>x;
        int arr[100005], prefix[100005];
        for(int i=1; i<=n; i++){
            arr[i] = x[i-1]-'0';
        }

        prefix[0] = 0;
        for(int i=0; i<=n; i++){
            prefix[i] = prefix[i-1]+arr[i];
        }

        map<int, int> val; //value, count
        val[0] = 1;
        for(int i=1; i<=n; i++){
            val[prefix[i]-i]++;
        }

        int ans = 0;

        for(auto p: val){
            //cout<<p.first<<" "<<p.second<<endl;
            ans += (p.second*(p.second-1))/2;
        }   

        cout<<ans<<endl;
    }
}