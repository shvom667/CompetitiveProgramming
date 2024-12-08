#include <bits/stdc++.h>
using namespace std;
using ll = int;
#define pb push_back
template <typename T>
using Vec = vector<T>;

#ifndef ONLINE_JUDGE
#include "/home/shivom/Downloads/CP/DataStructures/debug.cpp"
#else
#define dbg(...) 42
#endif



mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
int rnd(int x, int y) {
  return uniform_int_distribution<int>(x, y)(rng);
}
const ll N = 2e5+20;
const ll m = 600;
ll L2[N];

auto solve(ll n, vector<ll> a, Vec<ll> b) {

    vector<ll>fans;
    for(ll k=1;k<=min(n,m);k++){
        bool ok=true;

        for(ll i = 0; i < n; i++) {
            ll z1, z2;
            z1 = (a[i] - 1) / k;
            z2 = (b[i] - 1) / k;
            if (z1 < z2 + 1) {

            } else {
                ok = false;
            }
        }

        if(ok){
            fans.pb(k);
        }
    }

    vector<ll>mb(n,0);for(ll i=0;i<n;i++)mb[i]=i;


    for(ll i=0;i<n;i++){
        mb[a[i]-1]=min(mb[a[i]-1],b[i]-1);
    }


    ll f[n][30];
    for(ll i=0;i<n;i++)f[i][0]=mb[i];

    for(ll j=1;j<30;j++){
        for(ll i=0;i<n;i++){
            f[i][j]=min(f[i][j-1],f[min(n-1,i+(1<<(j-1)))][j-1]);
        }
    }

    auto get=[&](ll l, ll r){
        ll l2=L2[r-l+1];
        return min(f[l][l2],f[r-(1<<l2)+1][l2]);
    };

    dbg(mb);
    
    for(ll k=m+1;k<=n;k++){
        bool ok=true;
        for(ll b=0;b*k<n;b++){
            if(get(b*k,min(n-1,(b+1)*k-1))<(b)*k){
                ok=false;
            }   
        }
        if(ok){
            fans.pb(k);
        }
    }

    return fans;
}


auto bf(ll n, vector<ll> a, Vec<ll> b) {
    Vec<ll>fans;

    for(ll k=1;k<=n;k++){
        bool ok=true;

        for(ll i = 0; i < n; i++) {
            ll z1, z2;
            z1 = (a[i] - 1) / k;
            z2 = (b[i] - 1) / k;
            if (z1 < z2 + 1) {

            } else {
                ok = false;
            }
        }

        if(ok){
            fans.pb(k);
        }
    }
    return fans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    L2[1]=0;
    for(ll v=2,cnt=1;v<N;v*=2,cnt++){
        L2[v]=cnt;
    }
    for(ll i=2;i<N;i++){
        if(L2[i]>0)continue;
        L2[i]=L2[i-1];
    }


    ll T;
    T = 1;
    // cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        ll n;
        cin >> n;
        vector<ll> a(n), b(n);
        for(ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(ll i = 0; i < n; i++) {
            cin >> b[i];
        }
	    auto res = solve(n, a, b);
        cout << (ll) res.size() << '\n';
        for(auto&x: res){
            cout<<x<<' ';
        }   cout<<'\n';
    }
    return 0;
}
