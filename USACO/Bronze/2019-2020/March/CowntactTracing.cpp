#include <bits/stdc++.h>
#define pb push_back
using namespace std;
ifstream fin("tracing.in");
ofstream fout("tracing.out");



struct Interaction{
  int time, c1,c2;
};

int n,t;
vector<Interaction> v;
string sick;

int main(){
  fin>>n>>t;
  fin>>sick;
  //Change string to int arr
  int sickCows[n+1];
  for(int i=1; i<=n; i++){
    sickCows[i] = sick[i-1]-'0';
  }
  //input and sorting
  for(int i=0; i<t; i++){
    int a,b,c;
    fin>>a>>b>>c; //time,c1,c2
    v.pb({a,b,c});
  }
  sort(begin(v),end(v),[](const Interaction&a, const Interaction&b){return a.time<b.time;});
  //Simulate each K
  vector<int> possibleK;
  set<int> starts;
  int numStart = 0;
  for(int k=0; k<=251; k++){
    //simulate each initialCow
    for(int initialCow=1; initialCow<=n; initialCow++){
      int infected[102]={0};
      int numHandshakes[102]={0};
      infected[initialCow] = 1;
      //Go through each interaction 
      for(int i=0; i<t; i++){
        int cow1 = v[i].c1;
        int cow2 = v[i].c2;
        if(infected[cow1]) numHandshakes[cow1]++;
        if(infected[cow2]) numHandshakes[cow2]++;
        if(infected[cow1]==1&&numHandshakes[cow1]<=k){
          infected[cow2] = 1;
        }
        if(infected[cow2]==1&&numHandshakes[cow2]<=k){
          infected[cow1] = 1;
        }
      }
      //Check if infected in simulation is equal to acutal list of infected cows
      bool same = true; 
      for(int i=1; i<=n; i++){
        if(infected[i]!=sickCows[i]) same = false;
      }
      if(same){
        possibleK.pb(k);
        starts.insert(initialCow);
      }
    }
  }
  for(int elem: starts){
    numStart++;
  }
  int minK = possibleK[0];
  int maxK = possibleK[possibleK.size()-1];
  if(maxK==251){
    fout<<numStart<<" "<<minK<<" "<<"Infinity";
  }
  else{
    fout<<numStart<<" "<<minK<<" "<<maxK;
  }
}
