#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
const ll INF = 1e15;
#define all(x) (x).begin(), (x).end()
inline ll nxt() { ll x; cin >> x; return x; }
template <class X, class Y, char sep=' '> ostream & operator << (ostream & os, pair <X, Y> const& p) { return os << p.first << sep << p.second; }
template <class Ch, class Tr, char sep=' ', class Container> basic_ostream <Ch, Tr> & operator << (basic_ostream <Ch, Tr> & os, Container const& x) { for (auto it = x.begin(); it != x.end(); it++) { if (it != x.begin()) os << sep; os << *it; } return os << ""; }
template <char sep=' ', char end='\n', class T, class... U> void print( const T& first, const U&... rest) { std::cout << first; ((std::cout << sep << rest ), ...); std::cout << end; }
template <typename T> using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

const ll MAX_SIZE = 400005;

vector<ll> isprime(MAX_SIZE , true);
vector<ll> prime;
vector<ll> SPF(MAX_SIZE);

void sieve(ll N) {
    isprime[0] = isprime[1] = false ;
    for (ll i=2; i<N ; i++) {
        if (isprime[i]) {
            prime.push_back(i);
            SPF[i] = i;
        }
        for (ll j=0;
            j < prime.size() and
            i*prime[j] < N and prime[j] <= SPF[i];
            j++) {
            isprime[i*prime[j]]=false;
            SPF[i*prime[j]] = prime[j] ;
        }
    }
}

void solve() {
    ll n; cin >> n;
    vector<ll> v(n);
    ll pc = 0;
    ll p;
    for (ll i = 0; i < n; i++) {
        cin >> v[i];
        if (isprime[v[i]]) {
            pc++;
            p = v[i];
        }
    }
    if (pc == 0) {
        print(2);
        return;
    } else if (pc >= 2) {
        print(-1);
        return;
    }
    for (ll i = 0; i < n; i++) {
        if (v[i] == p) continue;
        if (v[i] % 2 == 0 and v[i] / SPF[v[i]] < p) {
            print(-1);
            return;
        }
        if (v[i] % 2 != 0 and v[i] / SPF[v[i]] < p and (v[i] - SPF[v[i]]) / 2 < p) {
            print(-1);
            return;
        }
    }
    print(p);
}

int main() {
    sieve(MAX_SIZE-2);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll tc = nxt();
    while (tc--) {
        solve();
    }
}
