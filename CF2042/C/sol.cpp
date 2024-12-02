#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
template <typename T> using Vec = vector<T>;

#ifndef ONLINE_JUDGE
#include "/home/shivom/Downloads/CP/DataStructures/debug.cpp"
#include "/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
#else
#define dbg(...) 42
#define rnd(...) 42
#endif

auto solve() {
  ll n,k;
  cin>>n>>k;
  vector<char> s(n + 1);
  vector<ll> d(n+1, 0),p1(n+1, 0),p0(n+1, 0);
  for(ll i=1;i<=n;i++){
    cin>>s[i];
    p1[i] += s[i] == '1';
    p0[i] += s[i] == '0';
    if (i) {
      p1[i] += p1[i-1];
      p0[i] += p0[i-1];
    }
    d[i]=p1[i]-p0[i];
  }
  vector<ll>v(n);
  for(ll i=0;i<n;i++)v[i]=d[i+1];
  sort(begin(v),end(v));
  ll fans=-1;
  ll pre=0;
  for(ll m=1;m<=n;m++){
    ll cur=0;
    cur+=(m-1)*d[n];
    if(m>=2)
      pre+=v[m-2];
    if(cur-pre>=k){
      fans=m;
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
