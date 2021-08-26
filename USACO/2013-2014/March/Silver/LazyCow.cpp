#include <iostream>
#include <algorithm>
using namespace std;

const int MX = 405;
int n, k;
int arr[MX][MX], prefix[MX][MX];

void setIO(string fileName = "") {
	ios_base::sync_with_stdio(0); cin.tie(0);
	if((int)fileName.size()) {
		freopen((fileName+".in").c_str(), "r", stdin);
		freopen((fileName+".out").c_str(), "w", stdout);
	}
}

int main(){
    setIO("lazy");
    cin>>n>>k;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<n; i++){
        prefix[i][0] = 0;
        for(int j=1; j<=n; j++){
            prefix[i][j] = prefix[i][j-1] + arr[i][j-1]; 
        }
    }

    int ans = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int sum=0;

            int left = j-k+1, right =j+k+1; 
            for(int l=i; l>=max(0, i-k); l--){
                sum+=prefix[l][min(right, n)] - prefix[l][max(left, 1)-1];
                left++, right--;
            }

            left = j-k+2, right = j+k;
            for(int l=i+1; l<=min(n-1, i+k); l++){
                sum+=prefix[l][min(right, n)] - prefix[l][max(left, 1)-1];
                left++, right--;
            }

            ans = max(ans, sum);
        }
    }
    cout<<ans;
}