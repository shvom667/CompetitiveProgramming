#define ONLINE_JUDGE
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;

void solve();
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll t; 
  cin >> t; 
  while (t--) solve();
}
using pl=pair<ll,ll>;
void solve() {
  ll n;
  string s;
  cin >> n >> s;
  Vec<ll> res;
  ll len=0;
  for(ll i=0;i<n;i++){
    if (i==0||s[i]!=s[i-1]){
      len++;
      continue;
    }
    if(s[i]==s[i-1]){
      res.pb(len);
      len=1;
    }
  }
  res.pb(len);
  set<pl> S,R;
  for(ll i=0;i<(ll)res.size();i++){
    S.insert({i,res[i]});
    R.insert({res[i],i});
  }
  while((ll)R.size()>1){
    auto f = *R.begin();
    auto ff=f;
    ff.second=f.first,ff.first=f.second;
    auto it = S.find(ff);
    f = *it;
    auto nt = it;
    auto pt = it;
    nt++;
    pt--;
    if (it == begin(S)) {
      auto ff=f;
      ff.second=f.first,ff.first=f.second;
      S.erase(S.find(f));
      R.erase(R.find(ff));
    }
    else if (nt == end(S)) {
      S.erase(S.find(f));
      auto ff=f;
      ff.second=f.first,ff.first=f.second;
      R.erase(R.find(ff));
    }
    else {
      auto p = *pt;
      auto n = *nt;
      auto rep = f;
      auto sep = rep;
      rep.second = p.second + n.second - f.second;
      rep.first = f.first;
      S.erase(S.find(f));
      S.erase(S.find(p));
      S.erase(S.find(n));
      auto ff=f, pp=p, nn=n;
      ff.first = f.second, ff.second=f.first;
      pp.first = p.second, pp.second=p.first;
      nn.first = n.second, nn.second=n.first;
      R.erase(R.find(ff));
      R.erase(R.find(pp));
      R.erase(R.find(nn));
      S.insert(rep);
      sep.first = rep.second;
      sep.second = rep.first;
      R.insert(sep);
    }
  }
  cout << (*R.begin()).first << "\n";
}
