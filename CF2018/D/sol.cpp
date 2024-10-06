#include <bits/stdc++.h>
#include <unistd.h> // for sleep

using namespace std;
using ll = long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;

#define fastIO()                \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
#define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "/home/shivom/Downloads/CP/DataStructures/debug.cpp"
#else
#define dbg(...) 42
#endif

// #define LOCAL

#ifdef LOCAL
#include "/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"

#else
#define rnd(...) 42
// do other stuff
#endif
#define ALL(x) begin(x), end(x)
template <typename T>
void makeUniq(vector<T> &vec)
{
  vec.resize(unique(ALL(vec)) - vec.begin());
}

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define fbo(x) find_by_order(x)
#define ook(x) order_of_key(x)
/*
 * find_by_order(x) : return the (x + 1) th smallest element
 * order_of_key(x)  : number of elements strictly less than x
 */

auto solve(ll n, vector<ll> a)
{
  ordered_set L;
  ordered_set R;
  multiset<ll> sz;
  multiset<ll> s5e, s5o;
  vector<ll> mi, pi[2];
  map<ll, vector<ll>> mp;
  vector<ll> b = a;

  sort(begin(b), end(b));
  makeUniq(b);
  dbg(b);

  for (ll i = 0; i < n; i++)
  {
    if (a[i] == b[(ll)b.size() - 1])
    {
      mi.pb(i);
      pi[i % 2].pb(i);
    }
  }
  dbg(mi);
  dbg(pi[0]);
  dbg(pi[1]);

  for (ll i = 0; i < n; i++)
  {
    mp[a[i]].pb(i);
  }
  dbg("yaho");
  dbg(mp);

  ll prev = 0;
  ll fans = 0;
  for (ll i = (ll)b.size() - 1; i >= 0; i--)
  {
    ll v = b[i];
    ll cur = prev;
    for (auto &ind : mp[v])
    {
      bool lft, rht;
      pair<ll, ll> pl, pr;
      pl = pr = make_pair(-1ll, -1ll);
      lft = rht = false;
      ll il = R.ook(ind) - 1;
      // dbg(il);
      if (il >= 0)
      {
        ll val = *R.fbo(il);
        if (val == ind - 1)
        {
          lft = true;
          pl.first = *L.fbo(il);
          pl.second = val;
        }
      }
      ll rl = L.ook(ind + 2) - 1;
      if (rl >= 0)
      {
        ll val = *L.fbo(rl);
        if (val == ind + 1)
        {
          rht = true;
          pr.first = val;
          pr.second = *R.fbo(rl);
        }
      }
      dbg(ind, lft, rht);
      if (!lft && !rht)
      {
        L.insert(ind);
        R.insert(ind);
        sz.insert(1);
        cur += 1;
        dbg("hello");
        if ((ind - ind + 1) & 1)
        {
          auto it = lower_bound(begin(pi[ind % 2]), end(pi[ind % 2]), ind);
          dbg(ind, "sugar", it - begin(pi[ind % 2]));
          if (it != end(pi[ind % 2]) && *it <= ind)
          {
            // s5e.erase(s5e.find(pl.second-pl.first+1));
            s5o.insert(ind - ind + 1);
          }
        }
        dbg("hi");
      }
      if (lft && rht)
      {
        L.erase(pl.first);
        L.erase(pr.first);
        R.erase(pl.second);
        R.erase(pr.second);
        L.insert(pl.first);
        R.insert(pr.second);
        sz.erase(sz.find(pl.second - pl.first + 1));
        cur -= (pl.second - pl.first + 1 + 1) / 2;

        if ((pl.second - pl.first + 1) % 2 == 0)
        {
          auto it = lower_bound(begin(mi), end(mi), pl.first);
          if (it != end(mi) && *it <= pl.second)
          {
            s5e.erase(s5e.find(pl.second - pl.first + 1));
          }
        }

        if ((pl.second - pl.first + 1) & 1)
        {
          auto it = lower_bound(begin(pi[pl.first % 2]), end(pi[pl.first % 2]), pl.first);
          if (it != end(pi[pl.first % 2]) && *it <= pl.second)
          {
            s5o.erase(s5o.find(pl.second - pl.first + 1));
            // s5o.insert(ind - ind + 1);
          }
        }

        sz.erase(sz.find(pr.second - pr.first + 1));
        cur -= (pr.second - pr.first + 1 + 1) / 2;

        if ((pr.second - pr.first + 1) % 2 == 0)
        {
          auto it = lower_bound(begin(mi), end(mi), pr.first);
          if (it != end(mi) && *it <= pr.second)
          {
            s5e.erase(s5e.find(pr.second - pr.first + 1));
          }
        }

        if ((pr.second - pr.first + 1) & 1)
        {
          auto it = lower_bound(begin(pi[pr.first % 2]), end(pi[pr.first % 2]), pr.first);
          if (it != end(pi[pr.first % 2]) && *it <= pr.second)
          {
            s5o.erase(s5o.find(pr.second - pr.first + 1));
            // s5o.insert(ind - ind + 1);
          }
        }

        sz.insert(pr.second - pl.first + 1);

        if ((pr.second - pl.first + 1) % 2 == 0)
        {
          auto it = lower_bound(begin(mi), end(mi), pl.first);
          if (it != end(mi) && *it <= pr.second)
          {
            s5e.insert(pr.second - pl.first + 1);
          }
        }

        if ((pr.second - pl.first + 1) & 1)
        {
          auto it = lower_bound(begin(pi[pl.first % 2]), end(pi[pl.first % 2]), pl.first);
          if (it != end(pi[pl.first % 2]) && *it <= pr.second)
          {
            // s5o.erase(s5o.find(pr.second-pr.first+1));
            s5o.insert((pr.second - pl.first + 1));
          }
        }
        cur += (pr.second - pl.first + 1 + 1) / 2;
      }
      if (lft && !rht)
      {
        L.erase(pl.first);
        R.erase(pl.second);
        L.insert(pl.first);
        R.insert(ind);
        sz.erase(sz.find(pl.second - pl.first + 1));
        dbg(pl);
        cur -= (pl.second - pl.first + 1 + 1) / 2;

        if ((pl.second - pl.first + 1) % 2 == 0)
        {
          auto it = lower_bound(begin(mi), end(mi), pl.first);
          if (it != end(mi) && *it <= pl.second)
          {
            s5e.erase(s5e.find(pl.second - pl.first + 1));
          }
        }

        if ((pl.second - pl.first + 1) & 1)
        {
          auto it = lower_bound(begin(pi[pl.first % 2]), end(pi[pl.first % 2]), pl.first);
          if (it != end(pi[pl.first % 2]) && *it <= pl.second)
          {
            s5o.erase(s5o.find(pl.second - pl.first + 1));
            // s5o.insert((pr.second-pl.first+1));
          }
        }

        sz.insert(ind - pl.first + 1);

        if ((ind - pl.first + 1) % 2 == 0)
        {
          auto it = lower_bound(begin(mi), end(mi), pl.first);
          if (it != end(mi) && *it <= ind)
          {
            s5e.insert(ind - pl.first + 1);
          }
        }
        if ((ind - pl.first + 1) & 1)
        {
          auto it = lower_bound(begin(pi[pl.first % 2]), end(pi[pl.first % 2]), pl.first);
          if (it != end(pi[pl.first % 2]) && *it <= ind)
          {
            // s5o.erase(s5o.find(pl.second-pl.first+1));
            s5o.insert((ind - pl.first + 1));
          }
        }

        cur += (ind - pl.first + 1 + 1) / 2;
      }
      if (!lft && rht)
      {
        L.erase(pr.first);
        R.erase(pr.second);
        L.insert(ind);
        R.insert(pr.second);
        sz.erase(sz.find(pr.second - pr.first + 1));
        cur -= (pr.second - pr.first + 1 + 1) / 2;

        if ((pr.second - pr.first + 1) % 2 == 0)
        {
          auto it = lower_bound(begin(mi), end(mi), pr.first);
          if (it != end(mi) && *it <= pr.second)
          {
            s5e.erase(s5e.find(pr.second - pr.first + 1));
          }
        }

        if ((pr.second - pr.first + 1) & 1)
        {
          auto it = lower_bound(begin(pi[pr.first % 2]), end(pi[pr.first % 2]), pr.first);
          if (it != end(pi[pr.first % 2]) && *it <= pr.second)
          {
            s5o.erase(s5o.find(pr.second - pr.first + 1));
            // s5o.insert((pr.second-pl.first+1));
          }
        }

        sz.insert(pr.second - ind + 1);

        if ((pr.second - ind + 1) % 2 == 0)
        {
          auto it = lower_bound(begin(mi), end(mi), ind);
          if (it != end(mi) && *it <= pr.second)
          {
            s5e.insert(pr.second - ind + 1);
          }
        }

        if ((pr.second - ind + 1) & 1)
        {
          auto it = lower_bound(begin(pi[ind % 2]), end(pi[ind % 2]), ind);
          if (it != end(pi[ind % 2]) && *it <= pr.second)
          {
            // s5o.erase(s5o.find(pr.second-pr.first+1));
            s5o.insert((pr.second - ind + 1));
          }
        }

        cur += (pr.second - ind + 1 + 1) / 2;
      }
    }
    fans = max(fans, b[(ll)b.size() - 1] + v + cur + (max((ll)s5e.size(), (ll)s5o.size()) > 0 ? 0 : -1));
    dbg(v, cur, fans);
    dbg(s5e);
    dbg(s5o);
    prev = cur;
    dbg(sz);
    // for (ll i = 0; i < L.size(); i++) {
    //   cout << *L.fbo(i) << " ";
    // } cout << '\n';
    // for (ll i = 0; i < R.size(); i++) {
    //   cout << *R.fbo(i) << " ";
    // } cout << '\n';
    // cout << "$$$$$$$$$$$$$$$$$$$$$$\n";
  }
  return fans;
}

