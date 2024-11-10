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

struct p3
{
    ll a, b, c;
    /* data */
};

p3 make(ll a, ll b, ll c) {
    p3 x;
    x.a = a;
    x.b = b;
    x.c = c;
    return x;
}

void print(p3 x) {
    cout << x.a << " " << x.b << " " << x.c << "\n";
}

void give(vector<p3> fans) {
    cout << fans.size() << "\n";
    for (auto&x  : fans) {
        print(x);
    }
}


 
auto solve() {
    ll n, m;
    cin >> n >> m;

    vector<ll> deg(n + 1, 0);

    vector<set<ll>> adj(n + 1);

    for (ll i = 1; i <= m; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
        deg[u]++;
        deg[v]++;
    }

    // Vec<bool> syn(n + 1, false);
    // function<void(int, int)> dfs = [&] (ll i, ll p) {
    //     syn[i] = true;
    //     for (auto& ch : adj[i]) {
    //         if (ch != p) {
    //             dfs(ch, i);
    //         }
    //     }
    // };

    // dfs(1, -1);

    priority_queue<pair<ll, ll>> pq;

    for (ll i = 1; i  <= n; i++) {
        pq.push({deg[i], i});
    }

    vector<ll> cur_deg(n + 1, 0);
    cur_deg = deg;

    vector<p3> fans;

    dbg(deg);

    while (!pq.empty() && pq.top().first >= 2) {            
        pair<ll, ll> t = pq.top();
        pq.pop();

        // dbg(t);
        if (cur_deg[t.second] < t.first) {
            continue;
        }
        dbg(t);

        ll a = *adj[t.second].rbegin();
        adj[t.second].erase(a);

        ll b = *adj[t.second].rbegin();
        adj[t.second].erase(b);

        deg[t.second] -= 2;
        cur_deg[t.second] = deg[t.second];
        if (cur_deg[t.second] >= 2)
            pq.push({cur_deg[t.second], t.second});

        fans.pb(make(a,b,t.second));

        dbg(a, b);

        adj[b].erase(t.second);
        adj[a].erase(t.second);
        deg[b] -= 1;
        deg[a] -= 1;

        if (adj[b].count(a)) {
            dbg("hello");
            adj[b].erase(a);
            adj[a].erase(b);
            deg[b] -= 1;
            deg[a] -= 1;
            cur_deg[b] = deg[b];
            cur_deg[a] = deg[a];

            if (cur_deg[b] >= 2)
                pq.push({cur_deg[b], b});

            if (cur_deg[a] >= 2)
                pq.push({cur_deg[a], a});
        } else {
            adj[b].insert(a);
            adj[a].insert(b);
            deg[a] += 1;
            deg[b] += 1;
        }
    }   

    for (ll i = 1; i <= n; i++) {
        dbg(adj[i]);
    }

    ll v = -1;
    for (ll i = 1; i <= n; i++) {
        if (cur_deg[i] == 1)  v = i;
    }

    if (v == -1) {
        give(fans);
        return;
    }

    dbg(v);

    ll a, b;
    a = v;
    b = *adj[v].begin();

    vector<bool> seen(n + 1, false);

    seen[a] = true; seen[b] = true;
    for (ll i = 1; i <= n; i++) {
        if (seen[i]) continue;
        seen[i] = true;
        fans.pb(make(a, b, i));
        a = a;
        b = i;
        for (auto&j : adj[i])  {
            seen[j] = true;
        }
    }

    give(fans);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        dbg(tc);
        solve();
    }
    return 0;
}
