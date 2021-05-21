#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

using ll = long long;
#define f first
#define s second

int n;
vector<pair<int,int>> tasks; // time, deadline

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        int a,d; cin>>a>>d;
        tasks.push_back({a,d});
    }
    sort(begin(tasks), end(tasks));

    ll reward = 0, currTime = 0;
    for(int i=0; i<n; i++){
        currTime+=tasks[i].f;
        reward+=tasks[i].s-currTime;
    }

    cout<<reward<<endl;
}