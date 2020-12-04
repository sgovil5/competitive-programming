#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;
ifstream fin("angry.in");
ofstream fout("angry.out");
int n;
int arr[101];
bool exploded[101] = {false};

void left(int start){
  int r = 1;
  int fstart = start;
  for(int i=fstart-1; i>=0; i--){
    int original_start = start;
    for(int j=0; j<=i; j++){
      if(arr[start]-arr[j]<=r){
        fill(exploded+j,exploded+start+1, true);
        start = j;
        break;
      }
    }
    if (original_start == start) // we can't explode any more haybales
      return;
    r++;
  }
}

void right(int start){
  int r = 1;
  int fstart = start;
  for(int i=fstart+1; i<n; i++){
    int original_start = start;
    for(int j=n-1; j>=i; j--){
      if(arr[j]-arr[start]<=r){
        fill(exploded+start,exploded+j+1, true);
        start = j;
        break;
      }
    }
    if (original_start == start) // we can't explode any more haybales
      return;
    r++;
  }
}

int main(){
  fin>>n;
  for(int i=0; i<n; i++){
    fin>>arr[i];
  }
  sort(arr,arr+n);
  // for(int i=0; i<n; i++){
  //   cout<<arr[i]<<endl;
  // }
  int mblast = 0;
  for(int start = 0; start<n; start++){
    fill(exploded, exploded+n, false);
    exploded[start] = true;
    left(start);
    right(start);
    int ctr=0;
    for(int i=0; i<n; i++){
      if(exploded[i]) ctr++;
      cout<<exploded[i]<<" ";
    }
    cout<<endl<<endl;
    mblast = max(mblast,ctr);
  }
  fout<<mblast;
}
