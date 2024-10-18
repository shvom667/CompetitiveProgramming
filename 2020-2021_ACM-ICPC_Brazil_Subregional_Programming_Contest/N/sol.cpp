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
 

const long long MAX_SIZE = 31622776+16;
 
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

const ll SZ=1e3+10;
ll g[SZ][SZ]; 

template <typename T>
void makeUniq(vector<T>& vec) {
    sort(begin(vec),end(vec));
    vec.resize(unique(begin(vec),end(vec)) - vec.begin());
}

auto solve() {
    ll M, N, K;
    cin >> M >> N >> K;
    vector<ll> C(N);
    vector<ll> P(M, -1);
    for (ll i = 0; i < N; i++) {
        cin >> C[i];
    }
    vector<ll> adj[M];
    for (ll i = 0; i < K; i++) {
        ll m, n, d;
        cin >> m >> n >> d;
        --m;--n;
        adj[m].pb(n);
        g[m][n] = d;

    }
    ll p_itr = 0;

    for (ll i = 0; i < (ll) prime.size(); i++) {
        if (p_itr >= M) break;
        // dbg(i, prime[i]);
        // dbg(prime[i]);
        // dbg(adj[p_itr][0]);
        // dbg(C[adj[p_itr][0]]);
        if (C[adj[p_itr][0]]%prime[i] == 0) {
            P[p_itr++] = prime[i];
        }
    }

    for (ll i = 0; i < M; i++) {
        if (P[i] > 0) {
            for (auto&v: adj[i]) {
                ll d = g[i][v];
                while (d--) {
                    C[v] /= P[i];
                }
            }
        }
    }

    vector<ll> othr;
    for (ll i = 0; i < N; i++) {
        if (C[i] > 1) {
            othr.pb(C[i]);
        }
    }

    makeUniq(othr);


    sort(begin(othr), end(othr));
    ll itr_oth=0;
    for(ll i = 0; i < M; i++) {
        if (P[i] == -1) {
            P[i] = othr[itr_oth++];
        }
    }
    sort(begin(P),end(P));
    assert(P[0] > 0);
    return P;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    manipulated_seive(31622776+9);


    ll T;
    T = 1;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        for (auto &x : res) {
            cout << x << " ";
        }   cout << "\n";
    }
    return 0;
}
