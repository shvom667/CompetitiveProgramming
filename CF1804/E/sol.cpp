#include <bits/stdc++.h>
using namespace std;
using ll = int;
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

const ll N=2e6;
ll L2[N];

auto solve() {
    ll n, m;
    cin >> n >> m;
    bool edge[n][n];
    for(ll i=0;i<n;i++)for(ll j=0;j<n;j++)edge[i][j]=false;
    for(ll i=0;i<m;i++){
        ll x,y;cin>>x>>y;--x;--y;
        edge[x][y]=edge[y][x]=true;
    }
    bool pos[1<<n][n];
    for(ll i=0;i<1<<n;i++)for(ll j=0;j<n;j++)pos[i][j]=false;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            if(edge[i][j]){
                pos[(1<<i)|(1<<j)][max(i,j)]=true;
            }
        }
    }
    for(ll sb=3;sb<=n;sb++){
        for(ll mask=0;mask<1<<n;mask++){
            if(__builtin_popcount(mask)!=sb)continue;

            for(ll j=0;j<n;j++){
                if((j>L2[mask&-mask]) && (mask&(1<<j))){
                    ll nmask=(mask^(1<<j));
                    for(ll k=0;k<n;k++){
                        if(k==j)continue;
                        if(pos[nmask][k] && edge[k][j]) {
                            pos[mask][j]=true;
                            break;
                        }
                    }
                }
            }
        }
    }


    bool dp[1<<n]; for(ll i=0;i<1<<n;i++)dp[i]=false;

    for(ll mask=0;mask<1<<n;mask++){
        for(ll e=0;e<n;e++){
            if(pos[mask][e] && edge[L2[(mask&-mask)]][e]) dp[mask]=true;
        }
    }


    for(ll mask=0;mask<1<<n;mask++){
        if(!dp[mask])continue;
        bool bad=false;
        for(ll j=0;j<n;j++){
            if((mask&(1<<j))==0){
                bool ok=false;
                for(ll k=0;k<n;k++){
                    if(mask&(1<<k)) {
                        if(edge[j][k]){
                            ok=true;
                            break;
                        }
                    }
                }
                if(!ok){
                    bad=true;
                }
            }
        }
        if(!bad){
            dbg(mask);
            cout<<"Yes\n";

            ll lb=L2[mask&-mask];
            ll e=-1;
            for(ll i=lb+1;i<n;i++){
                if(mask&(1<<i)){
                    if(pos[mask][i] && edge[lb][i]){
                        e=i;
                        break;
                    }
                }
            }

            dbg(lb,e);

            vector<ll> next_val(n,-1);
            next_val[e]=lb;
            ll org_mask=mask;

            bool ent=false;
            mask ^= (1<<e);

            while(mask>(1<<lb)){
                dbg(mask);
                ent=true;
                for(ll i=lb+1;i<n;i++){
                    if (!(mask&(1<<i)))continue;
                    if(pos[mask][i] && edge[i][e]) {
                        next_val[i]=e;
                        dbg(e,i);
                        mask ^= (1<<i);
                        e = i;
                        break;
                    }
                }
                // dbg(e);
            }
            dbg(next_val);
            // if(!ent){
                next_val[lb]=e;
            // }

            mask=org_mask;
            for(ll i=0;i<n;i++){
                if(next_val[i]>=0)continue;
                for(ll j=0;j<n;j++){
                    if(mask&(1<<j)){
                        if(edge[i][j])
                            next_val[i]=j;
                    }
                }
            }


            for(auto&x:next_val){
                cout<<x+1<<" ";
            }   cout<<'\n';
            return;
        }
    }
    cout<<"No\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    L2[1]=0;

    for(ll i=2,j=1;i<N;i*=2){
        L2[i]=j++;
    }
    for(ll i=2;i<N;i++){
        if(L2[i]>0)continue;
        else L2[i]=L2[i-1];
    }


    ll T;
    T = 1;
    for (ll tc = 1; tc <= T; tc++) {
	    solve();
    }
    return 0;
}
