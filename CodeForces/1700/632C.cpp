#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(const string& a, const string& b){
    return a+b<b+a;
}

int n;
vector<string> v;
int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        string x; cin>>x;
        v.push_back(x);
    }
    sort(begin(v), end(v), cmp);
    for(int i=0; i<n; i++) cout<<v[i];
    return 0;
}