
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back

// ====== Sometimes you need a little wishful thinking to keep on living

/* Manacher's Algorithm
 * Finding all sub-palindromes in O(N)
 * It fill's three arrays : manacher_odd (N), manacher_even (N) , manacher_length (2*N-1)
 * manacher_odd[i] : It is the maximum value s.t. [i - manacher_odd[i]] to [i + manacher_odd[i]] is pallindrome.
 * manacher_even[i] : If -1 then a[i] != a[i-1]
                    : else [i - 1 - manacher_even[i]] to [i + manacher_even[i]] is pallindrome.
 * manacher_length[i] (0 <= i <= 2*N-2)  : Length of the pallindome having i'th center.
 * There are 2*N-1 place for mid point of pallindrome
 * ***** Explanation *****
 * a b c b c b a
 *
 * | | | | | | | N        Total = 
 *  | | | | | |  N -1             2*N-1
 * 0123456789...
 * https://judge.yosupo.jp/submission/197382 - Library Checker Verified
 * https://cp-algorithms.com/string/manacher.html                   
 */
vector<ll> manacher_even, manacher_odd, manacher_length;
vector<ll> manacher_odd_index(string s) { // abcbcba
                                          // #a#b#c#b#c#b#a#
                                          // $#a#b#c#b#c#b#a#
                                          // 01234....
  s = "$" + s + "^";
  ll n = s.size();
  vector<ll> res(n, 1);
  ll r = 0, b = 0;
  for (ll i = 1; i < n; i++) {
    if (i <= r) {
      res[i] = max(0ll, min(res[2*b - i], r - i));
    }
    while (s[i + res[i]] == s[i - res[i]]) {
      res[i]++;
    }
    res[i]--;
    if (i + res[i] > r) {
      r = i + res[i];
      b = i;
    }
  }
  return res;
}

void manacher(string s) {
  ll n = (ll)s.size();
  manacher_odd = vector<ll> (n, 0);
  manacher_even = vector<ll> (n, 0);
  string t = "";
  for (auto& c : s) {
    t += '#';
    t += c;
  }
  t += '#';
  vector<ll> res = manacher_odd_index(t);
  for (ll i = 0; i < n; i++) {
    manacher_odd[i] = res[2*i + 2] / 2;
  }
  for (ll i = 0; i < n; i++) {
    manacher_even[i] = res[2*i+1] / 2 - 1;
  }
  for (ll i = 0; i < n; i++) {
    manacher_length.pb(manacher_odd[i]*2+1);
    if (i < n - 1)
      manacher_length.pb(manacher_even[i + 1]*2+2);
  }
}

bool manacher_pallindrome(ll l, ll r) {
  if ((r - l + 1) % 2 == 1) {
    ll m = (l + r) / 2;
    return manacher_odd[m]*2 + 1 >= r - l + 1;
  }
  else {
    ll m = (l + r + 1) / 2;
    return manacher_even[m]*2 + 2 >= (r - l + 1);
  }
  return false;
}

// ====== Liar.

void solve() {
  string s = "abcbcba";
  cin >> s;
  ll n = (ll)s.size();
  manacher(s);
  if(!manacher_pallindrome(0, n-1)) {
    cout << "YES\n";
    cout << 1 << "\n";
    cout << s << "\n";
    return;
  }
  for (ll i = 0; i < n - 1; i++) {
    if (!manacher_pallindrome(0,i) && !manacher_pallindrome(i+1,n-1)) {
      cout << "YES\n";
      cout << 2 << "\n";
      string a, b;
      a = b = "";
      for (ll j = 0; j <= i; j++)
        a += s[j];
      for (ll j = i + 1; j < n; j++)
        b += s[j];
      cout << a << " " << b << "\n";
      return;
    }
  }
  cout << "NO\n";
}
int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
