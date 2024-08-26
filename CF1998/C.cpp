#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define i32 int
#define pb push_back
#define ALL(x) begin(x), end(x)
#define SZ(x) (ll)(x.size())
#define OVERRIDE(a, b, c, d, ...) d
#define REP2(i, n) for (i32 i = 0; i < (i32)(n); ++i)
#define REP3(i, m, n) for (i32 i = (i32)(m); i < (i32)(n); ++i)
#define REP(...) OVERRIDE(__VA_ARGS__, REP3, REP2)(__VA_ARGS__)
#define PER(i, n) for (i32 i = (i32)(n) - 1; i >= 0; --i)

template <typename T>
using Vec = vector<T>;
template<typename T>
vector<T> PrefixSum(vector<T> X) {
    ll n = X.size();
    vector<T> ret(n, 0);
    REP (i, n) {
        ret[i] = X[i];
        if (i > 0) ret[i] += ret[i - 1];
    }
    return ret;
}
template<typename T>
void chmax(T& a, T b) {
    a = max(a, b);
}
template<typename T>
void chmin(T& a, T b) {
    a = min(a, b);
}
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

ll get_ans(Vec<ll> x) {
    sort(ALL(x));
    ll n = x.size();
    if(n==1){
        return x[0];
    }
    if(n&1){
        return x[n/2-1]+x[n-1];
    }else{
        return x[n/2-1]+x[n-1];
    }
    return 0ll;
}
ll test(Vec<ll> v, ll k){
    ll fans=0;
    for(ll i=k;i>=0;i--){
        for(ll j = 0; j + i <= k ; j++) {
            
            auto vd = v;
            vd[1] += i;
            vd[0] += j;
            vd[2] += k-i-j;
            fans=max(fans,get_ans(vd));
        }
    }
    
    return fans;
}
ll solve(ll n, ll k, Vec<ll>v, Vec<ll> b) {

    Vec<ll> I(n);
    for(ll i=0;i<n;i++){
        I[i]=i;
    }
    sort(ALL(I), [&](auto x, auto y) {
        if (v[x] < v[y]) return true;
        if (v[x] > v[y]) return false;
        if (v[x] == v[y]) {
            return b[x] < b[y];
        }
        return false;
    });
    // dbg(v);
    Vec<ll> vd=v;
    Vec<ll> bd=b;
    for(ll i=0;i<n;i++){
        vd[i]=v[I[i]];
        bd[i]=b[I[i]];
    }
    swap(vd,v);
    swap(bd,b);
    // dbg(v);
    // dbg(b);
    ll fans = 0;
    fans = get_ans(v);
    // dbg(fans);
    // dbg(v);
    if (true) {
        Vec<ll> vd=v;
        for(ll i = n - 1; i >= 0; i--) {
            if (b[i] == 1) {
                vd[i] += k;
                // dbg(vd);
                fans = max(fans, get_ans(vd));
                break;
            }
        }
    }
    // dbg(fans);   
    if (true) {
        Vec<ll> vd = v;
        ll cur = vd.back();
        vd.pop_back();
        ll sz = vd.size();
        Vec<ll> bd=b;
        b.pop_back();
        if(sz>0){
            ll l = 0, r = 1e12;
            auto cond = [&](ll mid) {
                Vec<bool> ok(sz,false);
                ll cnt = 0;
                Vec<ll> un;
                for(ll i=0;i<sz;i++){
                    if(b[i]==0){
                        ok[i]=true;
                        if(vd[i]>=mid){
                            cnt++;;
                        }
                    }
                    else{
                        un.pb(vd[i]);
                    }
                }
                sort(ALL(un));
                while(!un.empty() && un.back()>=mid){
                    un.pop_back();
                    cnt++;
                }
                ll left=k;
                // dbg(un, left);
                while(!un.empty()){
                    if(un.back()+left>=mid){
                        left -= mid-un.back();
                        un.pop_back();
                        cnt++;
                    }else{
                        break; 
                    }
                }
                // dbg(cnt);
                return (cnt >= ((sz+2)/2));
            };
            // dbg(cond(4));
            // dbg(vd);
            // dbg(bd);
            while(l<=r){
                ll mid=l+(r-l)/2;
                if (cond(mid)){
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }
            // dbg(r);
            // dbg(cur);
            fans=max(fans,cur+r);
        }
    }
    return fans;
}

ll solve_dbg(ll n, ll k, Vec<ll>v, Vec<ll> b) {

    Vec<ll> I(n);
    for(ll i=0;i<n;i++){
        I[i]=i;
    }
    sort(ALL(I), [&](auto x, auto y) {
        if (v[x] < v[y]) return true;
        if (v[x] > v[y]) return false;
        if (v[x] == v[y]) {
            return b[x] < b[y];
        }
        return false;
    });
    // dbg(v);
    Vec<ll> vd=v;
    Vec<ll> bd=b;
    for(ll i=0;i<n;i++){
        vd[i]=v[I[i]];
        bd[i]=b[I[i]];
    }
    swap(vd,v);
    swap(bd,b);
    // dbg(v);
    // dbg(b);
    ll fans = 0;
    fans = get_ans(v);
    dbg(fans);
    dbg(v);
    if (true) {
        Vec<ll> vd=v;
        for(ll i = n - 1; i >= 0; i--) {
            if (b[i] == 1) {
                vd[i] += k;
                // dbg(vd);
                fans = max(fans, get_ans(vd));
                break;
            }
        }
    }
    dbg(fans);   
    if (true) {
        Vec<ll> vd = v;
        ll cur = vd.back();
        vd.pop_back();
        ll sz = vd.size();
        Vec<ll> bd=b;
        b.pop_back();
        if(sz>0){
            ll l = 0, r = 1e18;
            auto cond = [&](ll mid) {
                Vec<bool> ok(sz,false);
                ll cnt = 0;
                Vec<ll> un;
                for(ll i=0;i<sz;i++){
                    if(b[i]==0){
                        ok[i]=true;
                        if(vd[i]>=mid){
                            cnt++;;
                        }
                    }
                    else{
                        un.pb(vd[i]);
                    }
                }
                sort(ALL(un));
                dbg(un);    
                while(!un.empty() && un.back()>=mid){
                    un.pop_back();
                    cnt++;
                }
                ll left=k;
                dbg(un, left, cnt);
                while(!un.empty()){
                    dbg(mid);
                    if(un.back()+left>=mid){
                        left -= mid-un.back();
                        un.pop_back();
                        cnt++;
                    }else{
                        break; 
                    }
                }
                dbg(cnt);
                return (cnt >= ((sz+2)/2));
            };
            dbg(cond(1));
            dbg(vd);
            dbg(bd);
            while(l<=r){
                ll mid=l+(r-l)/2;
                if (cond(mid)){
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }
            dbg(r);
            dbg(cur);
            fans=max(fans,cur+r);
        }
    }
    return fans;
}

int main() {
    // ll t;
    // t = 1;
    // // cin >> t;
    // for (ll k = 1; k <= 20; k++) { 
    //     for(ll i=0;i<=20;i++)
    //     for(ll j=0;j<=20;j++)
    //     for(ll l=0;l<=20;l++)
    //     for(ll m=0;m<=20;m++)
    //     for(ll k=0;k<=20;k++)  {
    //     ll n=5;
    //     Vec<ll> v(n),b(n);
    //     v={i,j,k,l,m};
    //     b={1,1,1,0,0};
    //     // for(ll i=0;i<n;i++){
    //     //     cin>>v[i];
    //     // }
        
    //     // for(ll i=0;i<n;i++){
    //     //     cin>>b[i];
    //     // }
    //     dbg("y");
    //     dbg(v,k,test(v,k),solve(n,k,v,b));
    //     assert (test(v,k) == solve(n,k,v,b));
    //     }
    // }
    ll t;
    t = 1;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        Vec<ll> v(n),b(n);
        for(ll i=0;i<n;i++){
            cin>>v[i];
        }
        
        for(ll i=0;i<n;i++){
            cin>>b[i];
        }
        // dbg(v,k,test(v,k),solve(n,k,v,b));
        // assert (test(v,k) == solve(n,k,v,b));
        
        cout << solve_dbg(n,k,v,b) << "\n";
    }
}
