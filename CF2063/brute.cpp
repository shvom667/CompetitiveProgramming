#include<bits/stdc++.h>
#define all(a) a.begin(),a.end()
#define rev(a) a.rbegin(),a.rend()
#define endl '\n'

using namespace std;
typedef long long ll;
const ll M = 1000000007;
const ll INF = 1000000000000000000;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m, t; cin >> t;
    while(t--) {
        cin >> n >> m;
        ll kmax = (n + m) / 3;
        if(n > 2 * m) kmax = m;
        if(m > 2 * n) kmax = n;

        vector<ll> a(n), b(m);

        for(ll &x: a) cin >> x;
        for(ll &x: b) cin >> x;

        sort(all(a));
        sort(all(b));

        deque<ll> da, db;

        ll l = 0, r = n - 1;
        while(l <= r) {
            if(l == r) {
                da.push_back(0);
                break;
            }

            da.push_back(a[r] - a[l]);
            l++, r--;
        }

        l = 0, r = m - 1;
        while(l <= r) {
            if(l == r) {
                db.push_back(0);
                break;
            }

            db.push_back(b[r] - b[l]);
            l++, r--;
        }

        ll curr = 0;
        vector<ll> ans;

        vector<tuple<ll, ll, ll, ll>> history;

        while(true) {
            if(da.empty() || db.empty()) break;
            if(da[0] == 0 && db[0] == 0) break;

            if(da[0] > db[0]) {
                curr += da[0];
                if(db.back() > 0) {
                    history.emplace_back(0LL, da[0], 0, db.back());
                    db.back() = 0;
                } else {
                    history.emplace_back(0LL, da[0], 1, -1);
                    db.pop_back();
                }

                da.pop_front();
            } else {
                curr += db[0];
                if(da.back() > 0) {
                    history.emplace_back(1LL, db[0], 0, da.back());
                    da.back() = 0;
                } else {
                    history.emplace_back(1LL, db[0], 1, -1);
                    da.pop_back();
                }
                
                db.pop_front();
            }

            ans.push_back(curr);
        }

        reverse(all(history));

        auto restore = [&] (ll used, ll value, ll popped, ll z_val) {
            if(used == 0) {
                da.push_front(value);
                if(popped) db.push_back(0);
                else db.back() = z_val;
                curr -= value;
            } else {
                db.push_front(value);
                if(popped) da.push_back(0);
                else da.back() = z_val;
                curr -= value;
            }
        };

        if(ans.size() < kmax) {
            ll ptr = 0;
            if(da.empty()) {
                swap(da, db);
                for(auto &[q, w, e, r]: history) q = 1 - q;
            }

            for(auto [used, value, popped, z_val]: history) {
                if(ans.size() == kmax) break;
                if(used == 1) {
                    restore(used, value, popped, z_val);
                    curr += da[ptr]; ptr++; curr += da[ptr]; ptr++;
                    ans.push_back(curr);
                } 
            }
        }


        cout << kmax << endl;
        assert(ans.size() == kmax);
        for(auto x: ans) cout << x << " "; cout << endl;
    }

    return 0;
}
