#include <iostream>
#include <map>
#include <string>
using namespace std;

int k, n;
map<string, int> names; //name, index
char ans[101][101];

int main(){
    cin>>k>>n;
    for(int i=0; i<n; i++){
        string x; cin>>x;
        names[x] = i;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(j==i) ans[i][j] = 'B';
            else ans[i][j] = '?';
        }
    }

    for(int i=0; i<k; i++){
        string curr[101];
        for(int j=0; j<n; j++) cin>>curr[j];

        for(int x=0; x<n; x++){
            bool isAlphabetical = true;
            for(int y=x+1; y<n; y++){
                if(curr[y-1]>curr[y]) isAlphabetical = false;

                if(!isAlphabetical){
                    int a = names[curr[x]], b = names[curr[y]];
                    ans[a][b] = '0', ans[b][a] = '1';
                }
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<ans[i][j];
        }
        cout<<endl;
    }
}