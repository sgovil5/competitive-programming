#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

int gcdc(int a, int b){
    if(b==0) return a;
    return gcdc(b, a%b);
}

int t;
int main(){
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> v(n);
        for(int i=0; i<n; i++){
            cin>>v[i];
        }
        sort(begin(v), end(v));
        int count = 0;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(gcdc(v[i], 2*v[j])>1 || gcdc(2*v[i], v[j]) > 1){
                    count++;
                }
            }
        }
        cout<<count<<endl;
    }
    return 0;
}