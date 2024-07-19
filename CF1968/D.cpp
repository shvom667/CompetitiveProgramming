
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;

void solve();
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll t; 
  cin >> t; 
  while (t--) solve();
}
using pl=pair<ll,ll>;
void solve() {
    ll n;
    cin >> n;
    Vec<Vec<ll>> g(n+1, Vec<ll> (n+1, 0));
    for (int i = 1; i <= n/2; i++) {
        g[n][i] = 1;
    }
    g[n][n]=1;
    for (ll j=n-(n+1)/2;j>=1;j-=(n+1)/2) {
        g[j][n]=1;
    }
    
    ll c=0;
    for (ll i=1;i<=n;i++)
        for(ll j=1;j<=n;j++)
            if(g[i][j]==1)
                c++;
    ll left=n-c;
    for (ll i=1;i<=n;i++)
        if(g[i][n]==0&&left>0) {
            g[i][n]=1;
            c--;
        }
    Vec<pl> ans;
    for(ll i=1;i<=n;i++)
        for(ll j=1;j<=n;j++)
            if(g[i][j]==1)
                ans.pb({i,j});

    for(auto&[u,v]:ans)
        cout<<u<<" " << v<<'\n';
}
