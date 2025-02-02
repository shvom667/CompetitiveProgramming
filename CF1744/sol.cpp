#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;

#ifndef ONLINE_JUDGE
#include "/home/shivom/Downloads/CP/DataStructures/debug.cpp"
#include "/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
#else
#define dbg(...) 42
#define rnd(...) 42
#endif

auto solve() {
    ll a, b, c, d;
    cin>>a>>b>>c>>d;
    vector<ll>fa,fb;
    for(ll i=1;i<=sqrtl(a);i++){
        if(a%i==0){
            fa.pb(i);
            if(i!=a/i)fa.pb(a/i);
        }
    }


    for(ll i=1;i<=sqrtl(b);i++){
        if(b%i==0){
            fb.pb(i);
            if(i!=b/i)fb.pb(b/i);
        }
    }
    // dbg(fa);
    // dbg(fb);

    for(auto x:fa)
        {
            for(auto y:fb){
        ll v1=(ll)x*y;
        ll v2=(ll)a*b;
        v2/=x;
        v2/=y;
        // dbg(x,y,v1,v2,a,b);
        assert(v1*v2==a*b);
        if((a+1)%v1 != 0) v1 = a + 1 + v1 - (a+1)%v1;
        else v1 = a + 1;
        if((b+1)%v2 != 0) v2 = b + 1 + v2 - (b+1)%v2;
        else v2 = b + 1;
        if(v1 <= c && v2 <= d){
            cout<<v1<<" "<<v2<<'\n';
            return 0;
        } 
            }
    }
    cout<<"-1 -1\n";
    
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll T;
	cin >> T;
	for (ll tc = 1; tc <= T; tc++) {
		auto res = solve();
		// cout << res << "\n";
	}
	return 0;
}
