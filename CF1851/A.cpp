
#include<bits/stdc++.h>
using namespace std;



using ll=long long;

template <typename T>
using V = vector<T>;

#define pb push_back

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin>>t;
    while(t--)solve();
}

void solve() {
    ll n,m,k,H;
    cin>>n>>m>>k>>H;
    ll c=0;
    for(ll i=0;i<n;i++) {
        ll x;
        cin>>x;
        if(((abs(H-x))%k)==0) {
            if ((abs(H-x))/k <= m-1 && (abs(H-x))/k >= 1) {
                c++;
            }
        }
    }
    cout<<c<<"\n";
}
