#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define eb emplace_back
#define pyes cout << "YES" << '\n'
#define pno cout << "NO" << '\n'
#define int unsigned long long
#define forn(i, n) for (int i = 0; i < int(n); i++)
const int MAXN = 2e5 + 20;
const int LMAXN = 9223372036854775807;  // the max value of long long int
long long MOD = 998244353;
// ll a[MAXN], pre[MAXN];
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
#define m_p make_pair
#define vi vector<int>

#define lp(i, a, b) for (int i = a; i < b; i++)
#define fastIO()                \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);

using namespace std;

void print(int a) {
  cout << a << '\n';
}
void print(vector<int> &a) {
  for(auto it : a) {
    cout << it << ' ';
  }
  cout << '\n';
}
void print(vector<vi> &a) {
  for(auto it : a) {
    for(auto e : it) {
      cout << e << ' ';
    }
    cout << '\n';
  }
}

template <typename T>
void print1dvector(vector<T> V) {
  for (auto it : V) {
    cout << it << ' ';
  }
  cout << '\n';
}

template <typename T>
void print2dvector(vector<vector<T>> V) {
  for (auto it : V) {
    for (auto itr : it) {
      cout << itr << ' ';
    }
    cout << '\n';
  }
}

struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};

template <std::size_t MAXN>  // change the value of bitest to any size (say nax)
                             // that you need to assign
                             bool operator<(const std::bitset<MAXN>& x,
                                            const std::bitset<MAXN>& y) {
  for (int i = MAXN - 1; i >= 0; i--) {
    if (x[i] ^ y[i]) return y[i];
  }
  return false;
}

void makeUniq(vector<int>& vec) {
  sort(all(vec));
  vec.resize(unique(all(vec)) - vec.begin());
}

int binaryStrToDecimal(string b) { return stol(b, nullptr, 2); }

int nxt() {
  int x;
  cin >> x;
  return x;
}

int Sqrt(int n) {
  int l = 1, r = n, ans = n;
  while (r >= l) {
    int mid = (l + r) / 2;
    if (mid > n / mid)
      r = mid - 1;
    else {
      ans = mid;
      l = mid + 1;
    }
  }
  return ans;
}

bool isPerfectSquare(int n) {
  int x = Sqrt(n);
  return x * x == n;
}

ll accurateFloor(ll a, ll b) {  // gives the accurate floor for -ve/+ve
  ll val = a / b;
  while (val * b > a) val--;
  return val;
}

ll GCD(ll a, ll b) { return (a) ? GCD(b % a, a) : b; }

ll LCM(ll a, ll b) { return a * b / GCD(a, b); }

bool isPowerOf2(ll n) { return (ceil(log2(n)) == floor(log2(n))); }
/*
 unsigned int hibit(unsigned int x) { // return the position of highest set
 bit
  if(x == 0) {
    return 0;
  } else {
    return (32 - (__builtin_clz(x | 1)));
  }
}
*/
ll fastpow(ll b, ll p) {
  if (!p) return 1;
  ll ret = fastpow(b, p >> 1);
  ret *= ret;
  if (p & 1) ret *= b;
  return ret;
}
int powermodulo(int a, int p, int m) {
  int ans = 1;
  a = a % m;
  while (p > 0) {
    if (p & 1) ans *= a;
    ans = ans % m;
    a = (a * a) % m;
    p = p >> 1;
  }
  return ans;
}
int inverse(int a, int p = MOD) { return (powermodulo(a, p - 2, p)) % p; }
struct DSU {
  vector<int> e;
  DSU(int N) { e = vector<int>(N, -1); }
  // get representive component (uses path compression)
  int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
  bool same_set(int a, int b) { return get(a) == get(b); }
  int size(int x) { return -e[get(x)]; }
  bool unite(int x, int y) {  // union by size
    x = get(x), y = get(y);
    if (x == y) return false;
    if (e[x] > e[y]) swap(x, y);
    e[x] += e[y];
    e[y] = x;
    return true;
  }
};
vector<int> fact;
void pre_calc_fact() {
  int nax = 4e5 + 10;
  fact = vector<int>(nax);
  fact[0] = 1;
  for (int i = 1; i < nax; i++) {
    fact[i] = ((fact[i - 1] % MOD) * i) % MOD;
  }
}

int combination(int n, int r) {
  return ((fact[n] % MOD * inverse(fact[r]) % MOD) % MOD *
          inverse(fact[n - r]) % MOD);
}

int mod_add(int a, int b) {
    return (a+b)%MOD;
}
int mod_sub(int a, int b) {
    return (a-b+MOD)%MOD;
}
int mod_mult(int a, int b) {
    return (a*b)%MOD;
}
int mod_div(int a, int b) {
    return (mod_mult(a , inverse(b)));
}

struct fTree {
  vector<int> bit;  // binary indexed tree
  int n;

  fTree(int n) {
    this->n = n + 1;
    bit.assign(n + 1, 0);
  }

  fTree(vector<int> a) : fTree(a.size()) {
    for (size_t i = 0; i < a.size(); i++) add(i, a[i]);
  }

  int sum(int idx) {
    int ret = 0;
    for (++idx; idx > 0; idx -= idx & -idx) ret += bit[idx];
    return ret;
  }

  int sum(int l, int r) { return sum(r) - sum(l - 1); }

  void add(int idx, int delta) {
    for (++idx; idx < n; idx += idx & -idx) bit[idx] += delta;
  }
  void setX(int indx, int x) { add(indx, x - sum(indx, indx)); }
};

const int nax = 2e5 + 20;
const int inf = 2e14 + 10;
int n;
int A[nax];
vector<int> adj[nax];
int lll[nax];
bool ans=true;
void dfs(int i, int mid) {
  if(ans==false)return;
  if(adj[i].size()==0) {
    lll[i] = mid;
    if(lll[i] < A[i]) {
      ans = false;
    }
    lll[i] = lll[i] - A[i];
    return;
  }
  for(auto  it : adj[i]){
    dfs(it, mid);
    lll[i] += lll[it];
  }
  if(lll[i] < A[i]) {
    ans = false;
  }
  lll[i] = lll[i] - A[i];
}
void solve() {
  cin >> n;
  for(int i=1;i<n;i++){
    int x; cin >> x; --x;
    adj[x].pb(i);
  }
  for(int i=0;i<n;i++) {
    cin >> A[i];
  }
  int L = 0, R = inf;
  while(L <= R) {
    int mid = L + ( R - L ) / 2;
    //cout << mid << " ";
    for(int i=0;i<n;i++){
      lll[i] = 0;
    }
    ans = true;
    dfs(0, mid);
    if(ans) {
      R = mid - 1;
    } else {
      L = mid + 1;
    }
  }
  cout << L << "\n";
}

signed main() {
  fastIO();
  pre_calc_fact();
  //int t = nxt();
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}

/*
    NO NEED TO CODE WITHOUT A COMPLETE ALGORITHM!!!
    THINK OF WHAT THE PROBLEM DEMANDS!!!
 */
/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */

/*
 ll fastpow(ll b, ll p) {
  if (!p) return 1;
  ll ret = fastpow(b, p >> 1);
  ret = ((ret%MOD) * (ret%MOD));
  if (p & 1) ret = ((ret%MOD) * (b%MOD));
  return ret%MOD;
}
*/
/* "double precision" cout << fixed << std:setprecision(10) << '\n' */
/* min heap "priority_queue<int, vector<int> , greater<int>>" */
/*
  1. Understanding the problem.
  2. Using past problems.
  3. Using known ideas and algorithms
  4. Observations Reductions RandomIdeas AnswerBounds SimplerProblems
 */

