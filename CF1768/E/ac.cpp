#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
    #include"/home/shivom/Downloads/CP/DataStructures/debug.cpp"
    #include"/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
#else
    #define dbg(...) 42
    #define rnd(...) 42
#endif
 
auto solve() {
    ll n = 1;
    cin>>n;
    vector<ll> v;
    for(ll i=1;i<=3*n;i++)v.pb(i);
    vector<vector<ll>> a1,a2;
    vector<ll> g = v;
    set<vector<ll>>s;
    do{
        // dbg(v);
        vector<ll> u1=v;
        vector<ll> u2=v;
        sort(begin(u1),begin(u1)+2*n);
        sort(begin(u1)+n,end(u1));



        sort(begin(u2)+n,end(u2));
        sort(begin(u2),begin(u2)+2*n);

        // dbg(u1,u2);
        if(u1==g||u2==g){
            // a1.pb(v);
        }else{
            s.insert(v);
        }
        if(u2==g){
            // a2.pb(v);
        }
        
    }while(next_permutation(begin(v),end(v)));
    // dbg(a1);
    // dbg(a2);

    for(auto&x:a1){
        ll cnt=0;
        for(ll i=0;i<a1.size();i++){

            if(i<2*n && x[i]>=1&&x[i]<=n)cnt++;
        }
        assert(cnt==n);
    }


    auto find_common = [&] () {
        ll res=0;
        for(auto&x:a1){
            ll cnt=0;
            for(auto&y:a2){
                if(x==y)cnt=1;
            }
            res+=cnt;
        }

        return res;
    };

    cout<<s.size()<<'\n';
    // for(auto&x:a1)s.insert(x);
    // for(auto&x:a2)s.insert(x);
    // ll tot=1;
    // for(ll i=1;i<=3*n;i++)tot*=i;
    // dbg(tot);
    // cout<<tot-s.size()<<'\n';
    // ll cm = find_common();
    // dbg(cm);
    // cout<<cm<<'\n';
    return 0;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;T=1;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        // cout << res << "\n";
    }
    return 0;
}
