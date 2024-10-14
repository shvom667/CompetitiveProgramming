#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;
 
#ifndef ONLINE_JUDGE
    #include"/home/shivom/Downloads/CompetitiveProgramming/DataStructures/debug.cpp"
#else
    #define dbg(...) 42
#endif

auto chmax(ll &a, ll b){
    a=max(a,b);
}
 
auto solve() {
    ll n;
    cin >> n;
    vector<vector<char>> g(2, vector<char>(n));
    for(ll j=0;j<2;j++)
    for(ll i=0;i<n;i++){
        cin>>g[j][i];
    }

    auto get=[&](char a,char b,char c){
        vector<char>C;
        C.pb(a);C.pb(b);C.pb(c);
        sort(begin(C),end(C));
        if(C[0]=='A'&&C[1]=='A')return 1;
        return 0;
    };

    vector<vector<ll>> dp(n, vector<ll> (3, 0));

    dp[1][1] = get(g[0][0],g[1][0],g[0][1]);
    dp[1][2] = get(g[0][0],g[1][0],g[1][1]);
    dp[2][0] = get(g[0][0],g[0][1],g[0][2]) + get(g[1][0],g[1][1],g[1][2]);
    chmax(dp[2][0], dp[1][1]+get(g[1][1],g[0][2],g[1][2]));
    chmax(dp[2][0], dp[1][2]+get(g[0][1],g[0][2],g[1][2]));
    for(ll i=3;i<n;i++){
        chmax(dp[i][0], dp[i-3][0] + get(g[0][i],g[0][i-1],g[0][i-2]) + get(g[1][i],g[1][i-1],g[1][i-2]));
        chmax(dp[i][0], dp[i-1][1] + get(g[0][i],g[1][i],g[1][i-1]));
        chmax(dp[i][0], dp[i-1][2] + get(g[0][i],g[1][i],g[0][i-1]));

        chmax(dp[i][1], dp[i-3][1]+get(g[0][i],g[0][i-1],g[0][i-2])+get(g[1][i-1],g[1][i-2],g[1][i-3]));
        chmax(dp[i][1], dp[i-2][0]+get(g[0][i],g[0][i-1],g[1][i-1]));

        chmax(dp[i][2], dp[i-2][0]+get(g[1][i],g[1][i-1],g[0][i-1]));
        chmax(dp[i][2], dp[i-3][2]+get(g[1][i],g[1][i-1],g[1][i-2])+get(g[0][i-1],g[0][i-2],g[0][i-3]));
    }

    return dp[n-1][0];
}

int main() {
    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        cout << res << "\n";
    }
    return 0;
}
