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
using pl=pair<ll,ll>;
auto solve() {
    ll n,k;
    cin>>n>>k;
    vector<ll> ch[n];
    for (ll i = 1; i < n; i++) {
        ll x;
        cin>>x;
        x--;
        ch[x].pb(i);
    }
    vector<ll> depth(n, 0);
    function<void(int)>dfs=[&](ll i){
        for(auto&c:ch[i]){
            dfs(c);
            depth[i]=max(depth[c]+1,depth[i]);
        }
    };
    dfs(0);
    dbg(depth);
    priority_queue<pl,Vec<pl>> pq;
    pq.push({depth[0],0});
    ll res=0; 
    function<void(ll,ll)>dfs2=[&](ll i, ll d) {
        dbg(i,d);
        if(d<0){
            return;
        }
        ll nextCh=-1;
        for(auto&c:ch[i]){
            if(depth[c]==d-1){
                nextCh=c;
            }
        }
        for(auto&c:ch[i]){
            if(c!=nextCh){
                pq.push({depth[c],c});
            }
        }
        dfs2(nextCh,d-1);
    };
    while(!pq.empty()) {
        auto t=pq.top();
        dbg(t);
        if(k>0){
            res+=t.first+1;
            k--;
        }else{
            break;
        }
        pq.pop(); 
        dbg("hillo");
        dfs2(t.second,t.first);
    }
    cout<<res<<"\n";
}

int main() {
    ll T;
    T=1;
    for (ll tc = 1; tc <= T; tc++) {
        solve();
    }
    return 0;
}
