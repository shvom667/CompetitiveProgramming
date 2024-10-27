#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ss second
#define ll long long int
#define lld long double
#define pll pair <ll, ll> 
#define yes cout<<"Yes\n"
#define no cout<<"No\n"
#define br cout<<"\n";
#define llh __int128
#define f(i,a,b) for(ll i = (a); i < (b); i++)
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
const ll M =  1e9+7;
const ll N = 4e5+20;
const llh H = (1ll<<61)-1;



ll binpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1; 
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

vector <ll> fact(N, 1), invf(N, 1);
ll ncr(ll n, ll r){
    ll ans = fact[n]; ans *= invf[r]; ans %= M; ans *= invf[n-r]; ans %= M;
    return ans;
}


void solve(ll tt, ll TT){
    ll n, m; cin>>n>>m; 
    vector <ll> a(n+1); f(i, 1, n+1){cin>>a[i];}
    vector <ll> b(m+1); f(i, 1, m+1){cin>>b[i];}
    ll dp[m+1][n+1];
    vector <ll> pref(n+1, 0);
    f(i, 0, m+1){
        f(j, 0, n+1){
            dp[i][j] = 1e18;
        }
        dp[i][0] = 0;
    }
    f(i, 1, n+1){
        pref[i] += a[i]; 
        pref[i] += pref[i-1]; 
    }
    f(i, 1, m+1){
        f(j, 1, n+1){
            dp[i][j] = dp[i-1][j];
            // find the last index where sum <= 
            //if(a[j] > b[i]){continue;}
            ll idx = lower_bound(pref.begin(), pref.end(), pref[j]-b[i])-pref.begin();
            if(idx <= j && idx >= 0){
                dp[i][j] = min(dp[i][j], dp[i][idx]+m-i);
            }
            //cout<<dp[i][j]<<" ";
        }//br;
    }
    if(dp[m][n] == 1e18){dp[m][n] = -1;}
    cout<<dp[m][n]; br; return;
}  

int main() {
    fastio();
    ll TT = 1;
  //  fn();
//    cin >> TT;
    // f(i, 1, N){
    //     fact[i] = (fact[i-1]*i) % M;
    //     invf[i] = binpow(fact[i], M-2, M);
    // }
    f(tt, 1, TT+1){
        solve(tt, TT);
    }
    return 0; 
}
