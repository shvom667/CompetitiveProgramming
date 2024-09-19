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
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> cnt(26, 0);
    for (ll i = 0; i < n; i++) {
        cnt[s[i]-'a']++;
    }
    vector<ll> I(26, 0);
    iota(begin(I),end(I),0ll);
    sort(begin(I),end(I),[&](auto x,auto y) {
        return cnt[x] < cnt[y];
    });
    string res="";
    while (true) {
        bool ok = false;
        for (ll i = 0; i < 26; i++) {
            ll j = I[i];
            if (cnt[j] > 0) {
                cnt[j]--;
                res += 'a' + j;
                ok = true;
            }
        }
        if (!ok) {
            break;
        }

    }
    cout << res << '\n';
}