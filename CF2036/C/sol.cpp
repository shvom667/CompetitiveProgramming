#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;
 
#ifndef ONLINE_JUDGE
    #include"/home/shivom/Downloads/CP/DataStructures/debug.cpp"
    #include"/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
#else
    #define dbg(...) 42
    #define rnd(...) 42
#endif
 
auto solve() {
    string s;cin>>s;ll n=s.size();ll q;cin>>q;
    auto chk = [&](ll i){
        if(i+3<n){
            if(s[i]=='1'&&s[i+1]=='1'&&s[i+2]=='0'&&s[i+3]=='0'){
                return 1;
            }
        }
        return 0;
    };
    vector<ll> is(n,0);
    ll cnt=0;
    for(ll i=0;i<n;i++){
        is[i]=chk(i);
        cnt+=is[i];
    }
    vector<string>fans;
    while(q--){
        ll a,b;cin>>a>>b;
        a--;
        for(ll j=max(0ll,a-5);j<min(n,a+5);j++){
            if (chk(j)){
                is[j]=0;
                cnt--;
            }
        }
        s[a] = '0'+b;
        for(ll j=max(0ll,a-5);j<min(n,a+5);j++){
            if (chk(j)){
                is[j]=1;
                cnt++;
            }
        }
        if(cnt){
            fans.pb((string)"YES");
        }else{

            fans.pb((string)"NO");
        }
    }
    return fans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        // cout << res << "\n";
        for(auto&x:res){
            cout<<x<<"\n";
        }//cout<<'\n';
    }
    return 0;
}
