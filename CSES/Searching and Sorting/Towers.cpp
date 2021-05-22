#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int n;
multiset<int> s;

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        int x; cin>>x;
        auto it = s.upper_bound(x);
        // Update the tower if one already exists
        if(it!=s.end()) s.erase(it);
        s.insert(x);
    }
    cout<<s.size();
}