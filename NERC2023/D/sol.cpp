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
ll sum_of_digits(ll x) {
    ll res = 0;
    while (x) {
        res += x%10;
        x /= 10;
    }
    return res;
}

void validate(ll n, ll ans) {
    if (ans%n == 0 && sum_of_digits(ans)%n==0){
        dbg(n,ans,"ok");
    }else{
        dbg(n,ans,"ok");
        assert(false);
    }
}

auto solve(int n) {
 
    cin >> n;
    string s = to_string(n);
    dbg(s);
    string res="";
    while(n--){
        res+=s;
    }

    return res.size();
}

void bf() {
    // for (ll n = 1; n <= 1000; n++) {
    //     solve(n);
    // }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);       

    bf();

    ll T;
    T = 1;
    for (ll tc = 1; tc <= T; tc++) {
        ll n; cin >> n;
        auto res = solve(n);
        cout << res << "\n";
    }
    return 0;
}
