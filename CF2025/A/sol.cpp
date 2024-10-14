#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;
 
#ifndef ONLINE_JUDGE
    #include"/home/shivom/Downloads/CompetitiveProgramming/DataStructures/debug.cpp"
#else
    #define dbg(...) 42
#endif
 
auto solve() {
    string a, b;
    cin >> a >> b;
    ll cnt = min((ll)a.size(),(ll)b.size());
    for (ll i = 0; i < min((ll)a.size(), (ll)b.size()); i++) {
        if (a[i] != b[i]) {
            cnt=i;
            break;
        }
    }

    return min((ll)a.size()+(ll)b.size(), (ll)a.size()+(ll)b.size()-cnt+1);
}

int main() {
    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        cout << res << "\n";
    }
    return 0;
}
