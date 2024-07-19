
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;

void solve();
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll t; 
  cin >> t; 
  while (t--) solve();
}
void solve() {
  ll d, k;
  cin >> d >> k;
  ll l = 0, r = 1e6/k;
  while (l <= r) {
    ll m = l + (r-l)/2;
    bool ok = (m*m+m*m)*k*k<=d*d;
    if (ok) {
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  if ((r*r+(r+1)*(r+1))*k*k-d*d>0) {
    cout<<"Utkarsh\n";
  }else{
    cout<<"Ashish\n";
  }
}
