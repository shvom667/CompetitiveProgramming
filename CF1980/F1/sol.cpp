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

#define ALL(x) begin(x), end(x)
template <typename T> void makeUniq(vector<T> &vec) {
  sort(begin(vec), end(vec));
  vec.resize(unique(ALL(vec)) - vec.begin());
}
const ll N = 1e6;
map<ll, ll> cmp, dmp;
void compress(Vec<ll> &tot) {
  makeUniq(tot);
  ll n = tot.size();
  for (ll i = 0; i < n; i++) {
    cmp[tot[i]] = i;
    dmp[i] = tot[i];
  }
}

auto solve() {
    ll n,m,k;cin>>n>>m>>k;
    ll  mm = m;
    ll X[k],Y[k];
    for(ll i=0;i<k;i++)cin>>X[i]>>Y[i];
    for(ll i=0;i<k;i++){
        X[i]--;Y[i]--;
    }

    vector<ll>tot;
    for(ll i=0;i<k;i++){
        tot.pb(Y[i]);
    }
    compress(tot);
    m = tot.size();
    for(ll i=0;i<k;i++){
        Y[i]=cmp[Y[i]];
    }

    assert(m < N);    

    map<ll,ll>mp;
    for(ll i=0;i<k;i++){
        if(mp.find(Y[i])==mp.end()) mp[Y[i]]=X[i];
        else
            mp[Y[i]]=max(mp[Y[i]],X[i]);
    }

    Vec<ll>x(m,-1);

    for(ll j=0;j<m;j++){
        if(mp.find(j)==mp.end())continue;
        else x[j]=mp[j];
    }
    dbg(x);
    for(ll i=1;i<m;i++)
        x[i]=max(x[i],x[i-1]);
    ll fans=0;


    dbg(cmp);
    dbg(dmp);
    dbg(x);


    ll prev = -1;
    ll prevh = n;
    for(ll i=0;i<m;i++) {
        ll a, b;a = b = 0;
        a+=(n-(x[i]+1));
        b += (prevh) * (dmp[i] - 1 - prev);
        prev = dmp[i];
        prevh = n-x[i]-1;
        dbg(i,a,b);
        fans += a + b;
        dbg(fans);
    }

    dbg(prev);
    dbg(prevh);
    fans += (prevh) * (mm - 1 - prev);

    Vec<ll>res;
    for(ll i=0;i<k;i++){
        if(x[Y[i]] != X[i]) {
            res.pb(0);continue;
        }
        if(Y[i]==0||x[Y[i]-1]<X[i]){
            res.pb(1);
        }else{
            res.pb(0);
        }
    }

    cout<<fans<<'\n';
    for(auto&x:res)
        cout<<x<<" ";
    cout<<'\n';

    cmp.clear();dmp.clear();
    return 0;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
	    auto res = solve();
    }
    return 0;
}
