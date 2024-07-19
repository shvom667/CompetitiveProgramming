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
    cin >>n;
    V<char> a(n);
    ll j=-1;
    ll sum=0;
    for (ll i=0;i<n;i++) {
        cin>>a[i];
        if(i && a[i] == '*'&&a[i-1]=='*'&&j==-1) {
            j = i;
        }
    }
    if (j==-1)j=n-1;
    for (ll i=0;i<=j;i++) {
        if(a[i]=='@')sum++;
    }
    cout<<sum<<"\n";
}
