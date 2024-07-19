//Har Har Mahadev
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define int long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define repin rep(i,0,n)
#define di(a) int a;cin>>a;
#define precise(i) cout<<fixed<<setprecision(i)
#define vi vector<int>
#define si set<int>
#define mii map<int,int>
#define take(a,n) for(int j=0;j<n;j++) cin>>a[j];
#define give(a,n) for(int j=0;j<n;j++) cout<<a[j]<<' ';
#define vpii vector<pair<int,int>>
#define sis string s;
#define sin string s;cin>>s;
#define db double
#define be(x) x.begin(),x.end()
#define pii pair<int,int>
#define pb push_back
#define pob pop_back
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define bpc(x) __builtin_popcountll(x) 
#define btz(x) __builtin_ctz(x)
using namespace std;

using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<pair<int, int>, null_type,less<pair<int, int> >, rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;

const long long INF=1e18;
const long long M=1e9+7;
const long long MM=998244353;
  
int power( int N, int M){
    int power = N, sum = 1;
    if(N == 0) sum = 0;
    while(M > 0){if((M & 1) == 1){sum *= power;}
    power = power * power;M = M >> 1;}
    return sum;
}

void sol(int n,int k)
{
    // int n,k;
    // cin >> n >> k;
    vi v;
    if(k > n){cout << "NO\n";return;}
    if(k == n){
        cout << "YES\n1\n1\n";return;
    }
    while(k!=0){
        if(n == 0)break;
        if(v.size() == 60)break;
        int l = 0,r = n;
        while(r > l+1){
            int m = (l+r)/2;
            if(n/m > k)l = m;
            else r = m;
        }
        v.pb(r);
        k -= n/r;
        n -= n/r*r;
    }   
    if(k){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    cout << v.size() << "\n";
    for(auto x : v){
        cout << x << " ";
    }cout << "\n";
}
 
void solve()
{
    int n,k;
    cin >> n >> k;
    vi v;
    if(k > n){cout << "NO\n";return;}
    if(k == n){
        cout << "YES\n1\n1\n";return;
    }
    while(k!=0){

        if(n <= 0)break;
        if(v.size() == 60)break;
        rep(i,1,1001){
            if(n/i+(n%i) == k && (60-v.size() >= 2)){
                v.pb(i);
                v.pb(1);
                k = 0;
                break;
            }
        }
        // if(60-v.size() >= k){
        //     rep(i,0,k){
        //         v.pb(1);
        //     }
        //     k = 0;break;
        // }
        
        int l = 0,r = n;
        if(n/r > k)break;
        while(r > l+1){
            int m = (l+r)/2;
            if(n/m > k)l = m;
            else r = m;
        }
        if(k <= 0)break;
        v.pb(r);
        k -= n/r;
        n = n%r;
        if(k > n){
            cout << "NO\n";return;
        }
    }   
    if(k){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    cout << v.size() << "\n";
    for(auto x : v){
        cout << x << " ";
    }cout << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef NCR
        init();
    #endif
    #ifdef SIEVE
        sieve();
    #endif
    di(t)
    while(t--)
        solve();
    // rep(i,1,130){
    //     cout << i << "\n";
    //     sol(873,i);
    // }
    return 0;
}
