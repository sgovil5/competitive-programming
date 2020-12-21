#include <bits/stdc++.h>
using namespace std;
ifstream fin("hps.in");
ofstream fout("hps.out");

int n;
int p[100003], h[100003], s[100003];

int main() {
  fin>>n;
  p[0] = 0, s[0] = 0, h[0]=0;
  for(int i=0; i<n; i++){
    p[i+1] = p[i], s[i+1] = s[i], h[i+1] = h[i];
    char c;
    fin>>c;
    if(c=='H') h[i+1]++;
    else if(c=='P') p[i+1]++;
    else if(c=='S') s[i+1]++;
  }
  int maxWins = 0;
  for(int i=1; i<n; i++){ //Start H then P
    int wins = 0;
    //H beats S
    wins += s[i] - s[0];
    //P beats H
    wins+= h[n] - h[i];
    maxWins = max(wins, maxWins);
  }
  for(int i=1; i<n; i++){ //Start H then S
    int wins = 0;
    //H beats S
    wins += s[i] - s[0];
    //S beats P
    wins+= p[n] - p[i];
    maxWins = max(wins, maxWins);
  }
  for(int i=1; i<n; i++){ //Start H then H
    int wins = 0;
    //H beats S
    wins += s[i] - s[0];
    //H beats S
    wins+= s[n] - s[i];
    maxWins = max(wins, maxWins);
  }
  for(int i=1; i<n; i++){ //Start P then S
    int wins = 0;
    //P beats H
    wins += h[i] - h[0];
    //S beats P
    wins+= p[n] - p[i];
    maxWins = max(wins, maxWins);
  }
  for(int i=1; i<n; i++){ //Start P then H
    int wins = 0;
    //P beats H
    wins += h[i] - h[0];
    //H beats S
    wins+= s[n] - s[i];
    maxWins = max(wins, maxWins);
  }
  for(int i=1; i<n; i++){ //Start P then P
    int wins = 0;
    //P beats H
    wins += h[i] - h[0];
    //P beats H
    wins+= h[n] - h[i];
    maxWins = max(wins, maxWins);
  }
  for(int i=1; i<n; i++){ //Start S then P
    int wins = 0;
    //S beats P
    wins += p[i] - p[0];
    //P beats H
    wins+= h[n] - h[i];
    maxWins = max(wins, maxWins);
  }
  for(int i=1; i<n; i++){ //Start S then H
    int wins = 0;
    //S beats P
    wins += p[i] - p[0];
    //H beats S
    wins+= s[n] - s[i];
    maxWins = max(wins, maxWins);
  }
  for(int i=1; i<n; i++){ //Start S then S
    int wins = 0;
    //S beats P
    wins += p[i] - p[0];
    //S beats P
    wins+= p[n] - p[i];
    maxWins = max(wins, maxWins);
  }
  fout<<maxWins;
}
