#include <bits/stdc++.h>
using namespace std;
ifstream fin("problem.in")//for USACO only
ofstream fout("problem.out")//for USACO only

typedef long long ll;

//Pairs
typedef pair<int,int> pi;
#define mp make_pair
#define f first
#define s second

//Vectors
typedef vector<int> vi;
typedef vector<pi> vpi;
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define ins insert 
#define ft front() 
#define bk back()
#define pb push_back

//Loops
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define trav(a,x) for (auto& a: x)

const int xd[4] = {0,1,0,-1}, yd[4] = {1,0,-1,0}; //Floodfill

template<class T> bool ckmin(T& a, const T& b) { 
	return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { 
	return a < b ? a = b, 1 : 0; }
