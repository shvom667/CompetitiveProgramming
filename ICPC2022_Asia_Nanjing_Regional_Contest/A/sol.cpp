#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;
 
#ifndef ONLINE_JUDGE
    #include"/home/shivom/Downloads/CP/DataStructures/debug.cpp"
#else
    #define dbg(...) 42
#endif
 
auto solve() {
    ll fans=0;

    ll n, m, k; cin >> n >> m >> k;
    string s; cin >> s; ll L = s.size();
    ll shift1=n, shift2=m;
    // ll shift=max(n,m);
    vector<vector<ll>> g(2*shift1, vector<ll> (2*shift2, 0));
    vector<ll>  x,y;
    x.pb(0),y.pb(0);
    for (ll i = 0; i < L; i++) {
        if (s[i] == 'U') {
            x.pb(x.back()-1);
            y.pb(y.back());
        }
        if (s[i] == 'D') {
            x.pb(x.back()+1);
            y.pb(y.back());
        }
        if (s[i] == 'R') {
            x.pb(x.back());
            y.pb(y.back()+1);
        }
        if (s[i] == 'L') {
            x.pb(x.back());
            y.pb(y.back()-1);
        }
    }
    vector<ll>sx,sy;
    ll lmax,lmin,umax,umin;
    lmax=lmin=umax=umin=0;
    for(auto&i:x){
        umax=max(umax,i);
        umin=min(umin,i);
    }
    for(auto&i:y){
        lmax=max(lmax,i);
        lmin=min(lmin,i);
    }
    dbg(lmax,lmin);
    dbg(umax,umin);
    sx=x;
    sy=y;
    for(auto&x:sx) x=-x;
    for(auto&y:sy) y=-y;
    ll lb,rb,ub,db;

    dbg(lmin,lmax,umin,umax);

    lb=abs(lmin);
    rb=m-1-abs(lmax);
    ub=abs(umin);
    db=n-1-abs(umax);

    // swap(sx,sy);
    for(ll i=0;i<(ll)sx.size();i++){
        ll x,y;
        x=sx[i],y=sy[i];
        if ( !(shift1 + x >= 0 && shift1 + x < 2 * n && shift2 + y >= 0 && shift2 + y < 2 * m) ) continue;
        if(g[shift1+x][shift2+y]==0)
            g[shift1+x][shift2+y]+=1;
    }
    dbg(sx,sy,shift1, shift2);
    // for(ll i = 0; i < g.size(); i++) {
    //     for (ll j = 0; j < g.size(); j++) {
    //         cout << g[i][j] << " ";
    //     }
    //     cout << "\n";
    // }   

    dbg(lb,rb,ub,db);

    for (ll i = 0; i < 2*shift1; i++) {
        for (ll j = 0; j < 2*shift2 ;j++) {
            if (j > 0)
            g[i][j] += g[i][j-1];
            if (i > 0)
            g[i][j] += g[i-1][j];
            if(i > 0 && j > 0)
            g[i][j] -= g[i-1][j-1];
        }
    }
    // for(ll i = 0; i < g.size(); i++) {
    //     for (ll j = 0; j < g.size(); j++) {
    //         cout << g[i][j] << " ";
    //     }
    //     cout << "\n";
    // }  

    auto get=[&](ll a, ll b, ll c, ll d) {
        ll x1,y1,x2,y2;
        x1=min(a,c);
        y1=min(b,d);
        x2=max(a,c);
        y2=max(b,d);
        ll cur_fans=g[x2][y2];
        if(y1-1>=0)
        cur_fans -= g[x2][y1-1]; 
        if(x1-1>=0)
        cur_fans -= g[x1-1][y2];
        if (x1-1>=0&&y1-1>=0)
        cur_fans += g[x1-1][y1-1];
        return cur_fans;
    };
    
    ll tot = (rb - lb + 1) * (db - ub + 1);
    if (lb > rb || ub > db) tot = 0;
    if (tot < 0) tot=0;
    if (tot == 0) {
        if (k == 0) {
            return n * m;
        } else {
            return 0ll;
        }
    }
    dbg(tot);
    
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            // if (i == 3 && j == 2) {
                ll dx1=ub - i + shift1;
                ll dx2=db - i + shift1;
                ll dy1=lb - j + shift2;
                ll dy2=rb - j + shift2;
                dbg(dx1,dy1,dx2,dy2);
                dbg(get(dx1,dy1,dx2,dy2));
                dbg(tot);
                if (tot - get(dx1,dy1,dx2,dy2) == k) {
                    dbg(i,j);
                    fans++;
                }
            // }
        }
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
