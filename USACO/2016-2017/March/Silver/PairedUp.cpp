#include <bits/stdc++.h>
using namespace std;
ifstream fin("pairup.in");
ofstream fout("pairup.out");

#define f first
#define s second

int main(){
  int n;
  fin>>n;
  vector<pair<int,int>> cows; //time, numCows
  for(int i=0; i<n; i++){
    int x,y;
    fin>>x>>y;
    cows.push_back({y,x});
  }
  //sort to pair smallest with largest times
  sort(begin(cows), end(cows));
  int left = 0, right = n-1;
  int maxTime = 0;
  //two pointers 
  while(right>left){
    //calculate maximum time by looking and left and right pointers
    maxTime = max(maxTime, cows[right].f + cows[left].f);
    // subtract any redundant cows after calculation and move to next pointers
    int cowsUsed = min(cows[right].s, cows[left].s);
    cows[right].s-=cowsUsed, cows[left].s-=cowsUsed;
    if(cows[right].s==0)right--;
    if(cows[left].s==0) left++;
  }
  fout<<maxTime;
}
