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
    ll n, x;
    cin >> n >> x;
    vector<ll>a(n);for(ll i=0;i<n;i++)cin>>a[i];
    vector<ll>b(n);for(ll i=0;i<n;i++)cin>>b[i];
    vector<ll>v(n);for(ll i=0;i<n;i++)v[i]=a[i]*b[i];
    sort(begin(v),end(v),greater<ll>());
    ll sum=0;
    ll fans=-1;
    for(ll i=0;i<n;i++){
        sum+=v[i];
        if(sum>=x){
            fans=i+1;
            break;
        }
    }
    return fans;
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