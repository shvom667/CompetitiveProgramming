#include<bits/stdc++.h>
using namespace std;
using ll=int;
#define pb push_back
template <typename T>
using Vec = vector<T>;

#ifndef ONLINE_JUDGE
    #include"/home/shivom/Downloads/CompetitiveProgramming/DataStructures/debug.cpp"
#else
    #define dbg(...) 42
#endif


auto bf(ll n, ll q, Vec<ll> a, Vec<pair<ll,ll>> Q) {
    vector<string> fans;
    auto check=[&](vector<ll> v) {
        assert(v.size() == 3);
        bool ok=true;
        if (v[0] >= v[1] + v[2]) {
            ok=false;
        }
        if (v[1] >= v[0] + v[2]) {
            ok=false;
        }
        if (v[2] >= v[0] + v[1]) {
            ok=false;
        }
        return ok;
    };
    auto valid=[&](vector<ll> &cur) {
        for (ll i = 0; i < cur.size(); i++) {
            for (ll j = i + 1; j < cur.size(); j++) {
                for (ll k = j + 1; k < cur.size(); k++) {
                    vector<ll> P,Q;
                    for (ll x=0;x<6;x++){
                        if(x==i || x==j || x==k) {
                            P.pb(cur[x]);
                        }else{
                            Q.pb(cur[x]);
                        }
                    }
                    if (check(P) && check(Q)) 
                        return true;
                }
            }
        }
        return false;
    };
    for (auto&[l,r]:Q) {
        bool ans=false;
        for (ll i=l-1;i<=r-1;i++) {
            for (ll j=i+1;j<=r-1;j++){
                for(ll k=j+1;k<=r-1;k++){
                    for(ll m=k+1;m<=r-1;m++){
                        for(ll o=m+1;o<=r-1;o++){
                            for(ll p=o+1;p<=r-1;p++){
                                vector<ll> cur;
                                cur.pb(a[i]);
                                cur.pb(a[j]);
                                cur.pb(a[k]);

                                cur.pb(a[m]);
                                cur.pb(a[o]);
                                cur.pb(a[p]);

                                if(valid(cur)) {
                                    ans=true;
                                }

                            }
                        }
                    }
                }
            }
        }
        if (ans) {
            fans.pb("Yes");
        } else {
            fans.pb("No");
        }
    }
    return fans;
}

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

    auto check(vector<ll> v) {
        assert(v.size() == 3);
        bool ok=true;
        if (v[0] >= v[1] + v[2]) {
            ok=false;
        }
        if (v[1] >= v[0] + v[2]) {
            ok=false;
        }
        if (v[2] >= v[0] + v[1]) {
            ok=false;
        }
        return ok;
    };
    auto valid(deque<ll> &cur) {
        bool ok=false;
        if (check({cur[1],cur[4],cur[5]}) && check({cur[0],cur[2],cur[3]}))ok=true;
        if (check({cur[1],cur[2],cur[5]}) && check({cur[0],cur[3],cur[4]}))ok=true;
        if (check({cur[1],cur[2],cur[3]}) && check({cur[0],cur[4],cur[5]}))ok=true;
        return ok;
    };

ordered_multiset<int> ss;

int fans=0;

void remove(int idx, vector<ll>&a) {
    ll n = (ll)a.size();

    deque<ll> lft,rht;
    ll pidx = (ll)ss.order_of_key(a[idx]);

    for (ll i = 1; i <= 5; i++) {
        if (pidx - i >= 0) {
            lft.push_front(*ss.find_by_order(pidx-i));
        }   
    }
    for (ll i = 1; i <= 5; i++) {
        if (pidx + i < (ll)ss.size()) {
            rht.push_back(*ss.find_by_order(pidx+i));
        }
    }
    deque<ll> d;
    for(auto&l:lft)d.push_back(l);

    for(auto&x:rht){
        d.pb(x);
        if(d.size()>6)d.pop_front();
        if(d.size()==6){
            if(valid(d)) {
                fans++;
            }
        }
    }
    d.clear();
    for(auto&l:lft)d.push_back(l);
    d.push_back(a[idx]);
    
    if(d.size()==6){
        if(valid(d))fans--;
    }
    for(auto&x:rht){
        d.pb(x);
        if(d.size()>6)d.pop_front();
        if(d.size()==6){

            if(valid(d)) {
                fans--;
            }
        }
    }


    ss.erase(ss.find_by_order(ss.order_of_key(a[idx])));
}

void add(int idx, vector<ll> &a) {
    ll n = a.size();
    ss.insert(a[idx]);
    deque<ll> lft,rht;   
    dbg("in_add",ss);
    ll pidx = (ll)ss.order_of_key(a[idx]);

    for (ll i = 1; i <= 5; i++) {
        if (pidx - i >= 0) {
            lft.push_front(*ss.find_by_order(pidx-i));
        }   
    }


    for (ll i = 1; i <= 5; i++) {
        if (pidx + i < (ll)ss.size()) { 
            rht.push_back(*ss.find_by_order(pidx+i));
        }
    }

    dbg(lft,rht);

    deque<ll> d;
    for(auto&l:lft)d.push_back(l);
    for(auto&x:rht){
        d.pb(x);
        if(d.size()>6)d.pop_front();
        if(d.size()==6){
            if(valid(d)) {
                fans--;
            }
        }
    }
    d.clear();
    for(auto&l:lft)d.push_back(l);
    d.push_back(a[idx]);
    dbg(d);
    if(d.size()==6){
        if(valid(d))fans++;
    }

    for(auto&x:rht){
        d.pb(x);
        if(d.size()>6)d.pop_front();
        if(d.size()==6){
            dbg("yes man");
            if(valid(d)) {
                fans++;
            }
        }
    }
    dbg(fans);
}
int get_answer() {
    return fans;
}
int block_size=600;

