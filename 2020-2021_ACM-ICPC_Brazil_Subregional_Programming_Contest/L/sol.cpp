#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;
 
#ifndef ONLINE_JUDGE
    #include"/home/shivom/Downloads/CP/DataStructures/debug.cpp"
#else
    #define dbg(...) 42
#endif
 
auto solve() {
    ll n, m;
    cin >> n >>m;
    ll g[n][m];
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {

            char x;
            cin >> x;
            g[i][j] = x - 'A';
        }
    }
    ll cnt_words;
    cin >> cnt_words;
    vector<ll> words[cnt_words];
    for (ll i = 0; i < cnt_words; i++) {
        string s;
        cin >> s;
        words[i] = vector<ll> (26, 0);
        for (ll j = 0; j < s.size(); j++){
            words[i][s[j] - 'A']++;
        }
    }

    set<ll> anas[n][m];
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            // dbg(i, j);
            vector<ll> ca(26, 0);
            for (ll k = j; k < min(m, j + 15); k++) {
                // dbg(k);

                // dbg(g[i][k]);
                ca[g[i][k]]++;
                // dbg(k);
                for (ll wn = 0; wn < cnt_words; wn++) {
                    if (ca == words[wn]) {
                        for (ll pos = j; pos <= k; pos++){
                            anas[i][pos].insert(wn);
                        }
                    }
                }
                // dbg(k);
            }
        }
    }

    for (ll j = 0; j < m; j++) {
        for (ll i = 0; i < n; i++) {
            vector<ll> ca(26, 0);
            for (ll k = i; k < min(n, i + 15); k++) {
                ca[g[k][j]]++;
                for (ll wn = 0; wn < cnt_words; wn++) {
                    if (ca == words[wn]) {
                        for (ll pos = i; pos <= k; pos++) {
                            anas[pos][j].insert(wn);
                        }
                    }
                }
            }
        }
    }
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++)  {
            vector<ll> ca(26, 0);
            for (ll k = 1; k <= 15; k++) {
                if (i + k - 1 >= n || j + k - 1 >= m) break;
                if (i + k - 1 < n && j + k - 1 < m) {
                    ca[g[i+k-1][j+k-1]]++;
                }
                // if (i == 0 && j == 1) {
                //     dbg(g[i+k-1][j+k-1], k);
                // }
                for (ll wn = 0; wn < cnt_words; wn++) {
                    if (ca == words[wn]) {
                        for (ll pos = 1; pos <= k; pos++) {
                            anas[i+pos-1][j+pos-1].insert(wn);
                            // dbg(i,j,k);
                        }
                    }
                }

            }
        }
    }
    dbg("hello");

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++)  {
            vector<ll> ca(26, 0);
            for (ll k = 1; k <= 15; k++) {
                if (i + k - 1 >= n || j - k + 1 < 0) break;
                if (i + k - 1 < n && j - k + 1 >= 0) {
                    ca[g[i+k-1][j-k+1]]++;
                }

                for (ll wn = 0; wn < cnt_words; wn++) {
                    if (ca == words[wn]) {
                        for (ll pos = 1; pos <= k; pos++) {
                            anas[i+pos-1][j-pos+1].insert(wn);
                        }
                    }
                }

            }
        }
    }
    // dbg("hello");

    ll fans = 0;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            if (anas[i][j].size() >= 2) {
                fans++;
            }
        }
    }

    // for (ll i = 0; i < n; i++) {
    //     for (ll j = 0; j < m; j++) {
    //         cout << anas[i][j].size() << " ";
    //     }
    //     cout << "\n";
    // }

    return fans;
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
