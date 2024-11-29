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
    ll n;
    cin >> n;
    vector<ll> a(n + 1, -1), p(n + 1, 0);
    vector<ll> adj[n + 1];
    for (ll i = 1; i <= n; i++) cin >> a[i];
    for (ll i = 2; i <= n; i++){
        cin >> p[i];
        adj[p[i]].pb(i);
    }
    vector<bool> isLeaf(n + 1, false);
    Vec<ll> depth(n+1,0);
    function<void(ll, ll)>dfs = [&] (ll i, ll p) {
        for(auto&ch : adj[i]) {
            if (ch != p) {
                depth[ch] = depth[i] + 1;
                dfs(ch, i);
            }
        }
    };
    dfs(1,0);
    for (ll i = 1; i <= n; i++) {
        if (adj[i].size() == 0) {
            isLeaf[i] = true;
        }
    }
    dbg(isLeaf);
    const ll INF = 1e18;
    ll fans = 0;
    function<priority_queue<pair<ll,ll>,Vec<pair<ll,ll>>,greater<pair<ll,ll>>>(ll, ll)>dfs2 = [&] (ll i, ll p) {
        priority_queue<pair<ll,ll>,Vec<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
        ll sum = 0;
        for(auto&ch : adj[i]) {
            if (ch != p) {
                auto res = dfs2(ch, i);
                while(!res.empty()) {
                    pq.push(res.top());
                    res.pop();
                }
                sum += a[ch];
            }
        }
        if (i == 1) {
            dbg(i, sum, a[i]);
        }
        if (isLeaf[i]) {
            pq.push({depth[i], -INF});
        } else {
            if (a[i] == sum) {

            }
            else if (a[i] < sum) {
                pq.push({depth[i], a[i] - sum});
            }else{
                while (!pq.empty() && sum < a[i]) {
                    auto t = pq.top();
                    pq.pop();
                    ll d = t.second;
                    ll df = min(abs(d), a[i] - sum );
                    dbg("hello");
                    fans += df * (-depth[i] + t.first);
                    sum += df;
                    d += df;
                    if (d < 0) {
                        pq.push({t.first,d});
                    }
                }
            }
        }
        dbg(i,pq);
        return pq;
    };
    dfs2(1,0);

    dbg(depth);

    return fans;
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
