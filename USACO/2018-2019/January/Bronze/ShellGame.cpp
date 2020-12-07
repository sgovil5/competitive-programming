#include <bits/stdc++.h>
using namespace std;
ifstream fin("shell.in");
ofstream fout("shell.out");

int n;
int a[101],b[101],g[101];

int main(){
  bool start[3] = {false,false,false};
  fin>>n;
  for(int i=0; i<n; i++){
    fin>>a[i]>>b[i]>>g[i];
  }
  int maxGuess = 0;
  for(int s = 0; s<3; s++){
    fill(start, start+3, false);
    start[s] = true;
    int correct = 0;
    for(int i=0; i<n; i++){
      swap(start[a[i]-1], start[b[i]-1]);
      if(start[g[i]-1]) correct++;
    }
    maxGuess = max(maxGuess, correct);
  }
  fout<<maxGuess;
}
