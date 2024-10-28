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
 
auto solve() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N), B(N);
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<pair<ll,ll>> E1, E2;
    ll M1, M2;
    cin >> M1;
    for (ll j = 0; j < M1; j++) {
        ll u, v;
        cin >> u >> v;
        E1.push_back({u, v});
    }
    for (ll i = 0; i < N; i++) {
        cin >> B[i];
    }
    cin >> M2;
    for (ll j = 0; j < M2; j++) {
        ll u, v;
        cin >> u >> v;
        E2.pb({u, v});
    }
    dbg(A, B);
    string res = "NO";
    if (count(begin(A),end(A), 1) != count(begin(B),end(B), 0)) {
        return res;
    }
    if ( (count(begin(A), end(A), 1) == N &&  count(begin(B), end(B), 0) == N) || (count(begin(A), end(A), 0) == N && count(begin(B), end(B), 1) == N)) {
        res = "YES";
        return res;
    }
    dbg(N);
    if (K == 2) {
        res = "YES";
        return res;
    }
    return res;
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
