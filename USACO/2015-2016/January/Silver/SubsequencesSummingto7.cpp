#include <bits/stdc++.h>
using namespace std;
ifstream fin("div7.in");
ofstream fout("div7.out");

using ll = long long;

struct Num{
  bool found1, found2;
  int minInd, maxInd;
};

int n;
vector<Num> nums;

int main(){
  //Input and create prefix array
  fin>>n;
  vector<int> v(n+1);
  v[0] = 0;
  for(int i=1; i<=n; i++){
    int x; fin>>x;
    v[i] = (v[i-1]+x)%7;
  }
  // Create nums array
  for(int i=0; i<7; i++){
    nums.push_back({false, false, n, 0});
  }
  // Calculate nums array
  for(int i=0; i<=n; i++){
    int currNum = v[i];
    if(nums[currNum].found1) nums[currNum].found2 = true;
    nums[currNum].found1 = true;
    nums[currNum].minInd = min(nums[currNum].minInd, i);
    nums[currNum].maxInd = max(nums[currNum].maxInd, i);
  }
  // Calculate answer
  int ans  = 0;
  for(int i=0; i<7; i++){
    if(nums[i].found2){
      ans = max(nums[i].maxInd - nums[i].minInd, ans);
    }
  }
  fout<<ans;
}
