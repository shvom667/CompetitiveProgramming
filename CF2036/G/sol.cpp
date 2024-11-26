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
ll ask(ll l, ll r) {
    cout << "xor " << l << " " << r << endl;
    ll ans;cin>>ans;return ans;
}
ll B=60;
auto solve() {
    ll n;cin>>n;
    ll tx = ask(1,n);
    if (tx == 0) {
        ll a = -1;
        ll L=-1;
        for (ll bit = B; bit >= 1; bit--) {
            ll y = min(n, (1ll <<bit) - 1);
            ll res = ask(1, y);
            L = y;
            if (res > 0) {
                a = res;
                break;
            }
        }
        ll R = n;
        auto cond=[&](ll mid){
            return ask(1,mid)==a;
        };
        while (L<=R){
            ll mid=L+(R-L)/2;
            if(cond(mid)){
                L=mid+1;
            }else{
                R=mid-1;
            }
        }
        ll ab = ask(1,R+1);
        ll b = (a ^ ab);
        ll c = a ^ b;
        cout << "ans " << a << " " << b << " " << c << endl; 
    }else{
        ll a,b,c;
        ll L=1,R=n;
        auto cond=[&](ll mid){
            return ask(1,mid)==0;
        };
        while(L<=R){
            ll mid=L+(R-L)/2;
            if(cond(mid)){
                L=mid+1;
            }else{
                R=mid-1;
            }
        }
        a=ask(1,R+1);
        L=R+1,R=n;
        auto cond2=[&](ll mid){
            return ask(1,mid)==a;
        };
        while(L<=R){
            ll mid=L+(R-L)/2;
            if(cond2(mid)){
                L=mid+1;
            }else{
                R=mid-1;
            }
        }
        ll ab = ask(1,R+1);
        b = a ^ ab;
        c = (tx^a^b);
        cout << "ans " << a << " " << b << " " << c << endl; 
    }
    return 0;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        auto res = solve();
        // cout << res << "\n";
    }
    return 0;
}
