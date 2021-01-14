#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m;
  cin>>n>>m;
  multiset<int> prices;
  for(int i=0; i<n; i++){
    int x;
    cin>>x;
    prices.insert(x);
  }
  for(int i=0; i<m; i++){
    int t;
    cin>>t;
    auto price = prices.upper_bound(t);
    if(price==prices.begin()) cout<<-1<<endl;
    else{
      cout<<*prev(price)<<endl;
      prices.erase(prices.find(*prev(price)));
    }
  }
}
