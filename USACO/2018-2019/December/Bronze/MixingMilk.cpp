#include <iostream>
#include <cstdio>
using namespace std;
int main(){
  // freopen("shell.in", "r", stdin);
  // freopen("shell.out", "w", stdout);
  int c1,m1,c2,m2,c3,m3;
  cin>>c1>>m1>>c2>>m2>>c3>>m3;
  int currBucket = 0;
  for(int i=0; i<100; i++){
    if(currBucket%3==0){
      if(c1+c2>m2){
        int amtPoured = m2 - c2;
        c2 = m2;
        c1-=amtPoured;
      }
      else{
        c2+=c1;
        c1 = 0;
      }
    }
    else if(currBucket%3==1){
      if(c2+c3>m3){
        int amtPoured = m3 - c3;
        c3 = m3;
        c2-=amtPoured;
      }
      else{
        c3+=c2;
        c2 = 0;
      }
    }
    else if(currBucket%3==2){
      if(c3+c1>m1){
        int amtPoured = m1 - c1;
        c1 = m1;
        c3-=amtPoured;
      }
      else{
        c1+=c3;
        c3 = 0;
      }
    }
    currBucket++;
  }
  cout<<c1<<endl;
  cout<<c2<<endl;
  cout<<c3<<endl;
}
