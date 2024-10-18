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
    ll wgl, wgr, sl, sr;
    wgl = wgr = sl = sr = 0;
    ll server=0;
    auto print = [&]() {
        if (max(wgl,wgr) >= 2) {
            if (wgl > wgr) {
                cout << wgl << " (winner) - " << wgr << "\n"; 
            } else {
                cout << wgl << " - " << wgr << " (winner) \n";
            }
        } else {
            if (server == 0) {
                cout << wgl << " (" << sl << "*) - " << wgr << " (" << sr << ") " << "\n";
            } else {
                cout << wgl << " (" << sl << ") - " << wgr << " (" << sr << "*) " << "\n";
            }
        }
    };

    string s;
    cin >> s;
    for (ll i = 0; i < s.size(); i++) {
        if (s[i] == 'Q') {
            print();
            continue;
        }
        if (s[i] == 'S') {
            if (server == 0) {
                sl++;
            }
            if (server == 1){
                sr++;
            }
        }
        if (s[i] == 'R') {
            if (server == 0) {
                sr++;
            }
            if (server == 1) {
                sl++;
            }
            server ^= 1;
        }
        // print();
        if (max(sl, sr) == 10 || (abs(sl-sr)>=2 && max(sl,sr) >= 5)) {
            // cout << "$$$$$$$$$$$$$$$$44\n";
            if (sl > sr) {
                wgl++;
                server = 0;
            } else {
                wgr++;
                server = 1;
            }

            sl = 0;
            sr = 0;
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;

    T = 1;
    for (ll tc = 1; tc <= T; tc++) {
        // auto res = solve();
        // cout << res << "\n";
        solve();
    }
    return 0;
}
