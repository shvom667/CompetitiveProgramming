#include<bits/stdc++.h>
using namespace std;
using ll=int;
#define pb push_back
template <typename T>
using Vec = vector<T>;
 
#ifndef ONLINE_JUDGE
    #include"/home/shivom/Downloads/CP/DataStructures/debug.cpp"
#else
    #define dbg(...) 42
#endif


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

const ll B = 20; 
const ll INF = 1e9;


auto solve() {
    ll N, M;
    cin >> N >> M;
    vector<ll> par(N + 1, 0);
    vector<ll> age(N + 1, INF);
    vector<ll> O(M), L(M), R(M);
    age[0] = INF;
    cin >> age[1] >> par[1];
    par[1] = 0;
    vector<ll> adj[N + 1];
    for (ll i = 2; i <= N; i++) {
        cin >> age[i] >> par[i];
        adj[par[i]].pb(i);
    }
    for (ll i = 0; i < M; i++) {
        cin >> O[i] >> L[i] >> R[i];
    }

    // ll up[N + 1][B];
    vector<vector<ll>> up(N + 1, vector<ll> (B, 0));

    for (ll i = 0; i < B; i++) {
        up[0][i] = 0;
    }

    for (ll i = 1; i <= N; i++) {
        up[i][0] = par[i];
    }

//    Vec<ll> final = {2, 1, 3, 1, 1, 2, 0, 2, 0, 1 };
//     for (auto& x : final) {
//         cout << x << " ";   
//     }   cout << '\n';
//     return;

    for (ll i = 1; i <= N; i++) {
        for (ll j = 1; j < B; j++) {
            if (up[i][j-1] > N || up[i][j-1] < 0) {
                up[i][j-1] = 0;
            }
            up[i][j] = up[up[i][j-1]][j-1];
        }
    }

//    Vec<ll> final = {2, 1, 3, 1, 1, 2, 0, 2, 0, 1 };
//     for (auto& x : final) {
//         cout << x << " ";   
//     }   cout << '\n';
//     return;

    auto get = [&] (ll node, ll val) {
        for (ll bit = B-1; bit >= 0; bit--) {
            // fans ^= (1<<bit);
            if ( age[up[node][bit]] <= val ) {
                node = up[node][bit];
            }
        }
        return node;
    };


    vector<ll> global;
    vector<ll> upd(N + 1, 0);

    vector<ll> lval[N + 1];
 
    for (ll i = 0; i < M; i++) {

        if (R[i] >= age[1]) {
            global.pb(L[i]);
            continue;
        }
        lval[O[i]].pb(L[i]);
        ll best_par = get(O[i], R[i]);
        upd[O[i]] += 1;
        upd[par[best_par]] += -1;
    }

    sort(begin(global),end(global));

    function<void(ll, ll)> dfs = [&] (ll i, ll p) {
        for (auto& ch : adj[i]) {
            if (ch != p) {
                dfs(ch, i);
                upd[i] += upd[ch];
            }
        }
    };

    dfs(1, 0);


    vector<ll> fans(N + 1, 0);

    ordered_multiset<ll> ord;

    function<void(ll, ll)> dfs2 = [&] (ll i, ll p) {
        for (auto&lv : lval[i]) {
            ord.insert(lv);
        }
        for (auto& ch : adj[i]) {
            if (ch != p) {
                fans[ch] += ord.order_of_key(age[ch]+1);
                dfs2(ch, i);
            }
        }

        for (auto&lv : lval[i]) {    
            ord.erase(ord.find_by_order(ord.order_of_key(lv)));
        }
    };

    dfs2(1, 0);


    for (ll i = 1; i <= N; i++) {
        fans[i] += upd[i];
        ll cur = 0;
        if ((ll)global.size() > 0) {
            cur = upper_bound(begin(global),end(global),age[i]) - begin(global);
        }
        fans[i] += cur;
    }

    // Vec<ll> final = {2, 1, 3, 1, 1, 2, 0, 2, 0, 1 };
    // for (auto& x : final) {
    //     cout << x << " ";   
    // }   cout << '\n';
    // return;

    for (ll i = 1; i <= N; i++) {
        cout << fans[i] << " ";
    }   cout << "\n";


}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    T = 1;
    for (ll tc = 1; tc <= T; tc++) {
        solve();
    }
    return 0;
}
