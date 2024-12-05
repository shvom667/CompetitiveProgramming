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
int ub(int a, int b) {
    if (a % b == 0) return (a / b);
    bool positive = !((a < 0) ^ (b < 0));
    return a / b + positive;
}
int lb(int a, int b) {
    if (a % b == 0) return (a / b);
    bool negative = (a < 0) ^ (b < 0);
    return a / b - negative;
}
auto solve(ll n, ll k, Vec<ll> a) {
    ll eq=0;
    ll cnt=0;
    ll ueq=0;
    dbg(a);
    for(ll i=0;i<n;i++){
        if(abs(a[i])%k==0){
            eq+=a[i]/k;
            continue;
        }
        dbg(a[i], k, ub(a[i],k));
        ueq += ub(a[i],k);
        cnt++;
    }
    eq=-eq;
    dbg(eq,ueq,cnt);
    if(eq<=ueq && eq>=ueq-cnt){
        return "YES";
    }
    return "NO";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    T = 1;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        ll n,k;cin>>n>>k;
        Vec<ll>a(n);
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        auto res = solve(n, k, a);
        cout << res << "\n";
    }
    return 0;
}
