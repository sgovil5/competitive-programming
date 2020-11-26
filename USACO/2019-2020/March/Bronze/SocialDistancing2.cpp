#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
ifstream fin("socdist2.in");
ofstream fout("socdist2.out");

struct Cow{
  int pos,sick;
};

int n;
vector<Cow> vect;

int main(){
  fin>>n;
  for(int i=0; i<n; i++){
    int x,s;
    fin>>x>>s;
    vect.push_back({x,s});
  }
  sort(begin(vect),end(vect),[](const Cow&x, const Cow&y){return x.pos<y.pos;});
  //Solve for the minimum r;
  int minR = 1e9;
  for(int i=1; i<n; i++){
    if(vect[i].sick==0){
      int r = 1e9;
      if(vect[i+1].sick==1){
        r = vect[i+1].pos -vect[i].pos -1;
      }
      if(vect[i-1].sick==1){
        r = vect[i].pos -vect[i-1].pos -1;
      }
      minR = min(minR,r);
    }
  }
  //Solve for how many cows are initially infected
  int initialCows = 0;
  for(int i=0; i<n; i++){
    if(i==0 && vect[i].sick==1){
      initialCows++;
    }
    else if(vect[i].sick==1){
      if(vect[i-1].sick==0){
        initialCows++;
      }
      else if(vect[i].pos-vect[i-1].pos>minR) initialCows++;
    }
  }
  fout<<initialCows;
}
