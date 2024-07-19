#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;

void solve();
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll t; 
  t=1;
  while (t--) solve();
}

// ============

vector<int> MinPrime;
vector<int> PRIME;
void pre_calc_sieve(int N) {
	MinPrime = vector<int> (N + 1, 0);
	for (int i = 2; i <= N; ++i) {
		if (MinPrime[i] == 0) {
			MinPrime[i] = i;
			PRIME.push_back(i);
		}
		for (int j = 0; i * PRIME[j] <= N; ++j) {
			MinPrime[i * PRIME[j]] = PRIME[j];
			if (PRIME[j] == MinPrime[i]) {
				break;
			}
		}
	}
}

// ============
const ll INF64=1e18;
void solve() {
  const ll N=1568617+20;
  pre_calc_sieve(N);
  Vec<ll> dp(N, -INF64);
  Vec<ll> nd(N,-1);
  dp[0]=0;
  dp[1]=1;
  dp[2]=2;
  for(ll i=2;i<N;i++){
    ll res=1;
    ll j=i;
    while(j>1) {
      ll mp = MinPrime[j];
      ll cnt=0;
      while(j%mp==0){
        j/=mp;
        cnt++;
      }
      res *= (cnt+1);
    }
    nd[i]=res;
    if(res<=300){
      assert(i-res>=0);
      dp[i] = dp[i-res]+1;
    }
  }
  ll best=1568621;
  Vec<ll> fans;
  fans.pb(best);
  while(!fans.empty()&&fans.back()>0){
    fans.pb(fans.back()-nd[fans.back()]);
  }
  reverse(begin(fans),end(fans));
  ll max_v = -1;
  Vec<ll> res2;
  for(ll i=1;i<(ll)fans.size();i++) {
    max_v = max(max_v,fans[i]-fans[i-1]);
    res2.pb(fans[i]-fans[i-1]);
  }
  ll n;
  cin>>n;
  for (ll i = 0; i < n; i++)
    cout << res2[i] << " ";
  cout<<'\n';
}
