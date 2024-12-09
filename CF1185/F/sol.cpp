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
const ll inf = 1e18;
auto solve() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> b(n);
    for (ll i = 0; i < n; i++) {
        ll x; cin >> x;
        b[i] = Vec<ll> (x);
        for (ll j = 0; j < x; j++) {
            cin >> b[i][j];
        }
    }
    dbg(b);

    Vec<ll> p(m); 
    vector<vector<ll>> ig(m);

    for (ll i = 0; i < m; i++) {
        ll x;
        cin >> p[i] >> x;
        ig[i] = Vec<ll> (x);
        for (ll j = 0; j < x; j++) {
            cin >> ig[i][j];
        }
    }

    dbg(ig);

    ll dp[1<<9];
    
    for(ll i = 0; i < (1 << 9); i++) dp[i] = inf;

    dp[0] = 0;

  
    vector<ll> mask_ig(m, 0);
    for (ll i = 0; i < m; i++) {
        for(auto&x:ig[i]) {
            mask_ig[i] ^= (1ll << (x - 1));
        }
    }    
    vector<pair<ll,ll>> opt_mask_ans(1<<9);


    vector<ll> cost_mask(1 << 9, inf);
    cost_mask[0] = 0;

    vector<ll> best_mask_rev(1<<9,-1);

    for (ll i = 0; i < m; i++) {
        cost_mask[mask_ig[i]] = min(cost_mask[mask_ig[i]], p[i]);

        if (cost_mask[mask_ig[i]]  == p[i]) {
            best_mask_rev[mask_ig[i]] = i;
        }
    }

    vector<ll> cost_mask_pair(1 << 9, inf);

    for (ll i = 0; i < (1 << 9); i++) {
        for (ll j = i + 1; j < (1 << 9); j++) {
            cost_mask_pair[(i|j)] = min(cost_mask_pair[(i|j)], cost_mask[i] + cost_mask[j]);
            if (cost_mask_pair[(i|j)] == cost_mask[i] + cost_mask[j]) {
                opt_mask_ans[(i|j)]={best_mask_rev[i],best_mask_rev[j]};
            }
        }
    }

    dbg(cost_mask_pair[15]);

    vector<ll> mask_fr(n, 0);

    for (ll i = 0; i < n; i++) {
        for(auto&x:b[i]) {
            mask_fr[i] ^= (1ll << (x - 1));
        }
    }

    dbg(mask_fr);
    dbg(mask_ig);

    for (ll i = 0; i < n; i++) 
    {
        dbg(mask_fr[i], 278, (mask_fr[i]&278));
    }

    ll max_fr = 0;
    ll min_cost = 1e18;
    ll best_mask = -1;
    for (ll mask = 0; mask < (1 << 9); mask++) {
        ll cur_fr = 0;
        if (cost_mask_pair[mask] < inf) {
            if (mask == 278) {
                dbg("Hello");
            }
            for (ll i = 0; i < n; i++) {
                if (mask == 278) {
                    dbg(((mask & mask_fr[i]) == mask_fr[i]) );
                }
                if ((mask & mask_fr[i]) == mask_fr[i]) {
                    cur_fr++;
                }    
            }
            dbg(cur_fr);
        }
        if (cur_fr > max_fr) {
            max_fr = cur_fr;
            min_cost = cost_mask_pair[mask];
            best_mask = mask;
        }
        else if (cur_fr == max_fr) {
            min_cost = min(min_cost, cost_mask_pair[mask]);
            if (min_cost == cost_mask_pair[mask]) {
                best_mask = mask;
            }
        }
    }

    dbg(best_mask);

    if (max_fr == 0) {
        vector<ll> I(m , 0); for (ll i = 0; i < m; i++) I[i] = i;
        sort(begin(I),end(I),[&](auto x, auto y) {
            return p[x] < p[y];
        });
        dbg(I);
        cout << I[0] + 1 << " " << I[1] + 1 << '\n';

        return 0;
    }

    if (opt_mask_ans[best_mask].first == -1) {
        ll mc=1e18;
        ll mi = -1;
        for (ll i = 0; i < n; i++) 
        {
            if (i == opt_mask_ans[best_mask].second) continue;
            mc = min(mc, p[i]);
            if (mc == p[i]) {
                mi = i;
            }
        }
        opt_mask_ans[best_mask].first = mi;
    }

    dbg(min_cost);

    assert(opt_mask_ans[best_mask].second != -1);
    cout << opt_mask_ans[best_mask].first + 1 << " " << opt_mask_ans[best_mask].second + 1 << '\n';

    dbg(max_fr);



    // cout << max_fr << " " << min_cost << '\n';

    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    
    T = 1;
    for (ll tc = 1; tc <= T; tc++) {
	    auto res = solve();
	    // cout << res << "\n";
    }
    return 0;
}
