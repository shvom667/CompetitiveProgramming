#include<bits/stdc++.h>
using namespace std;
using ll=int;
#define pb push_back
template <typename T>
using Vec = vector<T>;
 
#ifndef ONLINE_JUDGE
    #include"/home/shivom/Downloads/CompetitiveProgramming/DataStructures/debug.cpp"
#else
    #define dbg(...) 42
#endif

vector<ll> g[20];
auto pre() {
    for (ll s = 1; s <= 19; s++) {
        ll cntOdd = 0, cntEven = 0;
        ll fans = 0;
        for (ll i = 1; i < (1ll<<s); i++) {
            vector<ll> v(s, 0);
            for (ll b = 0; b < s; b++) {
                if (i & (1ll<<b)) {
                    for (ll k = b; k < s; k += b+1) {
                        v[k] ^= 1;
                    }
                }
            }
            ll cnt = count(begin(v),end(v),1);
            if (cnt <= s/5) {
                // for (ll b = 0; b < s; b++) {
                //     if (i & (1ll<<b)) {
                //         cout << "1";
                //     } else {
                //         cout << "0";
                //     }
                // }
                // cout << "\n";
                // cout << i << "\n";
                // if (i&1) cntOdd++;
                // else cntEven++;
                g[s].pb(i);
                // fans++;
            }
        }
        // cout << cntOdd << " " << cntEven << "\n";
        // cout << fans << "\n";
    }
}

vector<ll> bf(ll n,ll m,set<pair<ll,ll>> c) {
    vector<ll>res;
    if(n>=20){
        for(ll i=0;i<n;i++){
            res.pb(i);
        };
        return res;
    }
    for(auto&mask:g[n]){
        bool ok=true;
        for(auto[x,y]:c){
            x--;y--;
            if((mask&(1ll<<x))){ 
                if ((mask&(1ll<<y))){

                }else{
                    ok=false;
                }
            }
        }

        if(ok){
            for(ll b=0;b<n;b++){
                if((1ll<<b)&mask){
                    res.pb(b);
                }
            }
            return res;
        }
    }
    res.clear();res.pb(-1);
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    pre();
    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        ll n,m;
        cin>>n>>m;
        set<pair<ll,ll>>c;
        for(ll i=0;i<m;i++){
            ll x,y;
            cin>>x>>y;
            c.insert({x,y});
        }
        auto res = bf(n,m,c);
        if(res[0]==-1){
            cout<<-1<<'\n';
        }else{
            cout<<res.size()<<'\n';
            for(auto&x:res){
                cout<<x+1<<" ";
            }cout<<'\n';
        }
    }
    return 0;
}
