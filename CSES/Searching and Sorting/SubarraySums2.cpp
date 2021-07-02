#include <iostream>
#include <set>
#include <map>
using namespace std;
using ll = long long;

void setIO(){
  ios_base::sync_with_stdio(0); cin.tie(0);
}

int main(){
  setIO();
  int n, x; cin>>n>>x;
  int arr[200005];
  for(int i=1; i<=n; i++) cin>>arr[i];
  ll prefix[200005]; prefix[0] = 0;
  map<ll, int> visBefore; visBefore[0] = 1;
  ll ans = 0;
  for(int i=1; i<=n; i++){
    prefix[i] = prefix[i-1] + arr[i];
    ans+=visBefore[prefix[i]-x];
    visBefore[prefix[i]]++;
    //cout<<ans<<" "<<prefix[i]<<endl;
  }
  cout<<ans<<endl;
  return 0;
}