#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int MX = 1005;
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};

int n;
bool present[MX][MX];
set<pair<int,int>> comfy;

bool isValid(int x, int y){
    //change bounds
    return x>=0 && x<=n && y>=0 && y<=n;
}

bool isComfy(int x, int y){
    if(present[x][y]==false) return false;
    int adj = 0;
    for(int d=0; d<4; d++){
        if(isValid(x+dx[d], y+dy[d])){
            if(present[x+dx[d]][y+dy[d]]) adj++;
        }
    } 
    return adj==3;
}

int main(){
    cin>>n;

    for(int i=0; i<MX; i++) for(int j=0; j<MX; j++) present[i][j] = false;

    for(int i=0; i<n; i++){
        int a,b; cin>>a>>b;

        for(int d=0; d<4; d++){
            int x = a+dx[d], y = b+dy[d];
            if(isValid(x,y) && isComfy(x,y)) comfy.erase({x,y});
        }

        present[a][b] = true;

        for(int d=0; d<4; d++){
            int x = a+dx[d], y = b+dy[d];
            if(isValid(x,y) && isComfy(x,y)) comfy.insert({x,y});
        }
        if(isComfy(a,b)) comfy.insert({a,b});

        cout<<comfy.size()<<endl;
    }
}