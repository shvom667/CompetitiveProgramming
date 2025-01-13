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

// ============
const ll N = 1e6 + 20;
vector<ll> MinPrime;
vector<ll> PRIME;
vector<ll> cntPrime(N, 0);

void pre_calc_sieve(ll N) {
	MinPrime = vector<ll> (N + 1, 0);
	for (ll i = 2; i <= N; ++i) {
		if (MinPrime[i] == 0) {
			MinPrime[i] = i;
			PRIME.push_back(i);
		}
		for (ll j = 0; i * PRIME[j] <= N; ++j) {
			MinPrime[i * PRIME[j]] = PRIME[j];
			if (PRIME[j] == MinPrime[i]) {
				break;
			}
		}
	}
    for (ll i = 0; i < N; i++) {
        if (MinPrime[i] == i) {
            cntPrime[i] = 1;
        }

        if (i) {
            cntPrime[i] += cntPrime[i - 1];
        }
    }
}

// ============
void solve(ll n) {

    ll l = 1, r = 2000;

    auto cond = [&](ll m) {
        if (m & 1) {
            return m * (m + 1) / 2 >= n - 1;
        }
        return (m * m) / 2 + 1 >= n - 1;
    };

    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (cond(mid)) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    ll v = l;
    ll nn = n;

    dbg(v);

    n = v;
    vector<vector<ll>> g(n, vector<ll>(n, 0));
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            g[i][j] += 1;
        }
    }

    
    if (n % 2 == 0) {
        for (ll i = 1; i < n - 2; i++) {
            g[i][i + 1] -= 1;
            g[i + 1][i] -= 1;
        }
    }



    vector<ll> deg(n, 0);
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j)
            deg[i] += g[i][j];
    }

    dbg(deg);

    ll first = 0;
    while (first < n && !deg[first])
        ++first;
    if (first == n) {
        cout << -1;
    }

    dbg(first);

    ll v1 = -1, v2 = -1;
    bool bad = false;
    for (ll i = 0; i < n; ++i) {
        if (deg[i] & 1) {
            if (v1 == -1)
                v1 = i;
            else if (v2 == -1)
                v2 = i;
            else
                bad = true;
        }
    }

    if (v1 != -1)
        ++g[v1][v2], ++g[v2][v1];


    dbg(bad);

    stack<ll> st;
    st.push(first);
    vector<ll> res;
    while (!st.empty()) {
        dbg("hello");
        ll v = st.top();
        ll i;
        for (i = 0; i < n; ++i)
            if (g[v][i])
                break;
        if (i == n) {
            res.push_back(v);
            st.pop();
        } else {
            --g[v][i];
            --g[i][v];
            st.push(i);
        }
    }

    dbg(v1);

    if (v1 != -1) {
        for (size_t i = 0; i + 1 < res.size(); ++i) {
            if ((res[i] == v1 && res[i + 1] == v2) ||
                (res[i] == v2 && res[i + 1] == v1)) {
                vector<ll> res2;
                for (size_t j = i + 1; j < res.size(); ++j)
                    res2.push_back(res[j]);
                for (size_t j = 1; j <= i; ++j)
                    res2.push_back(res[j]);
                res = res2;
                break;
            }
        }
    }

    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            if (g[i][j])
                bad = true;
        }
    }
    
    if (bad) {
        cout << -1;
    } else {
        for (ll x : res)
            cout << x << " ";
    }

}

auto verify(Vec<ll> v) {
    ll n = (ll)v.size();

    map<ll, ll> mp;
    for (ll i = 0; i < n - 1; i++) {
        mp[v[i] * v[i + 1]]++;
    }
    bool ok = true;
    for (auto [u, v]: mp) {
        if (v > 1) {
            ok = false;
        }
    }
    return ok;
}

int main() {


    ios_base::sync_with_stdio(0);
    cin.tie(0);

    pre_calc_sieve(N);
    solve(10);
//    for (ll n = 2; n <= 21; n++) {
//        solve(n);
//    }

    // ll T;
    // cin >> T;
    // for (ll tc = 1; tc <= T; tc++) {
    //     auto res = solve();
    //     for(auto x : res) {
    //         cout << x << " ";   
    //     }   cout << '\n';
    //     assert(verify(res));
    // }
    return 0;
}
