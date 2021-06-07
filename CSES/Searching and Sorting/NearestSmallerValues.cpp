#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

#define f first
#define s second
typedef pair<int,int> pii;

int n;
int main(){
    cin>>n;
    stack<pii> s;
    s.push({0,0}); //value, index
    for(int i=1; i<=n; i++){
        int x; cin>>x;
        while(!s.empty() && s.top().f>=x) s.pop();
        cout<<s.top().s<<" ";
        s.push({x,i});
    }
}