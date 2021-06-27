#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  int a[n], b[n];
  for(int i=0; i<n; i++) cin>>a[i];
  for(int i=0; i<n; i++) cin>>b[i];
  sort(a, a+n), sort(b, b+n);
  vector<int> fit(n);
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(a[j]<=b[i]) fit[i]++;
    }
  }
  long long ans = 1;
  for(int i=0; i<n; i++){
    ans*=fit[i]-i;
  }
  cout<<ans;
}
