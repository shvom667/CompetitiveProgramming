#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;

#ifndef ONLINE_JUDGE
#include "/home/shivom/Downloads/CP/DataStructures/debug.cpp"
#include "/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
#else
#define dbg(...) 42
#define rnd(...) 42
#endif

auto solve() {
    ll n, l, r;
    cin>>n>>l>>r;

    map<ll,ll>cnt;
    map<ll,ll>len;

    function<void(ll)> fill_cnt = [&] (ll v) {
        if(v==1){
            cnt[v]=1;
            len[v]=1;
            return;
        }
        if(v==0){
            cnt[v]=0;
            len[v]=1;
            return;
        }
        fill_cnt(v/2);
        cnt[v] = 2*cnt[v/2] + (v&1);
        len[v] = 2*len[v/2] + 1;
    };

    fill_cnt(n);

    function<ll(ll,ll)> f= [&] (ll x, ll k) {
        if (x == 1) {
            if (k == 1) {
                return 1ll;
            } else {
                return 0ll;
            }
        }
        if (x == 0) {
            return 0ll;
        }
        if (k <= (len[x] - 1) / 2) {
            return f(x / 2, k);
        }
        ll res = 0;
        res += cnt[x/2];
        if (x&1) res++;
        k  -= (len[x] + 1) / 2;

        return res + f(x / 2, k);
    };

    return f(n,r) - f(n,l -1);
    // dbg(len[n]);
    // dbg(cnt[n]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    T = 1;
    for (ll tc = 1; tc <= T; tc++) {
	    auto res = solve();
	    cout << res << "\n";
    }
    return 0;
}
