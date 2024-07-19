
#include<bits/stdc++.h>
using namespace std;
using ll=int;
#define pb push_back
template <typename T>
using Vec = vector<T>;

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
 * https://judge.yosupo.jp/submission/197379 - Library Checker Verified
 * https://cp-algorithms.com/string/manacher.html                   
 */
vector<ll> manacher_even, manacher_odd, manacher_length;
vector<ll> manacher_odd_index(string s) { // abcbcba
                                          // #a#b#c#b#c#b#a#
                                          // $#a#b#c#b#c#b#a#
                                          // 01234....
  s = '$' + s + '^';
  ll n = s.size();
  vector<ll> res(n, 1);
  ll r = 0, b = 0;
  for (ll i = 1; i < n; i++) {
    if (i <= r) {
      res[i] = max(0, min(res[2*b - i], r - i));
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
}
bool pallindrome(ll l, ll r) {
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
void solve();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t; cin >> t; while (t--) solve();
}

void solve() {
  ll n, q; string s;
  cin >> n >> q >> s;
  manacher(s);
  Vec<ll> dp(n, -1);
  Vec<ll> dp2(n, -1);
  for (ll  i = 0; i < n; i++) {
    dp[i] = i;
    dp2[i] = i;
  }
  for (ll i = n - 2; i >= 0; i--) {
    if (s[i] == s[i+1]) {
      dp[i] = dp[i+1];
    }
    if (i + 2 < n && s[i] == s[i+2]) {
      dp2[i] = dp2[i + 2];
    }
  }

  while (q--) {
    ll l, r;
    cin >> l >> r;
    l--; r--;
    if (l == r) {
      cout << 0 << "\n";
      continue;
    }
    bool cp, alt, aeq;
    cp = alt = aeq = false;
    cp = pallindrome(l ,r);
    aeq = dp[l] >= r;
    if (l%2 == r%2) {
      alt = (dp2[l] >= r && dp2[l+1] >= r-1);
    } else {
      alt = (dp2[l] >= r-1 && dp2[l+1] >= r);
    }
    if (aeq) {
      cout << 0 << "\n";
      continue;
    }
    ll len = r - l + 1;
    if (alt) {

      long long sum = 1ll*(len/2)*((len/2)+1);
      if (len%2==0 && cp) sum -= len;
      cout << sum << "\n";
      continue;
    }
    long long fans = (1ll*len*(len+1))/2;
    fans -= 1;
    if (cp) fans -= len;
    cout << fans << "\n";
  }
}
