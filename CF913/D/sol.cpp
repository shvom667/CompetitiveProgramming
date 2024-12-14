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

auto solve() {
    ll n, T;
    cin >> n >> T;
    vector<ll> a(n), t(n);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    map<pair<ll, ll>, vector<ll>> pno;
    for (ll i = 0; i < n; i++) {
        cin >> a[i] >> t[i];
        pq.push({t[i], a[i]});
        pno[{t[i], a[i]}].push_back(i);
    }


    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq_in;
    ll tot_time = 0;

    ll fans = 0;
    for (ll ans = 1; ans <= n; ans++) {
        while (!pq_in.empty() && pq_in.top().first < ans) {
            tot_time -= pq_in.top().second;
            pq_in.pop();
        }
        while (!pq.empty() && pq_in.size() < ans) {
            auto t = pq.top();
            pq.pop();
            if (t.second < ans) {
                continue;
            }
            if (t.first + tot_time > T) {
                break;
            }
            tot_time += t.first;
            pq_in.push({t.second,t.first});
        }
        dbg(pq_in);
        if (pq_in.size() < ans) {

            fans = ans - 1;
            break;
        }
        if (ans == n) {
            cout << n << '\n';
            cout << n << '\n';
            for (ll i = 1; i <= n; i++) {
                cout << i << " ";
            }   cout << '\n';
            return 0;
        }
    }

    dbg(fans);

    while (!pq.empty()) pq.pop();
    while (!pq_in.empty()) pq_in.pop();
    tot_time = 0;

    for (ll i = 0; i < n; i++) {
        cin >> a[i] >> t[i];
        pq.push({t[i], a[i]});
    }
    dbg("hello");

    if (fans == 0) {
        cout << 0 << '\n';
        cout << 0 << '\n';
        return 0;
    }

    dbg(pq);
    dbg(pq_in);

    dbg(pno);

    for (ll ans = 1; ans <= n; ans++) {
        dbg(ans);
        while (!pq_in.empty() && pq_in.top().first < ans) {
            tot_time -= pq_in.top().second;
            pq_in.pop();
        }
        while (!pq.empty() && pq_in.size() < ans) {
            auto t = pq.top();
            pq.pop();
            if (t.second < ans) {
                continue;
            }
            if (t.first + tot_time > T) {
                break;
            }
            tot_time += t.first;
            pq_in.push({t.second,t.first});
        }
        dbg(pq_in);
        if (fans == ans) {
            cout << fans << '\n';
            cout << fans << '\n';
            while (!pq_in.empty()) {
                auto t = pq_in.top();
                // dbg(t);
                cout << pno[{t.second, t.first}].back() + 1 << ' ';
                pno[{t.second, t.first}].pop_back();
                pq_in.pop();
            }
            cout << '\n';
                
            return 0;
        }
        if (pq_in.size() < ans) {
            
            fans = ans - 1;
            break;
        }
        if (ans == n) {
            cout << n << '\n';
            cout << n << '\n';
            for (ll i = 1; i <= n; i++) {
                cout << i << " ";
            }   cout << '\n';
            return 0;
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    T = 1;
    for (ll tc = 1; tc <= T; tc++) {
	    auto res = solve();
	    // cout << res << "\n";
    }
    return 0;
}
