#include <bits/stdc++.h>
using ll = int;
using namespace std;

int rand(int a, int b) {
  return a + rand()%(b-a+1);
}

int main(int argc, char* argv[]) {
  srand(atoi(argv[1]));
  
  


  ll n = rand(7, 7);
  ll k = rand(2, 5);

  vector<ll> a(n);

  for (ll i = 0; i < n; i++) {
    a[i] = rand(0, k-1);
  }
  cout << n << " " << k << "\n";
  for (auto&x : a)
    cout << x << " ";
  cout << '\n';
}
