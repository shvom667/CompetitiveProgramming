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
 


vector<pair<ll, ll>> c;
map<ll, ll> con;
ll n, k;
const ll INF = 1e9;
map<vector<ll>, bool> winning;

const ll N  = 50;
ll grundy[N];

bool dfs(vector<ll> in) {
    if (*max_element(begin(in),end(in)) == 0) {
        return winning[in] = false;
    }

    bool can_win = false;
    for (ll i = 0; i < n; i++) {
        if (in[i] == 0) continue;
        in[i]--;


        map<ll, ll> freq;
        bool c_ok = true;

        for (ll i = 0; i < n; i++) {
            freq[in[i]]++;
        }
        for (ll j = 0; j < k; j++) {
            if (freq[c[j].first] <= c[j].second) {

            } else {
                c_ok = false;
            }
        }
        
        if (!c_ok) {

        } else {
            if (dfs(in) == false) {
                can_win = true;
            }   
        }
        in[i]++;    
    }
    return winning[in] = can_win;
}

auto brute(ll n) {
    if (n == 0) {
        grundy[n] = 0;
        return;
    }   
    if (n > 0) {
        ll ub = 0;
        if (con.find(n) == con.end()) ub = INF;
        else {
            ub = con[n];
        }
        if (ub > 0) {
            brute(n-1);
            
        } // can go to that
    }
}
auto get_mex(ll n) {
    if (n > 0) return 0;
    else return 1;
}
auto bf() {
    cin >> n >> k;

    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    c = vector<pair<ll, ll>> (k);
    for (ll i = 0; i < k; i++) {
        cin >> c[i].first >> c[i].second;
    }

    dbg(a);
    dbg(c);

    dbg(dfs(a));

    for (auto&[u, v]: c) {
        con[u] = v;
    }

    // grundy[0] = 0;
    // for (ll i = 1; i < N; i++) {
    //     ll ub = 0;
    //     if (con.find(n) == con.end()) ub = INF;
    //     else {
    //         ub = con[n];
    //     }
    //     if (ub > 0) {
    //         grundy[i] = get_mex(grundy[i-1]);
    //     }
    // }

    // for (auto& [u, v] : winning) {
    //     dbg(u, v);
    // }

    // ll x = 0;
    // for (ll i = 0; i < n; i++) {
    //     x ^= grundy[i];
    // }

    // for (ll i = 0; i < 5; i++) 
    // {
    //     cout << grundy[i] << " ";
    // }   cout << "\n";

    // if (x == 0) {
    //     cout << "losing\n";
    // } else {
    //     cout << "winning\n";
    // }
    // winning.clear();
}

auto solve() {
    bf();
    con.clear();
    return 0;
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
