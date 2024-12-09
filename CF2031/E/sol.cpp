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
    ll n;cin>>n;

    Vec<ll> a(n,0),f(n,0);
    vector<vector<ll>>adj(n);
    for(ll i=1;i<n;i++){
        cin>>a[i];a[i]--;adj[a[i]].pb(i);
    }
    dbg(a[n-1]);
    function<void(ll,ll)>dfs=[&](ll i,ll p){
        Vec<ll>ac;
        for(auto&ch:adj[i]){
            dfs(ch,i);
            ac.pb(f[ch]);
        }
        ll L=1,R=1e7+20;
        sort(begin(ac),end(ac),greater<ll>());
        auto cond=[&](ll mid){
            map<ll,ll>mp;
            mp[mid-1]=2;
            
            for(ll i=0;i<(ll)ac.size();i++){
                if(mp.empty())return false;
                auto b=*mp.rbegin();
                if(b.first<ac[i]){
                    return false;
                }
                mp.erase(b.first);
                ll diff=b.first-ac[i];
                if(diff>20)return true;
                b.second=b.second*(1ll<<(diff));
                if(b.second>n)return true;
                b.second--;
                if(b.second==0)continue;
                mp[b.first-diff]=b.second;
                dbg(mp);
            }
            
            return true;
        };

        if((ll)ac.size()>0){
            while(L<=R){
                ll mid=L+(R-L)/2;
                if(cond(mid)){
                    R=mid-1;
                }else{
                    L=mid+1;
                }
            }
            f[i]=L;
        }else{
            f[i]=0;
        }
    };

    dfs(0,-1);


    return f[0];
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
