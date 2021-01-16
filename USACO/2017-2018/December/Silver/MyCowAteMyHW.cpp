#include <bits/stdc++.h>
using namespace std;
ifstream fin("homework.in");
ofstream fout("homework.out");

int main() {
  int n;
  fin>>n;
  int arr[n];
  for(int i=0; i<n; i++){
    fin>>arr[i];
  }
  // Calculate suffix sums
  int suffix[n+1];
  suffix[n] = 0;
  for(int i=n-1; i>=0; i--){
    suffix[i] = suffix[i+1] + arr[i];
  }
  // Calculate min score from the back
  int mins[n+1];
  mins[n] = 1e9;
  for(int i=n-1; i>=0; i--){
    mins[i] = min(mins[i+1], arr[i]);
  }
  double maxScore = 0;
  vector<double> scores;
  // Calculate score for each possible k and add to list of scores
  for(int k=1; k<=n-2; k++){
    double sum = suffix[k] - suffix[n] - mins[k];
    double div = n-k-1;
    double score = sum/div;
    // Find maxscore
    maxScore = max(maxScore, score);
    scores.push_back(score);
  }
  // Output Ks with maxscores
  for(int i=0; i<scores.size(); i++){
    if(scores[i]==maxScore) fout<<i+1<<endl;
  }
}
