#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#ifndef ONLINE_JUDGE
#include "/home/shivom/Downloads/CP/DataStructures/debug.cpp"
#include "/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
#else
#define dbg(...) 42
#define rnd(...) 42
#endif

// Recursive function to process each element in sb
bool solve(ll x, map<ll, ll>& sa) {
    if (sa.find(x) != sa.end() && sa[x] > 0) {
        // If x is present in sa, erase one instance from sa
        sa[x]--;
        if (sa[x] == 0) {
            sa.erase(x);
        }
        return true;
    }
    
    // If x is smaller than the minimum element in sa, return false
    if (sa.empty() || x < sa.begin()->first) {
        return false;
    }
    
    // If x is even, break it llo a = x/2, b = x/2
    if (x % 2 == 0) {
        return solve(x / 2, sa) && solve(x / 2, sa);
    }
    // If x is odd, break it llo a = (x+1)/2, b = x/2
    else {
        return solve((x + 1) / 2, sa) && solve(x / 2, sa);
    }
}

// Function to solve the problem
string processTestCase(vector<ll>& a, vector<ll>& b) {
    long long sum_a = 0, sum_b = 0;
    
    // Calculate the sum of elements in a and b
    for (ll x : a) sum_a += x;
    for (ll x : b) sum_b += x;
    
    // If sums are not equal, return "No"
    if (sum_a != sum_b) return "No";
    
    // Remove common elements from a and b
    map<ll, ll> sa, sb;
    
    for (ll x : a) sa[x]++;
    for (ll x : b) sb[x]++;
    
    map<ll, ll> cc;
    for (auto& [key, count] : sb) {
        if (sa.find(key) != sa.end() && sa[key] > 0) {
            ll common_count = min(sa[key], count);
            cc[key] = common_count;
        }
    }

    vector<ll>esa,esb;
    for (auto &[k,v]:cc) {
        sa[k] -= v;
        sb[k] -= v;
        if(sa[k]==0)esa.push_back(k);
        if(sb[k]==0)esb.push_back(k);
    }

    for(auto x:esa){
        sa.erase(x);
    }
    for(auto x:esb){
        sb.erase(x);
    }

    dbg(sa);
    dbg(sb);

    

    // Now process elements in sb recursively
    bool all_good = true;
    for (auto& [x, count] : sb) {
        while (count-- > 0) {
            if (!solve(x, sa)) {
                all_good = false;
                break;
            }
        }
        if (!all_good) break;
    }

    return all_good ? "Yes" : "No";
}

int main() {
    ll t;
    cin >> t;

    while (t--) {
        ll n, m;
        cin >> n >> m;
        
        vector<ll> a(n), b(m);
        for (ll i = 0; i < n; i++) cin >> a[i];
        for (ll i = 0; i < m; i++) cin >> b[i];
        
        cout << processTestCase(a, b) << endl;
    }

    return 0;
}
