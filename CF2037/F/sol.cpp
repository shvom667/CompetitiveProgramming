#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;
 
#ifndef ONLINE_JUDGE
    #include"/home/shivom/Downloads/CP/DataStructures/debug.cpp"
    #include"/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
#else
    #define dbg(...) 42
    #define rnd(...) 42
#endif
ll ub(ll x, ll y) {
    return (x + y - 1) / y;
}
// =================
#define ALL(x) begin(x), end(x)
template <typename T>
void makeUniq(vector<T>& vec) {
    sort(begin(vec),end(vec));
    vec.resize(unique(ALL(vec)) - vec.begin());
}
map<ll,ll> cmp,dmp;
void compress(Vec<ll>& tot) {
  makeUniq(tot);
  ll n=tot.size();
  for(ll i=0;i<n;i++){
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
    dbg(2 * m + 1, x[n - 1] - x[0] + 1);
    if (2 * m + 1 < x[n - 1] - x[0] + 1) {
        return -1ll;
    }
    ll L, R;
    L = 1, R = 1e10;
    auto cond = [&] (ll mid) {
        vector<ll> al(n, 0),ar(n, 0);
        vector<ll> ta,tb;
        for (ll i = 0; i < n; i++) {
            ll pmax = m + x[i] - ub(h[i], mid);
            dbg(pmax, x[i]);
            if (pmax >= x[i]) {
                dbg("in", i);
                ta.pb(x[i]);
                tb.pb(pmax + 1);
            }
        }
        for (ll i = 0; i < n; i++) {
            ll pmax = x[i] - m + ub(h[i], mid);
            dbg(i, pmax);
            if (pmax <= x[i]) {
                ta.pb(pmax);
                tb.pb(x[i] + 1);
            }
        }
        
        dbg(ta);
        dbg(tb);
        vector<ll> tot;
        for(auto&x:ta){tot.pb(x),tot.pb(x+1),tot.pb(x-1);};
        for(auto&x:tb){tot.pb(x),tot.pb(x+1),tot.pb(x-1);};
        compress(tot);
        vector<ll> sz((ll)tot.size(), 0);
        for (ll i = 0; i < ta.size(); i++) {
            sz[cmp[ta[i]]]+=1;
            sz[cmp[tb[i]]]+=-1;
        }
        dbg(sz);
        for(ll i=1;i<tot.size();i++){
            sz[i]+=sz[i-1];
            if(sz[i]>=k)return true;
        }

        cmp.clear();
        dmp.clear();
        return false;   
    };

    auto res = cond(1);
    dbg(res);
    return 0ll;
    while (L <= R) {
        ll mid = L + (R-L)/2;
        if (cond(mid)) {
            R=mid-1;
        }else{
            L=mid+1;
        }
    }

    if (L >= 1e10) {
        return -1ll;
    }
    return L;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        cout << res << "\n";
    }
    return 0;
}
