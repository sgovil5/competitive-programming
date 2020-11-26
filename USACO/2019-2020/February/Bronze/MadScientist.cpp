#include <fstream>
#include <string>
using namespace std;
ifstream fin("breedflip.in");
ofstream fout("breedflip.out");

int main(){
  int n;
  fin>>n;
  string s1,s2;
  fin>>s1>>s2;
  int flips=0;
  for(int i=1; i<n; i++){
    if(s1[i-1]!=s2[i-1]&&s1[i]==s2[i]) flips++;
  }
  fout<<flips;
}
