#include <bits/stdc++.h>
using ll = int;
using namespace std;

int rand(int a, int b) {
  return a + rand()%(b-a+1);
}

int main(int argc, char* argv[]) {
  srand(atoi(argv[1]));
  
  


  ll n = rand(2, 50);
  ll m = rand(2, 50);

  vector<ll> a(n);
  vector<ll> b(m);

  for (ll i = 0; i < n; i++) {
    a[i] = rand(1, 100);
  }
  for (ll i = 0; i < m; i++) {
    b[i] = rand(1, 100);
  }
  sort(begin(b), end(b), greater<ll>());

  cout << n << " " << m << "\n";
  for (auto&x : a)
    cout << x << " ";
  cout << '\n';
  for (auto&x : b)
    cout << x << " ";
  cout << '\n';
}
