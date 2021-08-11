#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void setIO(string fileName = "") {
	ios_base::sync_with_stdio(0); cin.tie(0);
	if((int)fileName.size()) {
		freopen((fileName+".in").c_str(), "r", stdin);
		freopen((fileName+".out").c_str(), "w", stdout);
	}
}

int n,k;
vector<int> arr;

int main(){
    setIO("berries");
    cin>>n>>k;
    for(int i=0; i<n; i++){
        int x; cin>>x; arr.push_back(x);
    }

    int lim = *max_element(begin(arr), end(arr));
    int ans = 0;
    for(int i=1; i<=lim; i++){
        int currSum = 0;
        vector<int> temp;
        for(int j=0; j<arr.size(); j++){
            int numTimes = arr[j]/i;
            for(int l=0; l<numTimes; l++) temp.push_back(i);
            if(arr[j]%i!=0) temp.push_back(arr[j]%i);
        }
        sort(begin(temp), end(temp));
        reverse(begin(temp), end(temp));
        for(int j=k/2; j<k && j<temp.size(); j++) currSum+=temp[j];
        ans = max(ans, currSum);
    }
    cout<<ans;
    
}