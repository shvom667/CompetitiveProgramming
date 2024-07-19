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
  cin >> t; 
  while (t--) solve();
}

void solve() {
  ll n;
  cin >> n;
  ll fans=0;
  if (n==1) {
    fans=0;
  }
  else if (n==2) {
    fans=1;
  }
  else if(n%2==0) {
    fans=2;
  }
  else if(n==3){
    fans = 2;
  }
  else {
    fans=3;
  }
  cout<<fans<<"\n";
}
