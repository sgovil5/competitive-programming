#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;

#define int long long

#define f first
#define s second

int n;
vector<pair<int, pair<int, int>>> v; //index, start, end
priority_queue<pair<int, int>> q; //time, room
map<int, int> m; //index, room no.

bool cmp(pair<int, pair<int, int>>& a, pair<int, pair<int, int>>& b){
    if(a.s.f==b.s.f) return a.s.s<b.s.s;
    return a.s.f<b.s.f;
}

signed main(){
    cin>>n;
    for(int i=0; i<n; i++){
        int a,b; cin>>a>>b;
        v.push_back({i, {a,b}});
    }
    sort(begin(v), end(v), cmp);
    
    int rooms = 0, lastRoom = 0;
    for(int i=0; i<n; i++){
        if(q.empty()){
            lastRoom++;
            q.push({-v[i].s.s, lastRoom});
            m[v[i].f]=lastRoom;
        }
        else{
            if(v[i].s.f<=-q.top().f){
                lastRoom++;
                q.push({-v[i].s.s, lastRoom});
                m[v[i].f] = lastRoom;
            }
            else{
                int curRoom = q.top().s; 
                q.pop();
                q.push({-v[i].s.s, curRoom});
                m[v[i].f] = curRoom;
            }
        }
        rooms = max(rooms, lastRoom);     
    }

    cout<<rooms<<endl;
    for(int i=0; i<n; i++){
        cout<<m[i]<<" ";
    }
}