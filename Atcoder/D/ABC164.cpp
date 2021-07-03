#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
using ll = long long;

int main(){
    string s; cin>>s;
    int n = s.size();

    vector<ll> arr(n+1), prefix(n+1); prefix[0] = 0;
    for(int i=n; i>0; i--){
        arr[i] = s[n-i]-'0';
    }

    ll factor = 1, ans = 0;
    map<ll, ll> visBefore; //num, visCount
    visBefore[0] = 1;
    for(int i=1; i<=n; i++){
        factor = (factor*10)%2019;
        prefix[i] = (prefix[i-1] + factor*arr[i])%2019;
        ans+=visBefore[prefix[i]];
        visBefore[prefix[i]]++;
    }
    cout<<ans<<endl;
    return 0;
}