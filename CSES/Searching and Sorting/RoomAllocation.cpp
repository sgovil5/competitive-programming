#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <algorithm>
using namespace std;

#define f first
#define s second

int n;
int ans[200005];
vector<pair<pair<int,int>,int>> v; //arrival, departure, og index

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        v.push_back({{a,b},i});
    }
    sort(begin(v), end(v));

    priority_queue<pair<int,int>> pq; //departure, room number
    int lastRoom = 0; //lastRoom represents the max room that has been used
    for(int i=0; i<n; i++){
        if(pq.empty()){
            lastRoom++;
            /*
                We have to use a negative in the pq
                because pq only finds the max, and we need to 
                reverse it. We also add the current room being used
                so that we can calculate what rooms will be used
                for future visitors
            */
            pq.push({-v[i].f.s, lastRoom});
            // ans of the original index is what the current room is
            ans[v[i].s] = lastRoom;
        }
        else{
            // Room that becomes empty the first
            pair<int,int> minTime = pq.top();
            // We need to take the negative to counter the way we inserted stuff
            // This is in the case that the room gets empty before the next visitor
            if(-minTime.f<v[i].f.f){
                pq.pop();
                pq.push({-v[i].f.s, minTime.s});
                ans[v[i].s] = minTime.s;
            }
            // This is in the case that we need to add a new room
            else{
                lastRoom++;
                pq.push({-v[i].f.s, lastRoom});
                ans[v[i].s] = lastRoom;
            }
        }
    }
    
    cout<<lastRoom<<endl;
    for(int i=0; i<n; i++) cout<<ans[i]<<" ";
}