// Ugh can't use bits/stdc++.h🙄
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int n,q;
string s;

int main(){
    cin>>n>>q>>s;

    // Calculate and initialize prefix
    vector<int> prefix(n), lastSeenPrefix(26, -1);

    for(int i=0; i<n; i++){
        if(i>0) prefix[i] = prefix[i-1];
        if(lastSeenPrefix[s[i]-'A']==-1) prefix[i]++;
        else{
            bool isNewSegment = false;

            // Spent 20 minutes to realize that I used i in the nested loop 😒
            for(int j=0; j<s[i]-'A';j++){
                if(lastSeenPrefix[j]>lastSeenPrefix[s[i]-'A']){
                    isNewSegment = true;
                    break;
                }
            }

            if(isNewSegment) prefix[i]++;
        }
        lastSeenPrefix[s[i]-'A'] = i;
    }

    // Calculate and initialize suffix
    vector<int> suffix(n), lastSeenSuffix(26, n);

    for(int i=n-1; i>=0; i--){
        if(i<n-1) suffix[i] = suffix[i+1];
        if(lastSeenSuffix[s[i]-'A'] == n) suffix[i]++;
        else{
            bool isNewSegement = false;
            // Spent 20 minutes to realize that I used i in the nested loop 😒
            for(int j=0; j<s[i]-'A'; j++){
                if(lastSeenSuffix[j]<lastSeenSuffix[s[i]-'A']){
                    isNewSegement = true;
                    break;
                }
            }

            if(isNewSegement) suffix[i]++;
        }
        lastSeenSuffix[s[i]-'A'] = i;
    }

    // Perform queries
    while(q--){
        int a,b, ans = 0;
        cin>>a>>b;
        a--,b--;
        if(a>0) ans+=prefix[a-1];
        if(b<n-1) ans+=suffix[b+1];
        cout<<ans<<endl;
    }
    return 0;
}
