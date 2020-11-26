#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("lemonade.in");
ofstream fout("lemonade.out");

int main(){
  int n;
  fin>>n;
  int arr[n];
  for(int i=0; i<n; i++){
    fin>>arr[i];
  }
  sort(arr,arr+n);
  int numCows = 0;
  for(int i=n-1; i>=0; i--){
    if(arr[i]>=numCows) numCows++;
    else break;
  }
  fout<<numCows;
}
