#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

void setIO(string fileName = "") {
	ios_base::sync_with_stdio(0); cin.tie(0);
	if((int)fileName.size()) {
		freopen((fileName+".in").c_str(), "r", stdin);
		freopen((fileName+".out").c_str(), "w", stdout);
	}
}

using Cow = pair<int, pair<int,int>>; // seniority, arrival, duration

int n;
vector<Cow> v; 

int main(){
    setIO("convention2");
    cin>>n;
    for(int i=n; i>0; i--){
        int a, t; cin>>a>>t;
        v.push_back({i, {a, t}});
    }
    v.push_back({0, {(int) 2e9, 0}});

    #define arrival second.first
    #define time second.second
    #define seniority first

    sort(begin(v), end(v), [&](const Cow a,const Cow b){
        if(a.arrival==b.arrival) return a.seniority<b.seniority;
        else return a.arrival < b.arrival;
    });

    int currTime=0, maxWait=0; 
    priority_queue<Cow> q;
    for(int i=0; i<n; ){
        Cow curr = v[i];
        if(curr.arrival > currTime && q.empty()){
            currTime = curr.arrival + curr.time;
            i++;
        }
        else if(curr.arrival > currTime){
            Cow top = q.top();
            q.pop();

            maxWait = max(maxWait, currTime-top.arrival);

            currTime += top.time;
        }
        else{
            q.push(curr);
            i++;
        }
    }

    cout<<maxWait;
}