#include<bits/stdc++.h>
using namespace std;
using ll=int;
#define pb push_back
template <typename T>
using Vec = vector<T>;

void solve();
ll tc=0;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll t; 
  cin >> t; 
  while (t--){
    tc++; solve();
  }
}
const ll INF=1e8+20;


void solve() {
    char z[] = {'n','a','r','e','k'};
    ll n, m;
    cin >> n >> m;
    char s[n][m];
    for (ll i = 0; i < n; i++) {
        for (ll j= 0; j < m; j++) {
            cin >> s[i][j];
        }
    }
    // if (tc == 77) {
    //     for (ll i = 0; i < n; i++) {
    //         for (ll j= 0; j < m; j++) {
    //             cout << s[i][j];
    //         }
    //     }
    //     cout << '\n';
    //     return;
    // }

    ll cost[n][5][5];
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < 5; j++) {
            for (ll k = 0; k < 5; k++) {
                ll fans = 0;
                ll tot = 0;
                for (ll l = 0; l < m; l++) {
                    if (s[i][l] == 'n'
                    ||  s[i][l] == 'a'
                    ||  s[i][l] == 'r'
                    ||  s[i][l] == 'e'
                    ||  s[i][l] == 'k'
                    ) {
                        tot++;
                    }
                }
                ll itr = j;
                ll cnt = 0;
                for (ll l = 0; l < m; l++) {
                    if (s[i][l] == z[itr%5]) {
                        cnt++;
                        if (itr%5 == k) {
                            fans = cnt;
                        }
                        itr++;
                    } 
                }
                if (fans == 0) {
                    fans = -INF;
                }
                
                cost[i][j][k] = 2*fans-tot;
           }
        }
    }

    ll dp[n][5][5];

    for (ll i = 0; i < n; i++) {
            for (ll k = 0; k < 5; k++) {
                for (ll l = 0; l < 5; l++) {
                    dp[i][k][l] = -INF;
                }
            }
    }


    for (ll i = 0; i < n; i++) {
        for (ll k = 0; k < 5; k++) {
            for (ll l = 0; l < 5; l++) {
                dp[i][0][4]=0;
            }
        }
    }

    for (ll i = 0; i < n; i++) {
        for (ll x = 0; x < 5; x++) {
            dp[i][0][x] = max(dp[i][0][x], cost[i][0][x]);
            if (i) {
                dp[i][0][x] = max(dp[i][0][x],dp[i-1][0][x]);
            }
        }
    }

    for (ll i = 1; i < n; i++) {
        for (ll m = 0; m < 4; m++) {
            dp[i][0][m] = max(dp[i][0][m], cost[i][0][m]);
        }
        for (ll k = 0; k < 5; k++) {
            ll gv=-INF;
            for (ll mm = 0; mm < 5; mm++) {
                gv = max(gv, dp[i-1][mm][(k-1+5)%5]);
            }
            for (ll l = 0; l < 5; l++) {
                dp[i][k][l] = dp[i-1][k][l];
                dp[i][k][l] = max(dp[i][k][l],
                    gv + cost[i][k][l]
                );
            }
        }
    }

    ll fans = 0;

    for (ll m = 0; m <= 4; m++) {
        fans = max(fans, 
            dp[n-1][m][4]
        );
    }
    // for (ll i = 0; i < n; i++) {
    //     for (ll m = 0; m < 4; m++) {
    //         cout << dp[i][m][4] << " ";
    //     }
    //     cout << '\n';
    // }

    cout << fans << "\n";
}
/*

dp[i][j][k][l]: maximum number such that you have taken j string 
                upto index i and the last values
                of starts with k and ends with l.

dp[i][k][l]: maximum sum you can pick such that upto the i'th index the last pair
             is [s,e]
             dp[i][s][e] = dp[i-1][s][e]
                            dp[i-1][x][s-1] + cost[i][s][e]
            dp[0][0][x] = 0
            dp[0][s][e] = [0,x] wala hi lena hai!!!
*/