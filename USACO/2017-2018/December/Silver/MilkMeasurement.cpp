#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  ifstream cin("measurement.in");
  ofstream cout("measurement.out");

  ll n, g; cin>>n>>g;
  set<pair<ll, pair<ll,ll>>> input; //day, id, change
  map<ll, set<ll>> s; //s[i] = set of integers with a production value of i
  map<ll, ll> production; //production[i] = how much cow i makes
  multiset<ll, greater<ll>> leaderboard; // ranks cows in descending order of production

  for(int i=0; i<n; i++){
    ll day, id, change; cin>>day>>id>>change;
    input.insert({day, {id, change}});
    production[id] = g; s[g].insert(id); leaderboard.insert(g);
  }

  ll ans = 0, mx = g;
  for(auto u: input){
    set<ll> prev = s[mx];
    ll id = u.second.first, change = u.second.second;
    if(change==0) continue;
    ll newVal = production[id]+change;
    
    //remove old values
    leaderboard.erase(leaderboard.find(production[id]));
    s[production[id]].erase(s[production[id]].find(id));
    
    //add new values
    production[id] = newVal;
    leaderboard.insert(newVal); s[newVal].insert(id);

    mx = *leaderboard.begin();

    if(prev!=s[mx]) ans++;
  }
  cout<<max(1ll, ans);
} 
