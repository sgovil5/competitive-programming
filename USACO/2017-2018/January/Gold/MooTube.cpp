/*
Let me preface this by saying that the only "solution" I saw was to sort queries descending
I originally tried to use a map to contain the original index of the queries, but that didn't work out
because usaco decides that its okay to ask the same query twice???? Like howtf are you supposed to know that
Elephant orz, for helping me figure that out
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define f first
#define s second

void setIO(string fileName = "") {
	ios_base::sync_with_stdio(0); cin.tie(0);
	if((int)fileName.size()) {
		freopen((fileName+".in").c_str(), "r", stdin);
		freopen((fileName+".out").c_str(), "w", stdout);
	}
}

//Standard DSU
struct DSU {
	vector<int> e;
	void init(int N) { e = vector<int>(N, -1); }
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
	bool same_set(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
	bool unite(int x, int y) {  // union by size
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y]; e[y] = x;
		return true;
	}
};

// Sorts the list of edges based on decreasing order of relevance
bool cmp(const pair<pair<int,int>,int>& a, pair<pair<int,int>,int>& b){return a.s>b.s;}
//Sorts the list of queries based on deacreasing order of relevance
bool cmp2(const pair<pair<int,int>,int>& a, const pair<pair<int,int>,int>& b) {return a.f.f>b.f.f;}

int n,q;
vector<pair<pair<int,int>,int>> vids; //p,q,r
vector<pair<pair<int,int>,int>> queries; // k,v, index
DSU d;
int res[100005]; // Final result for each query

int main(){
    setIO("mootube");
    cin>>n>>q;
    // Input the edges
    for(int i=0; i<n-1; i++){
        int p,q,r; cin>>p>>q>>r;
        p--,q--;
        vids.push_back({{p,q},r});
    }
    // Input the queries
    for(int i=0; i<q; i++){
        int k,v; cin>>k>>v;
        v--;
        queries.push_back({{k,v},i});
    }
    d.init(n);

    sort(begin(vids), end(vids), cmp);
    sort(begin(queries), end(queries), cmp2);

    // currIndex represents the current Index being considered in the edges
    int currIndex = 0;
    for(int i=0; i<q; i++){
        int k = queries[i].f.f, v = queries[i].f.s;
        // Check if the current edge being considered has a high enough relevance
        while(currIndex < vids.size() && vids[currIndex].s>=k){
            // If the relevance is high enough, then the 2 nodes are united
            d.unite(vids[currIndex].f.f, vids[currIndex].f.s);
            currIndex++;
        }
        // Calculate the original index that the query belonged to
        int resIndex = queries[i].s;
        // Give the result as the size of the current node-1
        res[resIndex] = d.size(v)-1;
    }

    for(int i=0; i<q; i++){
        cout<<res[i]<<endl;
    }
}