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
    ll n , x;
    cin >> x >> n;

    ll L=1,R=(1ll<<n)-1;

    auto get = [&] (ll x) {
        ll travel = 0;
        ll fans = 0;
        while (x > 0) {
            travel++;
            fans += x;
            x /= 2;
            if(travel == n) {
                break;
            }
        }
        return fans;
    };
    dbg(get(6));
    while(L<=R){
        ll mid=L+(R-L)/2;
        auto cond = [&](ll mid) {
            return get(mid)<=x;
        } ;
        if(cond(mid)){
            L=mid+1;
        }else{
            R=mid-1;
        }
    }
    if(get(R)==x){
        return R;
    }
    L=(1ll<<n),R=1e18;

    while(L<=R){
        ll mid=L+(R-L)/2;
        auto cond = [&](ll mid) {
            return get(mid)<=x;
        } ;
        if(cond(mid)){
            L=mid+1;
        }else{
            R=mid-1;
        }
    }
    if(get(R)==x){
        return R;
    }

    return -1ll;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
	auto res = solve();
	cout << res << "\n";
    }
    return 0;
}
