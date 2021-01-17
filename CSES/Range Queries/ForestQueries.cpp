#include <bits/stdc++.h>
using namespace std;

int n,q;

int main() {
  cin>>n>>q;
  char a[n+1][n+1];
  for(int i=1; i<=n; i++){
    for(int j=1;j<=n; j++){
      cin>>a[i][j];
    }
  }
  int prefix[n+1][n+1];
  for(int i=0; i<=n; ++i) prefix[0][i] = 0, prefix[i][0] = 0;
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
      if(a[i][j]=='*') prefix[i][j]++;
    }
  }
  for(int i=0; i<q; i++){
    int a,b,A,B;
    cin>>a>>b>>A>>B;
    int sum = prefix[A][B] - prefix[a-1][B] - prefix[A][b-1] + prefix[a-1][b-1];
    cout<<sum<<endl;
  }
}
