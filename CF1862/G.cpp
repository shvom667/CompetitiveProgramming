
#include<bits/stdc++.h>
using namespace std;



using ll=int;

template <typename T>
using Vec = vector<T>;

#define pb push_back

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin>>t;
    while(t--)solve();
}

#define hlo cout << "Hello\n";
void solve() {
  ll n;
  cin >> n;
  ll a[n];
  multiset<ll> ms, cd;
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
    ms.insert(a[i]);
  }
  ll p = 0, i = 0;
  for (auto& x : ms) {
    if (i) cd.insert(x-p);
    p = x;
    i++;
  }
  ll q;
  cin >> q;
  while (q--) {
    ll i, x;
    cin >> i >> x;
    if (n == 1) {
      cout << x << "\n";
      continue;
    }
    --i;
    cd.insert(0);
    if (x == a[i]){
      ll fans = *ms.rbegin() + (cd.size()>0?*cd.rbegin():0);
      cout << fans << " ";
      continue;
    }
    auto it = ms.lower_bound(a[i]);
    auto nt = it;
    auto pt = it;
    nt++;
    pt--;
    if (nt != ms.end() && *nt == *it) {
    }
    else {
      if (nt != ms.end()) {
        if(cd.find(*nt - *it) != cd.end())
          cd.erase(cd.find(*nt - *it));
      }
      if (it != ms.begin()) {
        if(cd.find(*it - *pt) != cd.end())
          cd.erase(cd.find(*it - *pt));
      }
      if (nt != ms.end() && it != ms.begin()) {
          cd.insert(*nt - *pt);
      }
    }
    if(ms.find(a[i]) != ms.end())
      ms.erase(ms.find(a[i]));
    auto xt = ms.find(x);
    if (xt != ms.end()) {
     
    }
    else {
      if (ms.size() >0) {
        auto iit = ms.upper_bound(x);
        auto pit = iit; pit--;
        if (iit != ms.end() && iit != ms.begin()) {
          if (cd.find(*iit-*pit) != cd.end())
            cd.erase(cd.find(*iit - *pit));
        }
        if (iit == ms.end()) {
          cd.insert(x - *pit);
        }
        else if (iit == ms.begin()) {
          cd.insert(*iit - x);
        }
        else {
          cd.insert(*iit-x);
          cd.insert(x-*pit);
        }
      }
    }
    a[i] = x;
    ms.insert(x);
    
    ll fans = *ms.rbegin() + (cd.size()>0?*cd.rbegin():0);
    cout << fans << " ";
  }
  cout << "\n";
}

