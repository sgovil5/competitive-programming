#include<iostream>
#include <set>
#include <algorithm>
using namespace std;

int t; 
multiset<int> m;

bool check(int start){
    multiset<int> temp;
    for(auto elem: m) temp.insert(elem);

    bool possible = true;
    while(temp.size()>0){
        int currMax = *prev(temp.end());
        temp.erase(prev(temp.end()));
        if(temp.find(start-currMax)!=temp.end()){
            temp.erase(temp.find(start-currMax));
            start = currMax;
        } else{
            possible = false;
            break;
        }
    }
    return possible;
}

void output(int start){
    multiset<int> temp;
    for(auto elem: m) temp.insert(elem);

    while(temp.size()>0){
        int currMax = *prev(temp.end());
        cout<<currMax<<" "<<start-currMax<<endl;
        temp.erase(prev(temp.end()));
        temp.erase(temp.find(start-currMax));
        start = currMax;
    }
}

int main(){
    cin>>t;
    for(int tc=0; tc<t; tc++){
        int n; cin>>n;
        m.clear();
        for(int i=0; i<2*n; i++){
            int x; cin>>x;
            m.insert(x);
        }
        bool possible = false;
        int ans;
        for(multiset<int>::iterator it=m.begin(); it!=prev(m.end()); ++it){
            possible = check(*it+*prev(m.end()));
            if(possible){
                ans = *it+*prev(m.end());
                break;
            }
        }
       
       if(possible){
           cout<<"YES"<<endl<<ans<<endl;
           output(ans);
       } else{
           cout<<"NO"<<endl;
       }
    }
    return 0;
}