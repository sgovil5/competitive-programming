#include <fstream>
#include <iostream>
#include <string>
using namespace std;
ifstream fin("word.in");
ofstream fout("word.out");

int n,k;

int main(){
  fin>>n>>k;
  string arr[n];
  int length[n];
  for(int i=0; i<n; i++){
    fin>>arr[i];
    length[i] = arr[i].length();
  }
  int lineLength = 0;
  for(int i=0; i<n; i++){
    if(length[i]+lineLength==k){
      fout<<arr[i]<<'\n';
      lineLength=0;
    }
    else if(length[i]+length[i+1]+lineLength>k){
      fout<<arr[i]<<'\n';
      lineLength=0;
    }
    else if(length[i]+length[i+1]+lineLength==k){
      fout<<arr[i]<<" ";
      lineLength += length[i]; 
    }
    else{
      fout<<arr[i]<<" ";
      lineLength+=length[i];
    }
  }
}
