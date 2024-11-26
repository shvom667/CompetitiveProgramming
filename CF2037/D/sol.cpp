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
    ll n,m,l;cin>>n>>m>>l;

    vector<pair<ll,ll>> hurdles(n), pup(m);
    for(ll i=0;i<n;i++){
        cin>>hurdles[i].first>>hurdles[i].second;
    }
    for(ll i=0;i<m;i++){
        cin>>pup[i].first>>pup[i].second;
    }
    dbg(hurdles);
    dbg(pup);
    ll j=0,i=0,sz=0,pjmp=1,fans=0;
    priority_queue<ll> pq;
    for (j=0;j<n;j++){
        sz=max(sz,hurdles[j].second-hurdles[j].first);
        dbg(j,pjmp,sz+2);
        if(sz+2<=pjmp)continue;
        // ll v = 0;

        while(i<m&&pup[i].first<hurdles[j].first){
            pq.push(pup[i].second);
            i++;
        }
        dbg(i,m,pjmp);
        dbg(pq);
        while (!pq.empty()) {
            if (pjmp >= sz+2) break;
            pjmp += pq.top();
            pq.pop();
            fans++;
        }
        if(pjmp<sz+2){
            return -1ll;
        }
        // fans++;
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
