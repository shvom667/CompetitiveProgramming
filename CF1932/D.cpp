
#include<bits/stdc++.h>
using namespace std;



#define SZ(x) (i32)x.size()
#define ALL(x) begin(x), end(x)
using i32=int;
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
ll n;
using ps = pair<string,string>;
V<char> av = {'C','H','D','S'};
void solve() {
    cin>>n;
    char t;
    cin>>t;
    map<char,V<string>> mp;
    for (ll i=0;i<2*n;i++){
        string s;
        cin>>s;
        mp[s[1]].pb(s);
    }
    sort(ALL(mp['C']));
    sort(ALL(mp['H']));
    sort(ALL(mp['S']));
    sort(ALL(mp['D']));
    V<ps>fans;
    V<string> lf;
    for (auto& ch:av) {
        if(ch!=t) {
            for (ll i=0;i+1<SZ(mp[ch]);i+=2) {
                fans.pb({mp[ch][i], mp[ch][i+1]});
            }
            if(SZ(mp[ch])&1) lf.pb(mp[ch].back());
        }
    }
    if (SZ(mp[t]) < SZ(lf)) {
        cout<<"IMPOSSIBLE\n";
        return;
    }
    while(SZ(lf)) {
        fans.pb({lf.back(),mp[t].back()});
        lf.pop_back();mp[t].pop_back();
    }
    for (ll i=0;i+1<SZ(mp[t]);i+=2)
        fans.pb({mp[t][i], mp[t][i+1]});
    for(auto&x:fans)
        cout<<x.first<<" "<<x.second<<"\n";
}
