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
    vector<ll> ac={1,0,0,0};
    auto cond=[&](ll mid){
        map<ll,ll>mp;
        mp[mid-1]=2;
        dbg(mp);
        for(ll i=0;i<(ll)ac.size();i++){
            if(mp.empty())return false;
            auto b=*mp.rbegin();
            dbg(b);
            if(b.first<ac[i]){
                return false;
            }
            mp.erase(b.first);
            ll diff=b.first-ac[i];
            dbg(diff);
            if(diff>30)return true;
            b.second=b.second*(1ll<<(diff));
            b.second--;
            if(b.second==0)continue;
            mp[b.first-diff]=b.second;
            dbg("end",mp);
        }
        
        return true;
    };

    auto res= cond(2);
    dbg(res);
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    // cin >> T;
    T = 1;
    for (ll tc = 1; tc <= T; tc++) {
	    auto res = solve();
	    cout << res << "\n";
    }
    return 0;
}
