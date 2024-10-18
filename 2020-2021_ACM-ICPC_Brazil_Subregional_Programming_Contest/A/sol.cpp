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
f80 one = 1;

const long long MAX_SIZE = 31622776+1;
 
// isPrime[] : isPrime[i] is true if number is prime 
// prime[] : stores all prime number less than N
// SPF[] that store smallest prime factor of number
// [for Exp : smallest prime factor of '8' and '16'
// is '2' so we put SPF[8] = 2 , SPF[16] = 2 ]
vector<long long >isprime(MAX_SIZE , true);
vector<long long >prime;
vector<long long >SPF(MAX_SIZE);
 
// function generate all prime number less than N in O(n)
void manipulated_seive(int N)
{
    // 0 and 1 are not prime
    isprime[0] = isprime[1] = false ;
 
    // Fill rest of the entries
    for (long long int i=2; i<N ; i++)
    {
        // If isPrime[i] == True then i is
        // prime number
        if (isprime[i])
        {
            // put i into prime[] vector
            prime.push_back(i);
 
            // A prime number is its own smallest
            // prime factor
            SPF[i] = i;
        }
 
        // Remove all multiples of  i*prime[j] which are
        // not prime by making isPrime[i*prime[j]] = false
        // and put smallest prime factor of i*Prime[j] as prime[j]
        // [ for exp :let  i = 5 , j = 0 , prime[j] = 2 [ i*prime[j] = 10 ]
        // so smallest prime factor of '10' is '2' that is prime[j] ]
        // this loop run only one time for number which are not prime
        for (long long int j=0;
             j < (int)prime.size() &&
             i*prime[j] < N && prime[j] <= SPF[i];
             j++)
        {
            isprime[i*prime[j]]=false;
 
            // put smallest prime factor of i*prime[j]
            SPF[i*prime[j]] = prime[j] ;
        }
    }
}
 

auto solve() {
    
    ll n, a, b;
    cin >> n >> a >> b;

    f80 L = b - a + 1;
    if (a >= 1) {
        vector<f80> dp(n + 1, 0), dp_sum(n + 1, 0);
        dp[0] = 0;
        for (ll i = 1; i <= n; i++) {

            ll l, r;
            l = max(0ll, i - b);
            r = i - a;
            f80 sum=0;
            if (r >= 0) {
                sum = dp_sum[r];
                if (l) {
                    sum -= dp_sum[l - 1];
                }
            }

            dp[i] = one + sum / L;

            dp_sum[i] = dp[i];
            if (i) {
                dp_sum[i] += dp_sum[i-1];
            }
        }
        // for (ll i = 0; i <= n; i++) {
        //     cout << fixed << setprecision(20) << dp[i] << " ";
        // }   cout << "\n";
        return dp[n];
    }


    vector<f80> dp(n + 1, 0), dp_sum(n + 1, 0);
    dp[0] = 0;
    for (ll i = 1; i <= n; i++) {

        ll l, r;
        l = max(0ll, i - b);
        r = i - 1;
        f80 sum=0;
        if (r >= 0) {
            sum = dp_sum[r];
            if (l) {
                sum -= dp_sum[l - 1];
            }
        }

        dp[i] = L / (L - 1) + sum / (L - 1);

        dp_sum[i] = dp[i];
        if (i) {
            dp_sum[i] += dp_sum[i-1];
        }
    }
    // for (ll i = 0; i <= n; i++) {
    //     cout << fixed << setprecision(20) << dp[i] << " ";
    // }   cout << "\n";
    return dp[n];

    return one;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    T = 1;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        cout << fixed << setprecision(20) << res << "\n";
    }
    return 0;
}
