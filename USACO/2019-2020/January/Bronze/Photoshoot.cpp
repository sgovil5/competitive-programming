#include <bits/stdc++.h>
using namespace std;
ifstream fin("photo.in");
ofstream fout("photo.out");

int main(){
  int n;
  fin>>n;
  int arr[n-1];
  for(int i=0; i<n-1; i++) fin>>arr[i];
  bool done = false;
  for(int start=1; start<=n; start++){
    set<int> numSet;
    vector<int> numVect;
    numSet.insert(start);
    numVect.push_back(start);
    for(int i=0; i<n-1; i++){
      int num = arr[i] - numVect[i];
      if(num<=0) break;
      else{
        numSet.insert(num);
        numVect.push_back(num);
      }
    }
    if(numSet.size()==n){
      done = true;
      for(int i=0; i<n-1; i++){
        fout<<numVect[i]<<" ";
      }
      fout<<numVect[n-1];
    }
    if(done) break;
  }
}
