#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("moobuzz.in");
ofstream fout("moobuzz.out");
int main() {
  long long n;
  fin>>n;
  long long arr[8] = {1,2,4,7,8,11,13,14};
  long long ans;
  if(n%8==0){
    ans= 15*(n%8)-1;
  }
  else{
    long long mult = n/8;
    long long add = n%8;
    ans = 15*mult + arr[add-1];
  }
  fout<<ans;
}
