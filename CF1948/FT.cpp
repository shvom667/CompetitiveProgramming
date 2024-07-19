
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
    ll n = 5, k = 4;
    V<ll> a = {5,1,4,3,2};
    V<pair<ll,ll>> f;
    for (ll i=0; i<n; i++) {
        for (ll j = i+1; j < n; j++) {
            if (abs(i-j)+abs(a[i]-a[j])<=k)
            {
                f.pb({i+1,j+1});
            }

        }
    }
    for (auto&[x,y]:f){
        cout<<x<<" "<<y<<"\n";
    }
}
