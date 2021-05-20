#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,x;
vector<int> sz;

int main(){
    cin>>n>>x;
    for(int i=0; i<n; i++){
        int p; cin>>p;
        sz.push_back(p);
    }
    sort(begin(sz), end(sz));

    int left = 0, right = n-1;
    int count = 0;
    while(left<=right){
        while(sz[left]+sz[right]>x){
            right--, count++;
        }
        if(left>right) break;
        if(sz[left]+sz[right]<=x){
            right--, left++, count++;
        }
    }
    cout<<count;
}