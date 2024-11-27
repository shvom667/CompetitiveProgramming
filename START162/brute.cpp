#include<bits/stdc++.h>
using namespace std;
using ll=int;
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
    ll n;string s;cin>>n>>s;ll a,b;a=b=0;long long fans;fans=0;

    long long f[n];
    f[n - 1] = 1;
    vector<ll> pa(n, 0), pb(n, 0);
    for(ll i=0;i<n;i++){
        pa[i]=(s[i]=='A');if(i)pa[i]+=pa[i-1];
        pb[i]=(s[i]=='B');if(i)pb[i]+=pb[i-1];
    }
    vector<ll> gi(2*n+10,-1);
    ll shift=n;
    gi[shift+pa[n-1]-pb[n-1]] = n-1;
    for(ll i = n - 2; i>= 0; i--) {
        ll L,R;L=i+1,R=n-1;
        auto cond=[&](ll mid) {
            ll cnt=0;bool ok=false;
            for(ll j=i+1;j<=mid;j++){
                if(s[i]=='A'){
                    if(s[j]=='A')cnt--;
                    else cnt++;
                    if(cnt>0)ok=true;
                }else{
                    if(s[j]=='B')cnt--;
                    else cnt++;
                    if(cnt>0)ok=true;
                }
            }
            return ok;
        };
        while(L<=R){
            ll mid=L+(R-L)/2;
            if(cond(mid)){
                R=mid-1;
            }else{
                L=mid+1;
            }
        }
        // ll L = n;   
        // if(gi[shift+pa[i]-pb[i]+1]!=-1){
        //     L=gi[shift+pa[i]-pb[i]+1];
        // }
        f[i] = f[i + 1] + 1 + L-(i+1);
        dbg(i,L);
        // gi[shift+pa[i]-pb[i]]=i;
    }
    for(ll i=0;i<n;i++){
        // cout<<f[i]<<" \n"[i==n-1];
        fans+=f[i];
    }
    return fans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       
    ll T;
    // cin >> T;
    T=1;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        cout << res << "\n";
    }
    return 0;
}
