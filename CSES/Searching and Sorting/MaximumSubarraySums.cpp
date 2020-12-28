#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n;
  cin>>n;
  long long prefix[n+1];
  prefix[0] = 0;
  for(long long i=1; i<=n; i++){
    prefix[i] = prefix[i-1];
    long long x;
    cin>>x;
    prefix[i]+=x;
  }
  long long minVal = 0;
  long long maxSum = INT_MIN;
  for(int i=1; i<=n; i++){
    maxSum = max(maxSum, prefix[i]-minVal);
    minVal = min(minVal, prefix[i]);
  }
  cout<<maxSum;
}
