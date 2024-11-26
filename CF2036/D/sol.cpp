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
    ll n,m;cin>>n>>m;
    char g[n][m];
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>g[i][j];
        }
    }
    bool seen[n][m];for(ll i=0;i<n;i++)for(ll j=0;j<m;j++)seen[i][j]=false;
    auto get=[&](string s){
        ll n=s.size(),cnt=0;
        for(ll i=0;i<(ll)s.size();i++){
            if(s[i]=='1'){
                if (s[i] =='1'&&s[(i+1)%n]=='5'&&s[(i+2)%n]=='4'&&s[(i+3)%n]=='3')
                    cnt++;
            }
        }
        return cnt;
    };
    ll fans=0;
    for (ll i = 0; i <= min(n/2,m/2);i++){
        string s="";
        for (ll j=i;j<=m-i-1;j++){
            if(seen[i][j])continue;
            s+=g[i][j];
            seen[i][j]=true;
        }
        for(ll j=i+1;j<=n-i-1;j++){
            if(seen[j][m-i-1])continue;
            s+=g[j][m-i-1];
            seen[j][m-i-1]=true;
        }
        for(ll j=m-i-2;j>=i;j--){
            if(seen[n-i-1][j])continue;
            s += g[n-i-1][j];
            seen[n-i-1][j]=true;
        }
        for(ll j=n-i-2;j>=1;j--){
            if(seen[j][i])continue;
            s +=g[j][i];
            seen[j][i]=true;
        }
        dbg(i,s);
        fans+=get(s);
    }

    return fans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        cout << res << "\n";
    }
    return 0;
}
