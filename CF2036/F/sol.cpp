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

ll computeXOR(ll n)
{
  
  // If n is a multiple of 4
  if (n % 4 == 0)
    return n;

  // If n%4 gives remainder 1
  if (n % 4 == 1)
    return 1;

  // If n%4 gives remainder 2
  if (n % 4 == 2)
    return n + 1;

  // If n%4 gives remainder 3
  return 0;
}
auto solve() {
    ll l,r,i,k;cin>>l>>r>>i>>k;
    auto f=[&](ll x){
        // if(x<k)return (1ll <<i);
        if(x<k)return 0ll;
        ll ans = (x-k)/(1ll<<i);
        ll v=ans;
        dbg(x,v);
        v=computeXOR(v);
        v =  (v << i);
        if(ans%2==0)
        v ^= k;
        return v;
    };
    ll L,R,p,q;
    L=computeXOR(l-1);
    R=computeXOR(r);
    p=f(l-1);
    q=f(r);
    dbg(L,R);
    return (L^R^p^q);
    // dbg(r,f(r));
    // dbg(l-1,f(l-1));
    // return f(r)-f(l-1);
    // return 0;
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
