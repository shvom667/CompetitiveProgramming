#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
template <typename T> using Vec = vector<T>;

#ifndef ONLINE_JUDGE
#include "/home/shivom/Downloads/CP/DataStructures/debug.cpp"
#include "/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
#else
#define dbg(...) 42
#define rnd(...) 42
#endif
ll ub(ll x, ll y) { return (x + y - 1) / y; }
ll lb(ll x, ll y) { return x / y; }
// =================
#define ALL(x) begin(x), end(x)
template <typename T> void makeUniq(vector<T> &vec) {
  sort(begin(vec), end(vec));
  vec.resize(unique(ALL(vec)) - vec.begin());
}
map<ll, ll> cmp, dmp;
void compress(Vec<ll> &tot) {
  makeUniq(tot);
  ll n = tot.size();
  for (ll i = 0; i < n; i++) {
    cmp[tot[i]] = i;
    dmp[i] = tot[i];
  }
}

auto solve() {
  ll n, m, k;
  cin >> n >> m >> k;
  vector<ll> h(n), x(n);
  for (ll i = 0; i < n; i++) {
    cin >> h[i];
  }
  for (ll j = 0; j < n; j++) {
    cin >> x[j];
  }
  ll L, R;
  L = 1, R = 1e9+1;
  auto cond = [&](ll t) {
    vector<ll> lr(n),rr(n);
    for(ll i = 0; i < n; i++) {
        lr[i] = ub(h[i]+t*x[i]-t*m, t);
        rr[i] = lb(m*t+t*x[i]-h[i], t);
        
    }
    // swap(lr, rr);
    // for(ll i = 0; i < n; i++) {
    //     cout << lr[i] << " ";
    // }   cout << '\n';
    // for(ll i = 0; i < n; i++) {
    //     cout << rr[i] << " ";
    // }   cout << '\n';

    vector<pair<ll,ll>> vp;
    for (ll i = 0; i < n; i++) {
        if (lr[i] <= rr[i])
            vp.pb({lr[i], rr[i]});
    }

    sort(begin(vp),end(vp),[&](auto x,auto y){
        if(x.first < y.first)return true;
        if(x.first==y.first){
            return x.second<y.second;
        }
        return false;
    });
    ll cnt = 0; 
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    ll cur=0;
    dbg(vp);
    for(ll i=0;i<(ll)vp.size();i++){
        dbg(i,pq);
        while(!pq.empty() && pq.top().first < vp[i].first) {
            pq.pop();
            cur--;
        }
        pq.push({vp[i].second,vp[i].first});
        cur++;
        dbg(i,cur);
        cnt=max(cnt,cur);
    }
    return cnt>=k;
  };

//   auto res = cond(2);
//   dbg(res);
//   return 0ll;
  while (L <= R) {
    ll mid = L + (R - L) / 2;
    if (cond(mid)) {
      R = mid - 1;
    } else {
      L = mid + 1;
    }
  }

  if (L > 1e9) {
    return -1ll;
  }
  return L;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll T;
  cin >> T;
  for (ll tc = 1; tc <= T; tc++) {
    auto res = solve();
    cout << res << "\n";
  }
  return 0;
}
