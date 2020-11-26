#include <bits/stdc++.h>
using namespace std;
ifstream fin("lineup.in");
ofstream fout("lineup.out");
int n;
vector<pair<string, string>> s;
string names[8] = { "Beatrice", "Belinda","Bella" , "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};

int find(string element){
  int ans;
  for(int i=0; i<8; i++){
    if(names[i]==element) ans = i;
  }
  return ans;
} 

bool check(){
  bool ans = true;
  for(int i=0; i<n; i++){
    string a = s[i].first;
    string b = s[i].second;
    int index = find(b);
    if(index==0){
      if(!(names[index+1]==a)) ans = false;
    }
    else if(index==7){
      if(!(names[index-1]==a)) ans = false;
    }
    else if(!(names[index-1]==a||names[index+1]==a)) ans = false;
  }
  return ans;
}

int main() {
	fin >> n;
	for (int i = 0; i < n; i++) {
		string a, r1, r2, r3, r4, b;
		fin >> a >> r1 >> r2 >> r3 >> r4 >> b;
		s.push_back(make_pair(a, b));
	}
	do {
    if(check()) break;
	} while (next_permutation(names, names+8));
  for(int i=0; i<8; i++){
    fout<<names[i]<<endl;
  }
}
