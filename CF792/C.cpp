
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
  t = 1;
  while (t--) solve();
}
struct ans {
    string res;
    ll rm;
};
ans id;
void solve() {
    id.res = "";
    id.rm = 0;
    string s;
    cin >> s;
    ll n = s.size();
    Vec<ll> ind[3];
    ll sum = 0;
    for (ll i = n - 1; i >= 0; i--) {
        sum += s[i] - '0';
    }
    if (sum%3==0) {
        cout << s << '\n';
        return;
    }
    ll cap1 = 1;
    ll cap2 = 1;
    ll cap3 = 1;
    if (sum%3==1) {
        cap1 = 1;
        cap2 = 2;
        cap3 = -1;
    }
    if (sum%3==2) {
        cap1 = 2;
        cap2 = 1;
        cap3 = -1;
    }

    for (ll i = n - 1; i >= 0; i--)
    {
        if ((s[i] - '0') % 3 == 0) 
            ind[0].pb(i);
        if ((s[i] - '0') % 3 == 1) 
            ind[1].pb(i);
        if ((s[i] - '0') % 3 == 2) 
            ind[2].pb(i);
    }
    Vec<ans> fans;
    if (ind[1].size() >= cap1) {
        ans f = id;
        f.rm=0;
        for (ll i = n-1; i >= 0; i--) {
            bool ok=false;
            for (ll j = 0; j < cap1; j++) {
                if (i == ind[1][j])
                    ok=true;
            }
            if(ok){
                f.rm++;
            }else{
                f.res += s[i];
            }
        }
        while(f.res.size()>1 && f.res.back() == '0') {

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
  t = 1;
  while (t--) solve();
}
struct ans {
    string res;
    ll rm;
};
ans id;
void solve() {
    id.res = "";
    id.rm = 0;
    string s;
    cin >> s;
    ll n = s.size();
    Vec<ll> ind[3];
    ll sum = 0;
    for (ll i = n - 1; i >= 0; i--) {
        sum += s[i] - '0';
    }
    if (sum%3==0) {
        cout << s << '\n';
        return;
    }
    ll cap1 = 1;
    ll cap2 = 1;
    ll cap3 = 1;
    if (sum%3==1) {
        cap1 = 1;
        cap2 = 2;
        cap3 = -1;
    }
    if (sum%3==2) {
        cap1 = 2;
        cap2 = 1;
        cap3 = -1;
    }

    for (ll i = n - 1; i >= 0; i--)
    {
        if ((s[i] - '0') % 3 == 0) 
            ind[0].pb(i);
        if ((s[i] - '0') % 3 == 1) 
            ind[1].pb(i);
        if ((s[i] - '0') % 3 == 2) 
            ind[2].pb(i);
    }
    Vec<ans> fans;
    if (ind[1].size() >= cap1) {
        ans f = id;
        f.rm=0;
        for (ll i = n-1; i >= 0; i--) {
            bool ok=false;
            for (ll j = 0; j < cap1; j++) {
                if (i == ind[1][j])
                    ok=true;
            }
            if(ok){
                f.rm++;
            }else{
                f.res += s[i];
            }
        }
        while(f.res.size()>1 && f.res.back() == '0') {
            f.res.pop_back();
            f.rm++;
        }
        reverse(begin(f.res),end(f.res));
        if (f.res.size() > 0)
            fans.pb(f);
    }
    if (ind[2].size() >= cap2) {
        ans f = id;
        f.rm=0;
        for (ll i = n-1; i >= 0; i--) {
            bool ok=false;
            for (ll j = 0; j < cap2; j++) {
                if (i == ind[2][j]){
                    ok=true;
                }
            }
            if(ok){
                f.rm++;
                continue;
            }else{
                f.res += s[i];
            }
        }
        while(f.res.size()>1 && f.res.back() == '0') {
            f.res.pop_back();
            f.rm++;
        }
        reverse(begin(f.res),end(f.res));
        if (f.res.size() > 0)
            fans.pb(f);
    }
    if (cap3>0) {
        ans f = id;
        for (ll i = n - 1; i >= 0; i--) {
            if (i == ind[1][0] || i == ind[2][0]) {
                f.rm++;
            } else {
                f.res += s[i];
            }
        }
        while(f.res.size()>1 && f.res.back() == '0') {
            f.res.pop_back();
            f.rm++;
        }
        reverse(begin(f.res),end(f.res));
        if (f.res.size() > 0)
            fans.pb(f);
    }
    if (fans.size() == 0) {
        cout << -1 << '\n';
        return;
    }
    sort(begin(fans),end(fans), [&](auto a, auto b) {
            return a.rm < b.rm;
            });
    cout << fans[0].res << '\n';
}
            f.res.pop_back();
            f.rm++;
        }
        reverse(begin(f.res),end(f.res));
        if (f.res.size() > 0)
            fans.pb(f);
    }
    if (ind[2].size() >= cap2) {
        ans f = id;
        f.rm=0;
        for (ll i = n-1; i >= 0; i--) {
            bool ok=false;
            for (ll j = 0; j < cap2; j++) {
                if (i == ind[2][j]){
                    ok=true;
                }
            }
            if(ok){
                f.rm++;
                continue;
            }else{
                f.res += s[i];
            }
        }
        while(f.res.size()>1 && f.res.back() == '0') {
            f.res.pop_back();
            f.rm++;
        }
        reverse(begin(f.res),end(f.res));
        if (f.res.size() > 0)
            fans.pb(f);
    }
    if (cap3>0) {
        ans f = id;
        for (ll i = n - 1; i >= 0; i--) {
            if (i == ind[1][0] || i == ind[2][0]) {
                f.rm++;
            } else {
                f.res += s[i];
            }
        }
        while(f.res.size()>1 && f.res.back() == '0') {
            f.res.pop_back();
            f.rm++;
        }
        reverse(begin(f.res),end(f.res));
        if (f.res.size() > 0)
            fans.pb(f);
    }
    if (fans.size() == 0) {
        cout << -1 << '\n';
        return;
    }
    sort(begin(fans),end(fans), [&](auto a, auto b) {
            return a.rm < b.rm;
            });
    cout << fans[0].res << '\n';
}
