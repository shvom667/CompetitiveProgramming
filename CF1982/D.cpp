#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define i32 int
#define pb push_back
#define ALL(x) begin(x), end(x)
#define SZ(x) (ll)(x.size())
#define OVERRIDE(a, b, c, d, ...) d
#define REP2(i, n) for (i32 i = 0; i < (i32)(n); ++i)
#define REP3(i, m, n) for (i32 i = (i32)(m); i < (i32)(n); ++i)
#define REP(...) OVERRIDE(__VA_ARGS__, REP3, REP2)(__VA_ARGS__)
#define PER(i, n) for (i32 i = (i32)(n) - 1; i >= 0; --i)

template <typename T>
using Vec = vector<T>;
template<typename T>
vector<T> PrefixSum(vector<T> X) {
    ll n = X.size();
    vector<T> ret(n, 0);
    REP (i, n) {
        ret[i] = X[i];
        if (i > 0) ret[i] += ret[i - 1];
    }
    return ret;
}
template<typename T>
void chmax(T& a, T b) {
    a = max(a, b);
}
template<typename T>
void chmin(T& a, T b) {
    a = min(a, b);
}
void solve() {
    ll n,m,k;
    cin >> n >> m >> k;
    ll g[n+1][m+1],p[n+1][m+1];
    char b[n+1][m+1];
    for(ll i =0; i<=n;i++)for(ll j=0;j<=m;j++){
        g[i][j]=0;
        p[i][j]=0;
    }
    for(ll i =1; i<=n;i++)for(ll j=1;j<=m;j++)
    {
        cin >> g[i][j];
    }    
    for(ll i =1; i<=n;i++)for(ll j=1;j<=m;j++)
    {
        cin >> b[i][j];
    }    
    ll sum=0;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            if(b[i][j]=='0'){
                g[i][j] = -g[i][j];
            }
            sum += g[i][j];
        }
    }
    sum=abs(sum);
    for(ll i =1; i<=n;i++)for(ll j=1;j<=m;j++)
    {
        p[i][j] = (b[i][j]=='1'?1:-1);
        p[i][j] += p[i-1][j];
        p[i][j] += p[i][j-1];
        p[i][j] -= p[i-1][j-1];
    }
    ll gf=0;
    Vec<ll> fc;
    // i,j     i,j+k-1
    //i+k-1,j   i+k-1,j+k-1
    for(ll i=1;i+k-1<=n;i++){
        for(ll j=1;j+k-1<=m;j++){
            fc.pb(
                abs(p[i+k-1][j+k-1]
                - p[i-1][j+k-1]
                - p[i+k-1][j-1]
                + p[i-1][j-1])
            );
        }   
    }
    auto gcd = [&](ll x, ll y){
        if(x==0||y==0) return max(x,y);
        return __gcd(x,y);
    };
    for(auto&x:fc){
        if(x==0)continue;
        gf=gcd(gf,x);
    }
    if(gf==0 and sum!=0){
        cout<<"NO\n";return;
    }
    cout<<(sum==0||sum%gf==0?"YES\n":"NO\n");
}

int main() {

    ll t;
    t = 1;
    cin>>t;
    while (t--) {
        solve();
    }
}
/*
x 

-c   F - x123 413 24 233
123 42 0 216
22 1 1 53
427 763 22 6

1. [k*k] (q1-p1)

2. [k*k] (q2-p2)

39  -30  -0  -17
22   42   30  13
-10  -44  46  35
-12   19  9   39
21    0  -45 -40


*/