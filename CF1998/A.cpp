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
    ll x, y, k;
    cin >> x >> y >> k;
    Vec<ll> fx,fy;
    
    if(k&1){
        fx.pb(k*x);
        for(ll i=k+1;i<=2*k-1;i+=2){
            fx.pb(2*i*(x!=-5?x+5:x+7)*(1));
            fx.pb(2*i*(x!=-5?x+5:x+7)*(-1));
        }

        fy.pb(k*y);
        for(ll i=k+1;i<=2*k-1;i+=2){
            fy.pb(2*i*(y!=-5?y+5:y+7)*(1));
            fy.pb(2*i*(y!=-5?y+5:y+7)*(-1));
        }
    }else{
        if (x == 0 && y == 0) {
            for(ll i = 1; i <= k; i+=2) {
                cout << i << " " << -i << '\n';
                cout << -i << " " << i << "\n";
            }
            return;
        }
        fx.pb(((k+2)/2)*x);
        fx.pb(((k-2)/2)*x);
        for(ll i=k+1;i<=2*k-2;i+=2){
            fx.pb(2*i*(x!=-5?x+5:x+7)*(1));
            fx.pb(2*i*(x!=-5?x+5:x+7)*(-1));
        }

        fy.pb(((k+2)/2)*y);
        fy.pb(((k-2)/2)*y);
        for(ll i=k+1;i<=2*k-2;i+=2){
            fy.pb(2*i*(y!=-5?y+5:y+7)*(1));
            fy.pb(2*i*(y!=-5?y+5:y+7)*(-1));
        }
        
    }
    for(ll i = 0; i < k; i++){
        cout << fx[i] << " " << fy[i] << "\n";
    }
}

int main() {

    ll t;
    t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
