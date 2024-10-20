#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define R cin>>
#define ln cout<<'\n'
#define ll long long
#define in(a) insert(a)
#define pb(a) push_back(a)
#define pd(a) printf("%.10f\n",a)
#define mem(a) memset(a,0,sizeof(a))
#define all(c) (c).begin(),(c).end()
#define iter(c) __typeof((c).begin())
#define rrep(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define rep(i,n) REP(i,0,n)
#define tr(it,c) for(iter(c) it=(c).begin();it!=(c).end();it++)
ll check(ll n,ll m,ll x,ll y){return x>=0&&x<n&&y>=0&&y<m;}void pr(){ln;}
template<class A,class...B>void pr(const A &a,const B&...b){cout<<a<<(sizeof...(b)?" ":"");pr(b...);}
template<class A>void PR(A a,ll n){rep(i,n)cout<<(i?" ":"")<<a[i];ln;}
const ll MAX=998244353,MAXL=1LL<<61,dx[8]={-1,0,1,0,-1,-1,1,1},dy[8]={0,1,0,-1,-1,1,1,-1};
typedef pair<ll,ll> P;

void extended_euclid(ll x,ll y,ll *c,ll *a,ll *b){
  ll a0,a1,a2,b0,b1,b2,r0,r1,r2,q;r0=x;r1=y;a0=1;a1=0;b0=0;b1=1;
  while(r1>0){q=r0/r1;r2=r0%r1;a2=a0-q*a1;b2=b0-q*b1;r0=r1;r1=r2;a0=a1;a1=a2;b0=b1;b1=b2;}
  *c=r0;*a=a0;*b=b0;
}

ll get_inv(ll n, ll p){
  ll a,b,c;
  extended_euclid(n,p,&c,&a,&b);
  if(a<p) a+=p;
  return a%p;
}

ll fact[2000100],fact_inv[2000100];

void init() {
  fact[0]=1;
  REP(i,1,2000100) fact[i]=fact[i-1]*i%MAX;
  fact_inv[2000050]=get_inv(fact[2000050],MAX);
  rrep(i,2000050)fact_inv[i]=fact_inv[i+1]*(i+1)%MAX;
}

ll nCr(ll N,ll K){
  if(K<0||K>N)return 0;
  return fact[N]*fact_inv[K]%MAX*fact_inv[N-K]%MAX;
}

void Main() {
  init();
  ll T;
  R T;
  while(T--) {
    ll n;
    R n;
    ll a[n];
    rep(i,n) R a[i];
    ll m=0;
    rep(i,n) {
      if(!a[i]) m++;
    }
    ll x=0;
    rep(i,m) {
      if(a[i]) x++;
    }
    ll ans=0;
    rep(i,x) {
      ans+=nCr(n,2)*get_inv(nCr(x-i,1),MAX)%MAX*get_inv(nCr(x-i,1),MAX)%MAX;
      ans%=MAX;
    }
    pr(ans);
  }
}

int main(){ios::sync_with_stdio(0);cin.tie(0);Main();return 0;}
