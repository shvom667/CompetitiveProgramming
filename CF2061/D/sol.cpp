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


    map<ll, ll> mp;

    mp[3] = 1;
    mp[2] = 5;
    mp[-1] = 1000;

    dbg(mp.begin()->first);


    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
	    auto res = solve();
	    cout << res << "\n";
    }
    return 0;
}


/*
    Code this up in cpp

    t test cases

    a of length n
    b of length m


    sum(a) != sum(b) "No"

    sum(a) == sum(b)
        remove common elements from a and b
        sa, sb new multiset with uncommon elems

        bool all_good = true
        for x in sb:
            recursive function sol(x):
                if (x in sa) erase a single instance of x from sa; return
                if x < min(sa) all_good = false; return
                if x even break into a = x/2, b=  x/2
                else break into a = (x+1)/2,b = x/2 

                recursively solve a and b

                
        if (all_good) return "Yes"
        else return "No"


*/