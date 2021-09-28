#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Friend{
  int h, w, i;
};

bool cmp(Friend& a, Friend& b){
    if(a.h==b.h) return a.w>b.w;
    return a.h<b.h;
}

int t;

void solve(){
    int n; cin>>n;
    vector<Friend> v;
    for(int i=0; i<n; i++){
        int height, weight; cin>>height>>weight;
        if(weight > height) swap(height, weight);
        v.push_back({height, weight, i+1});
    }
    sort(begin(v), end(v), cmp);

    vector<int> overlap(n+1, -1);
    int currI = v[0].i, currW = v[0].w;
    
    for(int j=1; j<n; j++){
        if(v[j].w > currW){
            overlap[v[j].i] = currI;
        }
        else{
            currI = v[j].i;
            currW = v[j].w;
        }
    }

    for(int i=1; i<=n; i++) cout<<overlap[i]<<" ";
    cout<<endl;
}

int main(){
    cin>>t;
    while(t--){
        solve();
    }
}