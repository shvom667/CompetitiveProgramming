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

// ============
const ll MOD = 998244353;
struct Mint {
    ll val;
    Mint() {
        val = 0;
    }
    Mint(int x) {
        x %= MOD; x += MOD; x %= MOD;
        val = x;
    }
    Mint operator*(Mint& other) {
        ll ans = (val*other.val)%MOD;
        return Mint(ans);
    }
    Mint operator+(Mint& other) {
        ll ans = (val + other.val) % MOD;
        return Mint(ans);
    }
    Mint operator-(Mint& other) {
        ll ans = (val - other.val) % MOD;
        ans %= MOD; ans += MOD; ans %= MOD;
        return Mint(ans);
    }
    Mint power(ll b) {
        if (b == 1) return val;
        if (b == 0) return 1ll;
        Mint a = power(b/2);
        a = a * a;
        if (b&1) {
            Mint b(val);
            a = a * b;
        }
        return a;
    }
    Mint operator/(Mint& other) {
        Mint a(val);
        Mint b = other.power(MOD-2);
        Mint ans= a * b;
        return ans;
    }
    friend std::ostream& operator<<(std::ostream& os, const Mint& m) {
        os << m.val;
        return os;
    }
};

auto solve() {
    
    ll n; cin >> n;
    vector<vector<ll>> adj(n + 1);
    for (ll i = 1; i < n; i++) {
        ll x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    vector<Mint>ans(n+1,0);ans[1]=1;
    vector<ll> depth(n+1,0);
    function<void(ll, ll)>dfs=[&](ll i, ll p)  {
        for(auto&ch:adj[i]){
            if(ch!=p){
                depth[ch]=depth[i]+1;
                dfs(ch,i);
            }
        }
    };
    vector<ll>minChild(n+1,1e9);
    function<void(ll, ll)>dfs2=[&](ll i, ll p)  {
        for(auto&ch:adj[i]){
            if(ch!=p){
                dfs2(ch,i);
                minChild[i]=min(minChild[i],minChild[ch]);
            }
        }
        if(minChild[i]==1e9)
            minChild[i]=min(minChild[i],depth[i]);
    };

    dfs(1,-1);
    dfs2(1,-1);
    dbg(depth);
    dbg(minChild);
    function<void(ll, ll)>dfs3=[&](ll i, ll p)  {
        if(minChild[i]==depth[i] || i==1){
            dbg(i);
        }else{
            ans[i]=ans[p];
            Mint d(minChild[i]-depth[i]+1);
            Mint e = ans[i] / d;
            ans[i]= ans[i] - e;
        }
        // dbg(i);
        for(auto&ch:adj[i]){
            if(ch!=p){
                dfs3(ch,i);
            }
        }
    };

    dfs3(1,-1);
    for(ll i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }   cout<<'\n';
    return 0;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        // cout << res << "\n";
    }
    return 0;
}
