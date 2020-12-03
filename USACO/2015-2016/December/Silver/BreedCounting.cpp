#include <bits/stdc++.h>
using namespace std;
ifstream fin("bcount.in");
ofstream fout("bcount.out");

int main(){
  int n,q;
  fin>>n>>q;
  int p1[n+1],p2[n+1],p3[n+1];
  p1[0] = 0, p2[0] = 0, p3[0] = 0;
  for(int i=1; i<=n; i++){
    int x;
    fin>>x;
    p1[i]=p1[i-1];
    p2[i]=p2[i-1];
    p3[i]=p3[i-1];
    if(x==1) p1[i]++;
    else if(x==2) p2[i]++;
    else p3[i]++;
  }
  for(int i=0; i<q; i++){
    int a,b;
    fin>>a>>b;
    fout<<p1[b]-p1[a-1]<<" "<<p2[b]-p2[a-1]<<" "<<p3[b]-p3[a-1]<<endl;
  }
}
