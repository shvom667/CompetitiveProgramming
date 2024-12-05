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

const ll INF=1e9+20;
auto solve() {
    ll n;cin>>n;string s,p;cin>>s>>p;
    ll m[26], pos[26], rpos[26];
    for(ll i=0;i<26;i++){
        pos[p[i]-'a']=i;
    }
    for(ll i=0;i<26;i++){
        rpos[pos[i]]=i;
    }
    for(ll i=0;i<26;i++){
        m[i] = rpos[25-pos[i]];
    }
    // for(ll i=0;i<26;i++){
    //     cout<<pos[i]<< " ";
    // }   cout<<'\n';
    // for(ll i=0;i<26;i++){
    //     cout<<m[i]<<" ";
    // }   cout<<'\n';
    
    ll dp[n][26];
    for(ll i=0;i<n;i++){
        for(ll j=0;j<26;j++){
            dp[i][j]=INF;
        }
    }

    dp[0][s[0]-'a']=0;
    dp[0][m[s[0]-'a']]=1;

    for(ll i=1;i<n;i++){
        ll cur_char = s[i] - 'a';
        dbg(i,cur_char);
        for (ll prev = 0; prev < 26; prev++){
            if (prev<=cur_char)
                dp[i][cur_char] = min(dp[i][cur_char], dp[i-1][prev]);
        } 
        cur_char = m[cur_char];
        dbg(i,cur_char);
        for (ll prev = 0; prev < 26; prev++){
            if (prev<=cur_char)
                dp[i][cur_char] = min(dp[i][cur_char], dp[i-1][prev]+1);
        } 
    }
    dbg(dp[0][0]);
    dbg(dp[1][4]);

    dbg(dp[2][9]);
    dbg(dp[3][10]);

    ll fans=INF;
    for(ll j=0;j<26;j++){
        fans=min(fans,dp[n-1][j]);
    }
    if(fans>=INF){
        fans=-1;
    }
    return fans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
	auto res = solve();
	cout << res << "\n";
    }
    return 0;
}
