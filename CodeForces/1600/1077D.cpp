#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<pair<int,int>> v; // {value, count}
multiset<int> m;


bool check(int copies) {
    int tempK = k;
    int currIndex = 0;
    vector<pair<int, int>> tempV = v;
    while(tempK>0 && currIndex < tempV.size()) {
        if(tempV[currIndex].second >= copies) {
            tempV[currIndex].second -= copies;
            tempK--;
        } else {
            currIndex++;
        }
    }
    return tempK == 0;
}

int binarySearch(int lo, int hi) {
    lo--;
    while(lo<hi) {
        int mid = lo + (hi-lo+1)/2;
        if(check(mid)) lo = mid;
        else hi = mid-1;
    }
    return lo;
}

int main() {
    cin>>n>>k;
    for(int i=0; i<n; i++) {
        int x; cin>>x;
        m.insert(x);
    }
    set<int> uniqueElements(m.begin(), m.end());
    for (int elem : uniqueElements) {
        v.push_back({elem, m.count(elem)});
    }
    // sort v in descending order by counts
    sort(v.begin(), v.end(), [](pair<int,int> a, pair<int,int> b) {
        return a.second > b.second;
    });

    int copies = binarySearch(1, 2e5);

    vector<int> ans;
    int currIndex = 0;
    while(k>0) {
        if(v[currIndex].second >= copies) {
            ans.push_back(v[currIndex].first);
            v[currIndex].second -= copies;
            k--;
        }
        else {
            currIndex++;
        }
    }

    for(int i=0; i<ans.size(); i++) {
        cout<<ans[i]<<" ";
    }
}