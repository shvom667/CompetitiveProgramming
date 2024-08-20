#include<bits/stdc++.h>

using namespace std;


using ll = int;
// Debugging template
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename A>
void __print(const A &x);
template <typename A, typename B>
void __print(const pair<A, B> &p);
template <typename... A>
void __print(const tuple<A...> &t);
template <typename T>
void __print(stack<T> s);
template <typename T>
void __print(queue<T> q);
template <typename T, typename... U>
void __print(priority_queue<T, U...> q);
/*
void __print(Mint x) {
    cerr << x;
}
*/
template <typename A>
void __print(const A &x) {
    bool first = true;
    cerr << '{';
    for (const auto &i : x) {
        cerr << (first ? "" : ","), __print(i);
        first = false;
    }
    cerr << '}';
}
template <typename A, typename B>
void __print(const pair<A, B> &p) {
    cerr << '(';
    __print(p.first);
    cerr << ',';
    __print(p.second);
    cerr << ')';
}
template <typename... A>
void __print(const tuple<A...> &t) {
    bool first = true;
    cerr << '(';
    apply([&first](const auto & ...args) { ((cerr << (first ? "" : ","), __print(args), first = false), ...); }, t);
    cerr << ')';
}
template <typename T>
void __print(stack<T> s) {
    vector<T> debugVector;
    while (!s.empty()) {
        T t = s.top();
        debugVector.push_back(t);
        s.pop();
    }
    reverse(debugVector.begin(), debugVector.end());
    __print(debugVector);
}
template <typename T>
void __print(queue<T> q) {
    vector<T> debugVector;
    while (!q.empty()) {
        T t = q.front();
        debugVector.push_back(t);
        q.pop();
    }
    __print(debugVector);
}
template <typename T, typename... U>
void __print(priority_queue<T, U...> q) {
    vector<T> debugVector;
    while (!q.empty()) {
        T t = q.top();
        debugVector.push_back(t);
        q.pop();
    }
    __print(debugVector);
}
void _print() { cerr << "]\n"; }
template <typename Head, typename... Tail>
void _print(const Head &H, const Tail &...T) {
    __print(H);
    if (sizeof...(T))
        cerr << ", ";
    _print(T...);
}
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "Line:" << __LINE__ << " [" << #__VA_ARGS__ << "] = ["; _print(__VA_ARGS__)
#else
#define dbg(...)
#endif

int generateRandomNumber(int l, int r) {
    // Check if the range is valid
    if (l > r) {
        std::cerr << "Invalid range: l should be less than or equal to r" << std::endl;
        return -1; // Return an error value
    }

    // Create a random device and seed the generator
    std::random_device rd;
    std::mt19937 gen(rd()); // Initialize the random number generator with a random seed

    // Define the range
    std::uniform_int_distribution<> dis(l, r);

    // Generate and return the random number
    return dis(gen);
}



void gen(ll n, ll c, ll K) {
    vector<ll> g[c];
    for(ll i = 0; i < n; i++) {
        ll r = generateRandomNumber(0,c-1);
        g[r].push_back(i);
    }
    
    vector<char> text(n);
    
    for(ll i=0;i<c;i++){
        for(auto&x:g[i]){
            text[x] = 'a' + i;
        }
    }
    // dbg(text);

    ll lst = text[c-1] - 'a';
    ll fans=1e9;
    for(ll i = 1; i < (1ll<<c); i++) {
        vector<ll> tot;
        if ((i & (1ll<<lst)) == 0   ) continue;
        tot.push_back(-1);
        for(ll b = 0; b < c; b++) {
            if (i&(1ll<<b)) {
                for(auto&x:g[b]) {
                    tot.push_back(x);
                }
            }
        }

        sort(begin(tot), end(tot));

        bool ok = true;
        for(ll j = 1; j < (tot.size()); j++) {
            if (tot[j] - tot[j-1] <= K) {

            }else{
                ok=false;
            }
        }
        if (tot.back() != n - 1) {
            ok = false;
        }
        if (ok) {
            fans = min(fans, __builtin_popcount(i));
            
        }
    }
    dbg(text);
    cout << fans << "\n";
}

int main() {

    
    gen(100, 15, 3  );

    return 0;
}