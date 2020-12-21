#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n,t;
  cin>>n>>t;
  long long arr[n];
  long long prefix[n+1];
  prefix[0] = 0;
  for(long long i=0; i<n; i++){
    cin>>arr[i];
    prefix[i+1]=arr[i]+prefix[i];
  }
  multiset<long long> valuesBefore;
  long long sums = 0;
  for(long long i=0; i<=n; i++){
    sums+=valuesBefore.count(prefix[i]-t);
    valuesBefore.insert(prefix[i]);
  }
  cout<<sums;
}
