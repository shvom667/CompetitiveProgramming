#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;

#ifndef ONLINE_JUDGE
#include "/home/shivom/Downloads/CP/DataStructures/debug.cpp"
#include "/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
#else
#define dbg(...) 42
#define rnd(...) 42
#endif


#define ALL(x) begin(x), end(x)
template <typename T> void makeUniq(vector<T> &vec) {
//   sort(begin(vec), end(vec));
  vec.resize(unique(ALL(vec)) - vec.begin());
}

auto solve() {
    ll n;
    cin >> n;
    Vec<ll> a(n), b(n);
    map<ll, ll> mpa, mpb;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        mpa[a[i]]++;
    }
    for (ll i = 0; i < n; i++) {
        cin >> b[i];
        mpb[b[i]]++;
    }
    if (mpa != mpb) {
        return "NO";
    }
    Vec<ll> B, A;
    B = b;
    A = a;
    makeUniq(b);
    makeUniq(a);
    ll sb = (ll)b.size();
    ll sa = (ll)a.size();
    Vec<ll> sza(sa, 0), szb(sb, 0);
    
    dbg(a);
    dbg(b);
    // exit(0);

    for (ll i = 0, j = 0; i < sa; i++) {
        ll cnt = 0;
        while (j < n && A[j] == a[i]) {
            cnt++;
            j++;
        }
        sza[i] =cnt;
    }
    dbg(A);
    dbg(B);
    for (ll i = 0, j = 0; i < sb; i++) {
        ll cnt = 0;
        while (j < n && B[j] == b[i]) {
            cnt++;
            j++;
        }
        szb[i] =cnt;
    }

    dbg(a);
    dbg(sza);
    dbg(b);
    dbg(szb);

    map<ll, ll> reqd;
    for (ll i = sb - 1, j = sa - 1; i >= 0; i--) {
        if (b[i] == a[j]) {
            dbg(i, j);
            ll mn = min(szb[i], sza[j]);
            sza[j] -= mn;
            szb[i] -= mn;
            if (sza[j] > 0) {
                reqd[a[j]] -= sza[j];
            }
            if (szb[i] > 0) {
                reqd[b[i]] += szb[i];
            }
            dbg(reqd);
            if (reqd[a[j]] < 0) {
                return "NO";
            }
            j--;
        } else {
            dbg(i, j);
            if (reqd[a[j]] >= sza[j]) {
                reqd[a[j]] -= sza[j];
                j--;
            } else {
                dbg("hello");
                return "NO";
            }
            i++;
        }
    }

    return "YES";
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