struct Query {
    int l, r, idx;
    bool operator<(Query other) const
    {
        return make_pair(l / block_size, r) <
               make_pair(other.l / block_size, other.r);
    }
};

vector<int> mo_s_algorithm(vector<Query> queries, vector<ll>& a) {
    vector<int> answers(queries.size());
    sort(queries.begin(), queries.end());

    // TODO: initialize data structure

    int cur_l = 0;
    int cur_r = -1;
    // invariant: data structure will always reflect the range [cur_l, cur_r]
    for (Query q : queries) {
        while (cur_l > q.l) {
            cur_l--;
            dbg("add1");
            add(cur_l,a);
        }
        while (cur_r < q.r) {
            cur_r++;
            dbg("add2");
            add(cur_r,a);
        }
        while (cur_l < q.l) {
            dbg("remove1");
            remove(cur_l,a);
            cur_l++;
        }
        while (cur_r > q.r) {
            dbg("remove2"); 
            remove(cur_r,a);
            cur_r--;
        }
        answers[q.idx] = get_answer();
        dbg("nigger",ss, fans);
    }
    return answers;
}

auto solve(ll n,ll q,Vec<ll> a,Vec<pair<ll,ll>> Q) {
    vector<string>res;
    for(auto&[x,y]:Q){x--;y--;}

    for (auto&[x,y]:Q) {
        dbg(x,y);
        if (y -x + 1 >= 49) {
            res.pb("Yes");
        }else {

            deque<ll> dq,z; 
            for (ll i = x; i <= y; i++) {
                z.pb(a[i]);
            }
            sort(begin(z),end(z));
            for (ll i = 0; i < 6; i++) {
                dq.pb(z[i]);
            }
            dbg(z);
            bool ok=false;
            if(valid(dq))ok=true;
            for (ll i =  6; i < (ll)z.size(); i++) {
                dq.pop_front();
                dq.push_back(z[i]);
                if(valid(dq))ok=true;
            }
            ll rht=-1;
            for (ll i = 2; i < z.size(); i++) {
                if(z[i]<z[i-1]+z[i-2]) rht=i;
            }
            rht-=2;
            ll lft=z.size()+1;
            for(ll i=z.size()-1;i>=2;i--){
                if(z[i]<z[i-1]+z[i-2]){
                    lft=i;
                }
            }
            dbg(lft,rht);
            if(ok||(lft<rht)){
                res.pb("Yes");
            }else{
                res.pb("No");
            }
        }

    }

    return res;
}




mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
int rnd(int x, int y) {
  return uniform_int_distribution<int>(x, y)(rng);
}
auto stress() {
    while (true) {
        ll n,q;
        n = rnd(6,6);
        q = rnd(1,1);
        vector<ll> a(n);
        vector<pair<ll,ll>>Q(q);
        for(ll i=0; i<n;i++){
            a[i] = rnd(1,20);
        }
        for(ll i = 0; i < q; i++) {
            Q[i].first=(1,n-1-6+1);
            Q[i].second=(Q[i].first+6-1,n);
        }
        auto bans=bf(n,q,a,Q);
        auto sans=solve(n,q,a,Q);
        if (bans==sans){

        }else{

            dbg(n,q);
            dbg(a);
            dbg(Q);
            dbg(bans);
            dbg(sans);
            exit(0);
        }

    }
}

int main() {
    // stress();
    ll T;
    T=1;
    for (ll tc = 1; tc <= T; tc++) {
        ll n,q;
        cin>>n>>q;
        vector<ll>a(n);
        for(ll i=0;i<n;i++)
            cin>>a[i];
        vector<pair<ll,ll>>Q(q);
        for(auto&[x,y]:Q)
            cin>>x>>y;
        auto res = solve(n,q,a,Q);
        for (auto&x:res){
            cout<<x<<"\n";
        }
    }
    return 0;
}

shivom@PC:~/Downloads/performant-api-java$ 



shivom@PC:~/Downloads/performant-api-java$ wrk -t1 -c100 -d30s http://localhost:8080/
Running 30s test @ http://localhost:8080/
  1 threads and 100 connections
  Thread Stats   Avg      Stdev     Max   +/- Stdev
    Latency     1.35ms    4.03ms 193.55ms   99.68%
    Req/Sec    84.70k     7.72k   89.31k    96.67%
  2526909 requests in 30.00s, 220.65MB read
Requests/sec:  84223.22
Transfer/sec:      7.35MB
shivom@PC:~/Downloads/performant-api-java$ 
