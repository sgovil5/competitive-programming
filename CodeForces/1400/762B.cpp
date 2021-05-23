#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

#define f first
#define s second

int a,b,c; //USB, PS/2, Both
int m; //num mouses
vector<pair<int,string>> mouses;

int main(){
    cin>>a>>b>>c>>m;
    for(int i=0; i<m; i++){
        int val;
        string port;
        cin>>val>>port;
        mouses.push_back({val,port});
    }
    sort(begin(mouses), end(mouses));

    long long count = 0, cost = 0;
    for(int i=0; i<m; i++){
        if(mouses[i].s=="USB"){
            if(a>0){
                count++;
                cost+=mouses[i].f;
                a--;
            }
            else if(c>0){
                count++;
                cost+=mouses[i].f;
                c--;
            }
        }
        else if(mouses[i].s=="PS/2"){
            if(b>0){
                count++;
                cost+=mouses[i].f;
                b--;
            }
            else if(c>0){
                count++;
                cost+=mouses[i].f;
                c--;
            }
        }
    }

    cout<<count<<" "<<cost<<endl;
    return 0;
}