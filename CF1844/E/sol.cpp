#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
    #include"/home/shivom/Downloads/CP/DataStructures/debug.cpp"
    #include"/home/shivom/Downloads/CP/DataStructures/dsu.cpp"
#else
    #define dbg(...) 42
#endif
 
string solve(ll n, ll m, ll k, vector<ll> x1, vector<ll> y1, vector<ll> x2, vector<ll> y2) {
    string res;
    vector<vector<ll>> g(n + 1, vector<ll> (m + 1, 0));
    dbg(x1,y1);
    auto conv = [&](ll i, ll j) {
        return (i - 1) * m + j;
    };
    auto conv_back = [&] (ll val) {
        ll x = (val + m - 1) / m;
        ll y = val % m == 0 ? m : val%m;
        return make_pair(x, y);
    };
    DSU d(n * m + 10);

    for(ll i = 0; i < k; i++) {
        dbg(x1[i], y1[i]);
        dbg(conv(x1[i], y1[i]), conv(x2[i], y2[i]));
        d.unite(conv(x1[i], y1[i]), conv(x2[i], y2[i]));
    }

    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            g[i][j] = d.get(conv(i,j));
        }
    }

    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            cout << g[i][j] << " ";
        }   cout << '\n';
    }

    return res;
}
string bf(ll n, ll m, ll k, vector<ll> x1, vector<ll> y1, vector<ll> x2, vector<ll> y2) {
    string res;
    res="NO";
    auto next=[&](ll i, ll j){
        if(j==m-1){
            return make_pair(i+1, 0ll);
        }
        return make_pair(i, j + 1);
    };
    set<vector<vector<char>>> S;
    vector<vector<char>>g(n, vector<char>(m, '$'));
    function<void(ll,ll)>dfs=[&](ll i, ll j){
        auto nxt = next(i,j);
        if(i==n){
            bool ok=true;
            for (ll i = 0; i < n; i++) {
                for (ll j = 0; j < m ;j++) {
                    if (i + 1 < n) {
                        if (g[i][j] == g[i + 1][j])
                            ok = false;
                    }
                    if (j + 1 < m) {
                        if (g[i][j] == g[i][j+1]) {
                            ok=false;
                        }
                    }
                }
            }
            for (ll i = 0; i < n; i++) {
                for (ll j = 0; j < m; j++) {
                    if (i + 1 < n && j + 1 < m) {
                        bool ok_a = g[i][j]=='A' || g[i + 1][j] == 'A' || g[i][j + 1] == 'A' || g[i + 1][j + 1] == 'A';
                        bool ok_b = g[i][j]=='B' || g[i + 1][j] == 'B' || g[i][j + 1] == 'B' || g[i + 1][j + 1] == 'B';
                        bool ok_c = g[i][j]=='C' || g[i + 1][j] == 'C' || g[i][j + 1] == 'C' || g[i + 1][j + 1] == 'C';
                        if (ok_a && ok_b && ok_c) {

                        } else {
                            ok=false;
                        }
                    }
                }
            }
            // for (ll itr=0;itr<k;itr++){
            //     if(g[x1[itr]-1][y1[itr]-1] != g[x2[itr]-1][y2[itr]-1]) ok=false;
            // }
            if (ok) {
                for (ll i = 0; i < g.size(); i++) 
                {
                    for (ll j = 0; j < g[i].size(); j++)
                    {
                        cout << g[i][j];     
                    }   cout << "\n";
                }
                S.insert(g);
                cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$4\n";
                res="YES";
            }
            return;
        }
        g[i][j] = 'A';
        dfs(nxt.first, nxt.second);
        g[i][j] = 'B';
        dfs(nxt.first, nxt.second);
        g[i][j] = 'C';
        dfs(nxt.first,nxt.second);
    };
    dfs(0,0);
    cout << S.size() << '\n';
    for (auto&gr:S){
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                cout << gr[i][j];
            }   cout << "\n";
        }
        cout << "$$$$$$$$$$$$$$$$$$\n";
    }
    for (auto& gr: S) {
        int p[3][2];
        for (ll i = 0; i < 3; i++) for (ll j = 0; j < 2; j++) p[i][j] = 0;
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                p[gr[i][j]-'A'][(i+j)%2]++;
            }      
        }
        bool ok=false;
        for (ll i = 0; i < 3; i++) {
            if (p[i][0]==0 || p[i][1] == 0) {
                ok=true;
            }
        }
        if (!ok) {
            for (ll i = 0; i  < n; i++) {
                for (ll j = 0; j < m; j++) {
                    cout << gr[i][j] << " ";
                }cout<<'\n';
            }
            exit(0);
        }
        cout << "$$$$$$$$$$$$$$$$$$\n";
    }
    ll gmax=0;
    for (auto&gr : S) {
        ll lmax=0;
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                if (i + 1 < n && j + 1 < m && gr[i][j] == gr[i+1][j+1]) {
                    lmax++;
                }
                if (j + 1 < m && i - 1 >= 0 && gr[i][j] == gr[i-1][j+1]) {
                    lmax++;
                }
            }
        }
        gmax = max(gmax, lmax);
    }
    cout << gmax << "\n";
    return res;
}

int main() {
	// ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        ll n, m, k;
        cin >> n >> m >> k;
        vector<ll> x1(k),x2(k),y1(k),y2(k);
        for (ll i = 0; i < k; i++) {
            cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        }
        auto res = bf(n, m, k, x1, y1, x2, y2);
        cout << res << "\n";
    }
    return 0;
}
