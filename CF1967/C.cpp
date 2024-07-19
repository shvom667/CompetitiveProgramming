
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
    ll n, k;
    cin >> n >> k;
    ll a[n];
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    ll l = *min_element(a, a+n);
    ll r = 4e17;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        bool ok=true;
        ll reqd=0;
        for (ll i = 0; i<n;i++)
            if (a[i] < mid) {
                reqd += mid-a[i];
                if (reqd > k)
                    ok=false;
            }
        if(ok){
            if(reqd>k)
                ok=false;
        }
        if(ok)
            l=mid+1;
        else
            r=mid-1;
    }
    sort(a, a+n);
    ll b[n];
    for (ll i = 0; i < n; i++)
    {
        b[i] = a[i];
        if (b[i] < r) {
            k -= r - b[i];
            b[i] = r;
        }
    }
    ll v = 0;
    for (ll i = n - 1; i >= 0; i--) {
        if (b[i] > r) {
            v++;
        } else {
            if (k>0) {
                k--;
                v++;
            }
        }
    }
    cout << n*r-(n-1) + v << '\n';
}
