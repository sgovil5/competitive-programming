#include <bits/stdc++.h>
using namespace std;

struct Customer{
  int l,r;
};

bool cmp (const Customer& a, const Customer& b) {
  return a.l < b.l;
}

int n;
map<int, bool> m; //true for enter, false for exit

int main() {
  cin>>n;
  for(int i=0; i<n; i++){
    int a,b;
    cin>>a>>b;
    m[a] = true;
    m[b] = false;
  }
  int maxCustomers = 0;
  int currCustomers = 0;
  for(auto elem: m){
    if(elem.second==true) currCustomers++;
    else currCustomers--;
    maxCustomers = max(maxCustomers, currCustomers);
  }
  cout<<maxCustomers;
}
