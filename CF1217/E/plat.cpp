#include<bits/stdc++.h>
#define all(a) a.begin(),a.end()
#define rev(a) a.rbegin(),a.rend()
#define endl '\n'

using namespace std;
typedef unsigned int ll;
const ll N = 1000000007;
const ll d = 9;
const ll INF = 2000000000;

template <typename S, S(*op)(S, S), S(*e)()> class segtree {
    public:
        vector<S> t;
        int n, sz;
        segtree() {}
        segtree(int k){
            n = k; sz = 1;
            while(sz < n) sz *= 2;
            t.resize(2 * sz, e());
        }
        segtree(vector<S> a) {
            n = a.size(); sz = 1;
            while(sz < n) sz *= 2;
            t.resize(2 * sz, e());
            for(int i = 0; i < n; i++) t[i + sz] = a[i];
            for(int i = sz - 1; i > 0; --i) t[i] = op(t[i << 1], t[i << 1 | 1]);
        }
        
        void set(int p, S value) {
            for(t[p += sz] = value; p > 1; p >>= 1) t[p >> 1] = op(t[p], t[p ^ 1]);
        }
        S prod(int l, int r) { 
            S resl = e(), resr = e();
            for (l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
                if (l & 1) resl = op(resl, t[l++]);
                if (r & 1) resr = op(t[--r], resr);
            }
            return op(resl, resr);
        }

        S get(int p) {
            return t[p + sz];
        }
};

using S = pair<ll, ll>;
S e() { return make_pair(INF, INF); }
S op(S a, S b) { 
    auto [a1, a2] = a;
    auto [b1, b2] = b;
    ll aa = min({a1, b1, a2 + b2}), bb = min(a2, b2);
    return make_pair(aa, bb);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //NO NEED TO CODE WITHOUT A COMPLETE ALGORITHM!!!
    //THINK OF WHAT THE PROBLEM DEMANDS!!!

    ll n, m; cin >> n >> m;
    segtree<S, op, e> seg[d];
    for(int i = 0; i < d; i++) {
        seg[i] = segtree<S, op, e> (n);
    }
    for(int i = 0; i < n; i++) {
        ll x; cin >> x;
        ll tmp = x, ind = 0;
        for(int j = 0; j < d; j++, tmp /= 10) {
            if(tmp % 10) seg[j].set(i, make_pair(INF, x));
        }
    }

    while(m--) {
        ll t; cin >> t;
        if(t == 1) {
            ll i, x; cin >> i >> x;
            ll tmp = x; --i;
            for(int j = 0; j < d; j++, tmp /= 10) {
                if(tmp % 10) seg[j].set(i, make_pair(INF, x));
                else seg[j].set(i, e());
            }
        } else {
            ll l, r; cin >> l >> r;
            --l, --r;
            ll mn = INF;
            for(int j = 0; j < d; j++) {
                mn = min(mn, seg[j].prod(l, r + 1).first);
            }

            if(mn == INF) cout << -1 << endl;
            else cout << mn << endl;
        }
    }

    

    return 0;
}
