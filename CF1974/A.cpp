
/*
  And all I am is a man
  I want the world in my hands
  I hate the beach
  But I stand in California with my toes in the sand
  Use the sleeves of my sweater
  Let's have an adventure
  Head in the clouds but my gravity centered
  Touch my neck and I'll touch yours
  You in those little high waisted shorts, oh
*/

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
  ll x, y;
  cin >> x >> y;
  ll tf = 0;
  tf += (y+1)/2;
  ll left = 15*tf - 4 * y;
  ll add=0;
  if (x-left>0) {
    add = (x-left+14)/15;
  }
  cout<<tf+add<<'\n';
}
