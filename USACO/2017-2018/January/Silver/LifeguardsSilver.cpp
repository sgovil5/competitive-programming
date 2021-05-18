/**
    To preface this problem I have no fucking clue what I just did.😅
    I just tried doing a bunch of random min and max shit and it worked.😓
    I hope to come back to this problem and understand how to solve it,
    except I probably won't because I'm a lazy fuck. 😁

    This kinda shit is pretty common in Silver so I should actually study this....
**/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// I love macros😄
#define l first //left
#define r second //right

int n;
vector<pair<int,int>> times; //start, stop

void setIO(string fileName = "") {
	ios_base::sync_with_stdio(0); cin.tie(0);
	if((int)fileName.size()) {
		freopen((fileName+".in").c_str(), "r", stdin);
		freopen((fileName+".out").c_str(), "w", stdout);
	}
}

int main(){
    // Standard IO Stuff......... 😴
    setIO("lifeguards");
    cin>>n;
    for(int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        times.push_back({a,b});
    }
    sort(begin(times), end(times));

    // Calculate the total amount of time that is being worked
    int left = 0, right = 0, tot = 0;
    for(int i=0; i<n; i++){
        // I have no fucking clue how this works, but let me try my best to explain 🤯
        // If the new right boundary is greater than the previous boundary we know that a new shift is being covered 😲 
        if(times[i].r > right){
            // We then compute our left to be the previous right, or the new left(in case of a disjointed interval) 🤨
            left = max(right, times[i].l);
            // Update right 😑
            right = times[i].r;
            // Add new interval to total 😶
            tot += right - left;
        }
    }

    // Calculate the minimum amount that a lifeguard works alone so we can fire them 😔
    int minAlone = tot;
    // Gotta do this to ensure we don't go outta bounds 🤓
    times.push_back({times[n-1].r, times[n-1].r});
    left = 0, right = 0;

    for(int i=0; i<n; i++){
        // Left can be calculated as the max of the previous right and new left(similar to before) 😌
        left = max(right, times[i].l);
        // Right can be computed as the max of the previous right or the new right(similar to before) 🙄
        right = max(right, times[i].r);

        // The current alone time a lifeguard has is the smallest interval between [left, current right] and [left, next left] 🥴
        // Side note, I got so fucking confused when doing this part 😵
        int curAlone = min(times[i+1].l, times[i].r) - left;
        // Self explanatory 😒
        minAlone = min(curAlone, minAlone);
    }

    // Total time we get is total time being worked - minimum time alone 😝
    cout<<tot-max(0, minAlone)<<endl;
}