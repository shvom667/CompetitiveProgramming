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
 
auto solve() {
    ll n,m;cin>>n>>m;ll g[n+1][m+1];
    if(n==4){
        for(ll v=1,j=1;j<=m;j++){
            for(ll i=1;i<=n;i++){
                g[i][j]=v++;
            }
        }
        for(ll i=1;i<=n;i++)for(ll j=1;j<=m;j++){
            cout<<g[i][j]<<" \n"[j==m];
        }

        return 0;
    }
    for (ll i=1;i<=(n+1)/2;i++){
        g[i][1] = (2*i - 2) * m+1; 
    }
    for(ll j=1,i=(n+1)/2+1;i<=n;i++,j+=2){
        g[i][1] = j*m+1;
    }
    for(ll i=1;i<=n;i++){
        for(ll j=2;j<=m;j++){
            g[i][j] = g[i][j-1]+1;
        }
    }
    for(ll i=1;i<=n;i++)for(ll j=1;j<=m;j++)
    {
        cout<<g[i][j]<<" \n"[j==m];
    }
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
