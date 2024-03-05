#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++) {
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    vector<int> use(4);
    use[0] = v[0], use[1] = v[1], use[2] = v[n-2], use[3] = v[n-1];
    vector<vector<int>> permutations;
    do {
        permutations.push_back(use);
    } while(next_permutation(use.begin(), use.end()));

    long long max_val = -1e9;
    for (vector<int> p : permutations) {
        long long currSum = abs(p[0]-p[1]) + abs(p[1]-p[2]) + abs(p[2]-p[3]) + abs(p[3]-p[0]);
        max_val = max(max_val, currSum);
    }

    
    // for(int i=0; i<n; i++) {
    //     for (int j=0; j<n; j++) {
    //         if(j==i) continue;
    //         for(int k=0; k<n; k++) {
    //             if(k==j || k==i) continue;
    //             for(int l=0; l<n; l++) {
    //                 if(l==k || l==j || l==i) continue;
    //                 long long currSum = abs(v[i]-v[j]) + abs(v[j]-v[k]) + abs(v[k]-v[l]) + abs(v[l]-v[i]);
    //                 if(currSum > max_val) {
    //                     max_val = currSum;
    //                     cout<<max_val<<" "<<v[i]<<" "<<v[j]<<" "<<v[k]<<" "<<v[l]<<endl;
    //                 }
    //             }
    //         }
    //     }
    // }
    cout<<max_val<<endl;
}

int main() {
    int t; cin>>t;
    while(t--) {
        solve();
    }
}