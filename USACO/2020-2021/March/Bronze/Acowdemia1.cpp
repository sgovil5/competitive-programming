#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, l;
vector<int> papers;

int index(){
    int h = papers.size();
    // using h-1 because off index mismatch
    while(h>0 && papers[h-1]<h) h--;
    return h;
}

int main(){
    cin>>n>>l;
    for(int i=0; i<n; i++){
        int x; cin>>x;
        papers.push_back(x);
    }
    sort(begin(papers), end(papers), greater<int>());
    int h = index();
    if(h<n){
        for(int i=h; i>=max(0, h-l+1); i--){
            papers[i]++;
        }
    }
    sort(begin(papers), end(papers), greater<int>());
    cout<<index()<<endl;
}