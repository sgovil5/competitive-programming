#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int k; string s;
vector<int> spaces;

bool check(int w){
    int start = 1, lines = 1, curr = 0;
    for(int i=0; i<spaces.size(); i++){
        if(spaces[i]-start+1>w){
            lines++;
            start = curr+1;
            curr = spaces[i];
        } else{
            curr = spaces[i];
        }
    }
    return lines<=k;
}

int firstTrue(int lo, int hi) {
	for (hi ++; lo < hi; ) {
		int mid = lo+(hi-lo)/2;
		if (check(mid)) hi = mid;
		else lo = mid+1;
	}
	return lo;
}

int main(){
    cin>>k; cin.ignore(1000, '\n');
    getline(cin, s);
    for(int i=1; i<=s.length(); i++){
        if(s[i-1]==' '||s[i-1]=='-') spaces.push_back(i);
    }
    spaces.push_back(s.length());

    int max_dist = spaces[0];
    for(int i=1; i<spaces.size(); i++){
        max_dist = max(max_dist, spaces[i]-spaces[i-1]);
    }
    cout<<firstTrue(max_dist, 1e6);
    return 0;
}