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
 
    vector<ll> act;

auto solve() {
    ll A, B, M;
    cin >> A >> B >> M;
    ll fans = 0;
    for (auto& x : act) {
        if (x <= B && x % M == 0)
            fans++;
        if (x <= A - 1 && x % M == 0)
            fans--;
    }
    return fans;
} 

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);   

    auto conv = [&] (deque<ll> d) {
        ll p10 = 1;
        ll res = 0;
        for (ll i = 0; i < d.size(); i++) {

            res += p10 * d[i];
            p10 *= 10;
        }   
        return res;
    };

    for (ll k = 0; k <= 8; k++) {
        for (ll mid = k + 1; mid <= 9; mid++) {
            deque<ll> num;
            num.pb(mid);
            for(ll i = 1; i <= k; i++) {
                num.push_front(mid-i);
                num.push_back(mid-i);
            }
            dbg(num);
            act.pb(conv(num));
        }
    }
    
    dbg(act);
    sort(begin(act),end(act));

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        cout << "Case #" << tc << ": " << res << "\n";
    }
    return 0;
}
