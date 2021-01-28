#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,k,q;
  cin>>n>>k>>q;
  const int MXN = 200005;
  int arr[MXN];
  for(int i=0; i<MXN; i++) arr[i] = 0;
  for(int i=0; i<n; i++){
    int l,r;
    cin>>l>>r;
    arr[l]++;
    arr[r+1]--;
  }
  int prefix[MXN+1];
  for(int i=0; i<=MXN; i++) prefix[i] = 0;
  for(int i=1; i<=MXN; i++){
    prefix[i]=prefix[i-1]+arr[i];
  }
  int admissible[MXN+1];
  for(int i=0; i<=MXN; i++) admissible[i] = 0;
  for(int i=1; i<=MXN; i++){
    admissible[i]+=admissible[i-1];
    if(prefix[i]>=k) admissible[i]++;
  }
  for(int i=0; i<q; i++){
    int a,b;
    cin>>a>>b;
    cout<<admissible[b]-admissible[a-1]<<endl;
  }
}
