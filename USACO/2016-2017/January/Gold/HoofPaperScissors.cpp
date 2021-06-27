#include <iostream>
#include <vector>
using namespace std;

const int MX = 1e5+1;

int n,k;
int a[MX];

void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0); 
	if (sizeof(name)) {
		freopen((name+".in").c_str(), "r", stdin); 
		freopen((name+".out").c_str(), "w", stdout);
	}
}

bool check(int b, int fj){
    if(b==0 && fj==2) return true;
    if(b==1&&fj==0) return true;
    if(b==2&&fj==1) return true;
    return false;
}

int main(){
    //setIO("hps");
    cin>>n>>k;
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(k+2, vector<int>(3, 0)));

    for(int i=1; i<=n; i++){
        char x; cin>>x;
        if(x=='H') a[i] = 0;
        else if(x=='P') a[i] = 1;
        else a[i] = 2;
    }

    int ans = 0;
    cout<<ans<<endl;

    for(int i=1; i<=n; i++){
        for(int j=0; j<=k; j++){
            if(check(0, a[i])) dp[i][j][0]++;
            dp[i][j][0]= max(dp[i-1][j][0], max(dp[i-1][j-1][1], dp[i-1][j-1][2]));
            
            if(check(1, a[i])) dp[i][j][1]++;
            dp[i][j][1]= max(dp[i-1][j][1], max(dp[i-1][j-1][0], dp[i-1][j-1][2]));
            
            if(check(2, a[i])) dp[i][j][2]++;
            dp[i][j][2]= max(dp[i-1][j][2], max(dp[i-1][j-1][0], dp[i-1][j-1][1]));

            if(i==n){
                ans=max(ans, max(dp[i][j][0], max(dp[i][j][1], dp[i][j][2])));
            }
        }
    }
    cout<<ans;
}