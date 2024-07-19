
#include<bits/stdc++.h>
using namespace std;



using ll=long long;

template <typename T>
using V = vector<T>;

#define pb push_back

void solve();

int main() {
    ll t;
    cin>>t;
    while(t--)solve();
}

void solve() {
    ll n;
    string s;
    cin >> n>>s;
    ll a[n];
    for (ll i=0;i<n;i++) {
        a[i] = s[i] - '0';
        if (i) a[i] += a[i-1];
    }
    string res=""; ll p = 0;
    for (ll i=n-1; i>=0;i--){
        p += a[i];
        res += '0'+p%10ll;
        p /= 10ll;
    }
    while (p) {
        res += '0'+p%10ll;
        p/=10ll;
    }
    while(res.back()=='0')res.pop_back();
    reverse(begin(res),end(res));
    cout<<res<<"\n";
}
