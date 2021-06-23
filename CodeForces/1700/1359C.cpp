#include <iostream>
using namespace std;

long double h,c,t;

bool check(int cups){
    long double totTemp = (long double) c*(cups) + h*(cups+1.0);
    long double avgTemp = (long double) (totTemp) / (long double) (2*cups+1.0);
    //cout<<cups<<" "<<avgTemp<<" "<<t<<endl;
    return avgTemp >= t;
}

int solve(){
    int left = 0, right = 1e6+1, cups = 0;

	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (check(mid)) {
			cups = mid;
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
    
    if(cups>=1e6+1){
        return 2;
    }
    
    long double beforeTemp = (long double) c*(cups) + h*(cups+1.0);
    long double afterTemp = (long double) c*(cups+1.0) + h*(cups+2.0);

    long double beforeAvg = beforeTemp/(long double) (2*cups+1.0);
    long double afterAvg = afterTemp/(long double) (2*cups +3.0);
    long double bothAvg = (long double) (h+c)/(2.0);

    long double minDiff = min(abs((long double) t-beforeAvg), min(abs((long double) t-afterAvg), abs((long double) t-bothAvg)));

    if(minDiff==abs(t-bothAvg)) return 2;
    if(minDiff==abs(t-beforeAvg)) return 2*cups+1;
    return 2*cups+3;
}

int main(){
    int tc; cin>>tc;
    while(tc--){
        cin>>h>>c>>t;
        int ans = solve();
        cout<<ans<<endl;
    }
    return 0;
}