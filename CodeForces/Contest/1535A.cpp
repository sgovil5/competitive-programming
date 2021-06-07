#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int t;
int main(){
    cin>>t;
    while(t--){
        bool fair = true;
        int a,b,c,d; cin>>a>>b>>c>>d;
        int win1 = max(a,b);
        int win2 = max(c,d);
        if(win1<c && win1<d) fair = false;
        else if(win2<a && win2<b) fair = false;
        cout<<(fair ? "YES" : "NO")<<endl;
    }
    return 0;
}