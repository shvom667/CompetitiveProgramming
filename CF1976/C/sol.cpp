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

auto solve() {
    ll n,m;cin>>n>>m;vector<ll>a(n+m+2),b(n+m+2);
    for(ll i=1;i<=n+m+1;i++)cin>>a[i];
    for(ll i=1;i<=n+m+1;i++)cin>>b[i];

    vector<ll> ph(n + m + 2, 0);
    vector<ll> th(n + m + 2, 0);
    vector<ll> res(n + m + 2, 0);

    vector<ll> psum_best(n + m + 2 , 0);
    vector<ll> psum_p(n + m + 2, 0);
    vector<ll> psum_t(n + m + 2, 0);
    vector<ll> cnt_p(n + m + 2, 0);
    vector<ll> cnt_t(n + m + 2, 0);

    for (ll i = 1; i <= n + m + 1; i++) {
        psum_p[i] = psum_p[i - 1] + a[i];
        psum_t[i] = psum_t[i - 1] + b[i];
        psum_best[i] = psum_best[i  - 1] + max(a[i], b[i]);
        cnt_p[i] += cnt_p[i - 1];
        cnt_t[i] += cnt_t[i - 1];
        if (a[i] > b[i]) {
            cnt_p[i] += 1;
        } else {
            cnt_t[i] += 1;
        }
    }



    for(ll i = 1; i <= n + m + 1; i++) {
        ph[i] = ph[i - 1];
        th[i] = th[i - 1];
        res[i] += res[i - 1];
        if (a[i] > b[i]) {
            if (ph[i] != n) {
                ph[i]++;
                res[i] += a[i];
            } else {
                th[i]++;
                res[i] += b[i];
            }
        }
        if (a[i] < b[i]) {
            if (th[i] != m) {
                th[i]++;
                res[i] += b[i];
            } else {
                ph[i]++;
                res[i] += a[i];
            }
        }
    }

    dbg(res);

    for (ll i = 1; i <= n + m + 1; i++) {
        ll fans = 0;
        fans += res[i - 1];
        ll leftp = n - ph[i - 1], leftt = m - th[i - 1];
        if (leftp == 0) {
            fans += psum_t[n + m + 1] - psum_t[i];
            cout << fans << " ";
            continue;
        }
        if (leftt == 0) {
            fans += psum_p[n + m + 1] - psum_p[i];
            cout << fans << " ";
            continue;
        }
        ll l = i + 1,  r = n + m + 1;
        auto cond = [&] (ll mid) {
            return (cnt_p[mid] - cnt_p[i] <= leftp 
                &&
                cnt_t[mid] - cnt_t[i] <= leftt
                );
        };
        while (l <= r) {
            ll mid = l + (r - l) /2 ;
            if (cond(mid)) {
                l = mid + 1;
            }  else {
                r = mid - 1;
            }
        }
        dbg(r);
        fans += psum_best[r] - psum_best[i];
        dbg(cnt_p[r], cnt_p[i]);
        if (cnt_p[r] - cnt_p[i] == leftp) {
            fans += psum_t[n + m + 1] - psum_t[r];
        } else {
            dbg("hi");
            fans += psum_p[n + m + 1] - psum_p[r];
        }
        cout << fans << " ";
    }
    cout << '\n';


    dbg(ph);
    dbg(th);
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
	    auto res = solve();
	    // cout << res << "\n";
    }
    return 0;
}
