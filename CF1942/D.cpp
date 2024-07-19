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


struct Foo
{
  ll sum, j, itr;
};

class Compare
{
public:
    bool operator() (Foo a, Foo b)
    {
      if (a.sum < b.sum) return true;
      return false;
    }
};

/*
 * Custom Compare For Priority Queue
 * priority_queue<Foo, vector<Foo>, Compare> pq;
 */ 
const ll N = 1e3 + 20;
ll tab[N][N];
void solve() {
  ll n , k;
  cin >> n >> k;
  Vec<ll> dp[n+1];
  for (ll i = 1; i <= n; i++) {
    for (ll j = i; j <= n; j++) {
      cin >> tab[i][j];
    }
  }
  dp[0] = {0};
  dp[1] = {max(0ll, tab[1][1]), min(0ll, tab[1][1])};
  for (ll i = 2; i <= n; i++) {
    priority_queue<Foo, Vec<Foo>, Compare> pq;
    for (ll j = 0; j <= i - 2; j++) {
      Foo x;
      x.sum = dp[j][0] + tab[j+2][i];
      x.j = j;
      x.itr = 0;
      pq.push(x);
    }
    Foo y;
    y.sum = tab[1][i];
    y.j = 0;
    y.itr = 0;
    pq.push(y);
    while(!pq.empty() && dp[i].size() < k) {
      Foo t = pq.top();
      pq.pop();
      dp[i].pb(t.sum);
      if (t.itr + 1 < dp[t.j].size()) {
        t.itr++;
        t.sum = dp[t.j][t.itr] + tab[t.j+2][i];
        pq.push(t);
      }
    }
    Vec<ll> res;
    ll ptr1 = 0, ptr2 = 0;
    while (ptr1 < dp[i-1].size() && ptr2 < dp[i].size()) {
      if (dp[i-1][ptr1] >= dp[i][ptr2])  {
        res.pb(dp[i-1][ptr1]);
        ptr1++;
      } else {
        res.pb(dp[i][ptr2]);
        ptr2++;
      }
    }
    while (ptr1 < dp[i-1].size()) {
      res.pb(dp[i-1][ptr1]);
      ptr1++;
    }
    while (ptr2 < dp[i].size()) {
      res.pb(dp[i][ptr2]);
      ptr2++;
    }
    while (res.size() > k) {
      res.pop_back();
    }
    dp[i] = res;
  }
  while (dp[n].size() > k) dp[n].pop_back();
  for (ll i = 0; i < (ll) dp[n].size(); i++) {
    cout << dp[n][i] << " ";
  } cout << '\n';
}
