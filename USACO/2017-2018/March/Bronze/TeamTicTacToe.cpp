#include <bits/stdc++.h>
using namespace std;
ifstream fin("tttt.in");
ofstream fout("tttt.out");

int main(){
  string grid[3];
  for(int i=0; i<3; i++){
    fin>>grid[i];
  }
  set<char> winners;
  set<pair<char,char>> teamWinners;
  /*XXX
    OOO
    OOO*/
  for(int i=0; i<3; i++){
    set<char> usedLetters;
    for(int j=0; j<3; j++){
      usedLetters.insert(grid[i][j]);
    }
    if(usedLetters.size()==1){
      winners.insert(*usedLetters.begin());
    }
    else if(usedLetters.size()==2){
      teamWinners.insert({*usedLetters.begin(),*usedLetters.rbegin()});
    }
  }
  /*XOO
    XOO
    XOO*/
  for(int i=0; i<3; i++){
    set<char> usedLetters;
    for(int j=0; j<3; j++){
      usedLetters.insert(grid[j][i]);
    }
    if(usedLetters.size()==1){
      winners.insert(*usedLetters.begin());
    }
    else if(usedLetters.size()==2){
      teamWinners.insert({*usedLetters.begin(),*usedLetters.rbegin()});
    }
  }
  /*XOO
    OXO
    OOX*/
  set<char> diag1Letters;
  diag1Letters.insert(grid[0][0]),diag1Letters.insert(grid[1][1]),diag1Letters.insert(grid[2][2]);
  if(diag1Letters.size()==1){
    winners.insert(*diag1Letters.begin());
  }
  else if(diag1Letters.size()==2){
    teamWinners.insert({*diag1Letters.begin(),*diag1Letters.rbegin()});
  }
  /*OOX 
    OXO 
    XOO*/
  set<char> diag2Letters;
  diag2Letters.insert(grid[0][2]),diag2Letters.insert(grid[1][1]),diag2Letters.insert(grid[2][0]);
  if(diag1Letters.size()==1){
    winners.insert(*diag1Letters.begin());
  }
  else if(diag1Letters.size()==2){
    teamWinners.insert({*diag1Letters.begin(),*diag1Letters.rbegin()});
  }
  fout<<winners.size()<<"\n"<<teamWinners.size();
}