auto bf(ll n, vector<ll> a)
{
  ll fans = 0;
  vector<ll> best;
  for (ll i = 0; i < (1ll << n); i++)
  {
    vector<ll> s(n, 0);
    for (ll b = 0; b < n; b++)
    {
      s[b] = ((i & (1ll << b)) > 0);
    }
    bool ok = true;
    for (ll b = 0; b < n; b++)
    {
      if (b > 0)
      {
        if (s[b] == 1 && s[b - 1] == 1)
        {
          ok = false;
        }
      }
    }
    if (ok)
    {
      vector<ll> c;
      for (ll b = 0; b < n; b++)
      {
        if (s[b] == 1)
          c.pb(a[b]);
      }
      sort(begin(c), end(c));
      if ((ll)c.size() > 0)
      {
        ll cur = (ll)c.size() + c[0] + c[(ll)c.size() - 1];
        fans = max(fans,
                   cur);
        if (fans == cur)
        {
          best = s;
        }
      }
    }
  }
  if (true)
  {
    for (ll i = 0; i < n; i++)
    {
      if (best[i] == 0)
      {
        cout << a[i] << " ";
      }
      else
      {
        cout << "\e[31m" << a[i] << "\e[0m" << " ";
      }
    }
    cout << "\n";
  }
  return fans;
}

auto stress()
{
  while (true)
  {
    ll n = rnd(2, 20);
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
      a[i] = rnd(1, 1000);
    }
    // cout << n << "\n";
    // for (auto& x : a) {
    //   cout << x << " ";
    // } cout << "\n";
    // dbg(n);
    // dbg(a);
    auto bans = bf(n, a);
    auto sans = solve(n, a);
    if (bans == sans)
    {
      cout << "ok\n";
    }
    else
    {
      cout << n << "\n";
      for (auto &x : a)
      {
        cout << x << " ";
      }
      cout << '\n';
      exit(0);
    }
    // dbg(res);
  }
}

int main()
{
  fastIO();

#ifdef LOCAL
  stress();
  return 0;
#endif  

  ll T;
  cin >> T;
  for (ll tc = 1; tc <= T; tc++)
  {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    auto res = solve(n, a);
    cout << res << "\n";
  }
  return 0;
}
