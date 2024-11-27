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
ll B = 60;
auto solve() {
    ll l, r, x;
    cin >> l  >> r >> x;

    ll L = 0, R = 1e10;

    auto cond = [&] (ll mid) {
        if(mid<0)return true;
        ll maxv=x, minv=x;
        for (ll bit = B; bit >= 0; bit--) {
            if ((mid&(1ll<<bit)) == 0)continue;
            if ((mid&(1ll<<bit))) {
                if(x&(1ll<<bit)){
                    for (ll nb=bit;nb>=0;nb--){
                        maxv |= (1ll << nb);
                    }
                    break;
                }else{
                    maxv |= (1ll << bit);
                    
                }
            }
        }

        for (ll bit = B; bit >= 0; bit--) {
            if ((mid&(1ll<<bit)) == 0)continue;
            if ((mid&(1ll<<bit))) {
                if(!(x&(1ll<<bit))){
                    for (ll nb=bit;nb>=0;nb--){
                        if (minv&(1ll<<nb)){
                            minv ^= (1ll<<nb);
                        }
                    }
                    break;
                }else{
                    minv ^= (1ll<<bit);
                }
            }
        }
        // dbg(minv,maxv);
        assert(minv<=maxv);
        return (r >= maxv && l <= minv);
    };

    // dbg(cond(15));

    while (L <= R) {
        ll mid = L + (R - L) / 2;
        if (cond(mid-1)) {
            L=mid+1;
        }else{
            R=mid-1;
        }
    }
    return R;
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
