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
ll N, M;
auto solve() {
    cin >> N >> M;

    ll sum = N * (N + 1);
    if (sum % M >= 1 && sum % M <= N) {
        cout << "Bob\n";
    } else {
        cout << "Alice\n";
    }
    dbg(sum % M, N);
}   

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        // auto res = solve();
        solve();
    }
    return 0;
}
