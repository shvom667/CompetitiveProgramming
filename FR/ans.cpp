#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;


void toggle(int r) {
  if (s.find(r) != s.end()) {
    s.erase(r);
  } else {
    s.insert(r);
  }
}

ll query(ll x, ll y) {
  if (s.empty()) return true;
  ll lx, ly;
  lx = a[x];
  ly = a[y];
  if (lx == ly) {
    return 0ll;
  }
  if (lx < ly) {
    ll res = ly - lx;
    auto it = s.lower_bound(lx);
    if (it == s.end()) {
      return res;
    }
    if (*it <= ly-1) {
      return res;
    }
  }
  if (lx > ly) {
    ll res = n - lx + ly;
    auto it = s.lower_bound(lx);
    if (it != s.end()) {
      return -1ll;
    }
    auto jt = s.begin();
    if (*jt > ly - 1) {
      return -1ll;
    }
    return res;
  }

  return -1;
}

void init(ll nn,  ll mm, vector<ll> aa) {
  s.clear();
  n = nn;
  m = mm;
  a = aa;

}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
}

