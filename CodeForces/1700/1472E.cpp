#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

using ll = long long;

struct Friend{
    ll h,w,i; //height, width, index
};

bool cmp(Friend& a, Friend& b){
    if(a.h==b.h) return a.w>b.w;
    else return a.h<b.h;
}

void solve(){
    int n; cin>>n;
    vector<Friend> friends; 

    for(int i=0; i<n; i++){
        int height,width; cin>>height>>width;
        if(height<width) swap(height,width);
        friends.push_back({height,width,i});
    }
    sort(begin(friends), end(friends), cmp);

    vector<int> ans(n, -1);

    int currI = friends[0].i, currW = friends[0].w;
    for(int i=1; i<n; i++){
        if(friends[i].w>currW){
            ans[friends[i].i] = currI+1;
        }
        else{
            currI = friends[i].i; 
            currW = friends[i].w;
        }
    }

    for(int i=0; i<n; i++) cout<<ans[i]<<" ";
    cout<<endl;
}

int main(){
    int t; cin>>t;
    for(int i=0; i<t; i++){
        solve();
    }
}