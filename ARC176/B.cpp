
#define FAST_IO
// ============

#include <bits/stdc++.h>

using ll = long long;
using namespace std;

ll get(ll N) {
    if (N == 0) return 1ll;
    if (N%4==0){
        return 6ll;
    }
    if(N%4==1){
        return 2ll;
    }
    if(N%4==2){
        return 4ll;
    }
    if(N%4==3){
        return 8ll;
    }
    return 0ll;
}
ll test(ll N, ll M, ll K) {
    // ll a = 1ll<<N;
    ll b = (1ll<<N) % ((1ll<<M) - (1ll<<K));
    return b%10;
}

ll solve(ll N, ll M, ll K) {
    if (M > N) {
        if (M == N + 1 && K == N) {
            return 0ll;
        } else {
            return get(N);
        }
    }
    ll y = N - K, x = M - K;
    if (x == 1) {
        return 0ll; 
    }
    return (get(y%x)*get(K))%10;
}

signed main() {

    // for(ll N = 60; N >= 1; N--) {
    //     for (ll M = 1; M <= 60; M++) {
    //         for (ll K = 0; K < M; K++) {
    //             if (test(N,M,K)==solve(N,M,K)) {

    //             } else {
    //                 cout << "{ \n";
    //                 cout << N << " " << M << " " << K << "\n";
    //                 cout << test(N,M,K) << " " << solve(N,M,K) << "\n";
    //                 cout << "}\n";
    //             }
    //         }
    //     }
    // }

    ll t;
    t = 1;
    cin >> t;
    while (t--) {
        ll N, M, K;
        cin >> N >> M >> K;
        cout << solve(N, M, K) << "\n";
    }
}

