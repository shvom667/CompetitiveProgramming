
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
    ll n;string s;
    cin>>s;n=s.size();
    ll m[n][n];
    for(ll i=0;i<n;i++)for(ll j=0;j<n;j++) m[i][j]=0;
    for (ll i = 0; i < n; i++) {
        for (ll len = 1; i + len < n; len++) {
            if (s[i] == s[i+len] || s[i]=='?' || s[i+len]=='?') {
                m[i][len]=1;
            } else {
                m[i][len]=0;
            }
        }
    }
    for (ll len = n-1; len >= 1; len--) {
        ll f=0,c=0;
        for (ll i=0; i<n; i++) {
            if(m[i][len]==0) c=0;
            else c++;
            f=max(f,c);
        }
        if (f >= len) {
            cout<<2*len<<"\n";
            return;
        }
    }
    cout<<0<<"\n";

}
