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


const ll N = 2e5 + 20;
ll p2[N];

const ll INF  = 1e13;

auto solve() {
    ll n, k;
    cin >> n >> k;

    if (p2[n - 1] != -1 && p2[n - 1] < k) {
        cout << -1 << '\n';
        return;
    }

    vector<ll> f(n);

    function<void(ll,ll,ll,ll,ll)> dfs = [&] (ll l, ll r, ll k, ll sz, ll val) {
        if(val==n){
            assert(sz==0);
            return;
        }
        if (sz == 1) {
            f[l] = val;
            return;
        }
        assert(sz >= 2);
        dbg(l,r,sz,k);
        if (p2[sz-2] == -1 || p2[sz-2]  >=  k) {
            f[l] = val;
            dfs(l+1,r,k,sz-1,val+1);
        } else {
            f[r] = val; 
            dfs(l,r-1,k-p2[sz-2],sz-1,val+1);
        }
    };

    dfs(0,n-1,k,n,0);

    for(auto&x:f){
        cout<<x+1<<" ";
    }   cout<<'\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(ll i=0;i<N;i++){
        p2[i] = -1;
        // F[i] = -1;
    }

    p2[0] = 1;
    // F[0] = 1;

    for(ll i=1;i<N;i++){
        p2[i] = p2[i - 1] * 2;
        if (p2[i] > INF) break;
    }

    // for(ll i=1;i<N;i++){
    //     F[i] = F[i - 1] * i;
    //     if (F[i] > INF) break;
    // }


    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        solve();
    }
    return 0;
}
