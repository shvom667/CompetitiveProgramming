#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;
 
#ifdef SHIVOM
    #include"/home/shivom/Downloads/CP/DataStructures/debug.cpp"
    #include"/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
#else
    #define dbg(...) 42
    #define rnd(...) 42
#endif

const ll M = 998244353;
const ll N = 1e6 + 1;


vector<vector<ll>> dp(N, vector<ll> (28, 0));
vector<ll> F(N, 0);

vector<ll> P(28, 0);

auto solve() {
    ll n;
    cin >> n;

    if (n % 4) {
        return 0ll;
    }

    return F[n/4];
}



auto bf() {

    P[2] = 4;
    for (ll i = 3; i <= 27; i++) {
        P[i] = 2 * P[i - 1] + (1ll << i);
    }
    
    dbg(P);

    dbg(P);
    dp[0][0] = 1;
    
    dp[1][2] = 1;

    for (ll i = 2; i < N; i+=1) {
        for (ll p2 = 2; p2 <= 27; p2++) {
            if (4*i - P[p2] < 0) continue;
            for (ll p3 = 0; p3 <= p2; p3++){
                if ((4 * i - P[p2]) % 4 != 0) continue;
                if (!((4*i - P[p2])/4 >= 0 && (4*i - P[p2])/4 < N)) continue;
                dp[i][p2] += dp[(4*i - P[p2])/4][p3];
                dp[i][p2] %= M;
            }
        }
    }

    for (ll i = 1; i < N; i += 1) {
        ll fans = 0;
        for (ll j = 0; j <= 27; j++) {
            fans += dp[i][j];
            fans %= M;
        }
        F[i] = fans;
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       
    bf();
    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        cout << res <<  "\n";
    }   
    return 0;
}

