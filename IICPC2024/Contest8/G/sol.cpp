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
    string s;
    int k;
    cin >> s >> k;
    vector<deque<ll>> ind(26);
    ll n = s.size();
    for (ll i = 0; i < n; i++) {
        ind[s[i] - 'a'].push_back(i);
    }

    string res = "";
    
    for (ll i = 0; i < 3; i++) {
        dbg(ind[i]);
    }
    // for (ll j = 0; j < 26; j++) {
    // for (ll )
    //     for (ll k = 0; k < ind[j].size(); k++) {
    //         if (ind[j][k] < g) continue;
    //         if (ind[j][k] <= -sz - 1 + n) {
    //             res += 'a' + j;
    //             g = ind[j][k];
    //             sz--;
    //         }
    //     }
    // }
    ll g = -1;
    for (ll sz = k; sz >= 1; sz--) {
        dbg(g);
        for (ll i = 0; i < 26; i++) {
            while (!ind[i].empty() && ind[i].front() < g) {
                ind[i].pop_front();
            }
            if (ind[i].front() == 6) {
                dbg("hello");
            }
            if (!ind[i].empty() && ind[i].front() <= n - sz) {
                
                g = ind[i].front();
                ind[i].pop_front();
                res += 'a' + i;
                break;
            }
        }
    }

    return res;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    T = 1;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        cout << res << "\n";
    }
    return 0;
}
