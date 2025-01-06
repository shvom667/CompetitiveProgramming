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

auto solve() {
    ll n;cin>>n;vector<ll>a(n);for(ll i=0;i<n;i++)cin>>a[i];
    vector<ll> p[3];
    for(ll i=0;i<n;i++){
        p[a[i]].pb(i);
    }
    vector<ll>n0(n,n),p0(n,-1);
    for(ll i=n-1;i>=0;i--){
        if (i==n-1){
            if(a[i]==0){
                n0[i]=i;
            }
            continue;
        }
        n0[i]=n0[i+1];
        if(a[i]==0){
            n0[i]=i;
        }
    }
    if(a[0]==0)p0[0] = 0;
    for(ll i=1;i<n;i++){
        p0[i]=p0[i-1];
        if(a[i]==0){
            p0[i]=i;
        }
    }
    dbg(n0);
    dbg(p0);
    vector<bool>seen(n,false);
    ll fans=0;
    for(auto x: p[2]) {
        if (seen[x])continue;
        fans++;
        for(ll j=p0[x];j<=n0[x];j++){
            if(j>=0&&j<n){
                seen[j]=true;
            }
        }
    }
    dbg(seen,fans);

    ll cnt1=0,cnt0=0;
    ll alt1=0;
    for(ll i=0;i<n;i++){
        if (seen[i]){
            fans+=max(cnt0, alt1);
            cnt1=0;
            cnt0=0;
            alt1 = 0;
            continue;
        }else{
            if(a[i] == 1){
                if(i > 0) {
                    if (!seen[i - 1]) {
                        if (a[i - 1] != 1) {
                            alt1++;
                        }
                    } else {
                        alt1++;
                    }
                }else{
                    alt1++;
                }
            }

            if(a[i]==0)cnt0++;
            else cnt1++;
        }
    }
    fans+=max(cnt0,alt1);

    if (fans==0){
        fans=1;
    }
    
    return fans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    T = 1;
    for (ll tc = 1; tc <= T; tc++) {
	    auto res = solve();
	    cout << res << "\n";
    }
    return 0;
}
