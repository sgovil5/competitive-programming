#include <iostream>
#include <set> 
#include <algorithm>
#include <vector>
using namespace std;
 
struct Time{
    int a,b;
};
 
bool cmp(const Time& x, Time&y){
    if(x.b==y.b) return x.a<y.a;
    return x.b<y.b;
}
 
int n,k;
vector<Time> m; //start, end
multiset<int> endTimes;
 
int main(){
    cin>>n>>k;
    for(int i=0; i<n; i++){
        int a,b; cin>>a>>b;
        m.push_back({a,b});
    }
    // Sort by end time
    sort(begin(m), end(m), cmp);
 
    int count = 0;
    for(int i=0;i<k; i++){
        endTimes.insert(0);
    }
 
    for(int i=0; i<n; i++){
        auto it = endTimes.upper_bound(m[i].a);
        if(it!=begin(endTimes)){
            endTimes.erase(prev(it));
            endTimes.insert(m[i].b);
            count++;
        }
    }
    cout<<count;
}