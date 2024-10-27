#include <bits/stdc++.h>
using ll = int;
using namespace std;

int rand(int a, int b)
{
  return a + rand() % (b - a + 1);
}

int main(int argc, char *argv[])
{
  srand(atoi(argv[1]));

  ll n = rand(2, 8);

  vector<ll> a(n);
  for (ll i = 0; i < n; i++)
  {
    a[i] = rand(1, 4);
  }

  cout << n << "\n";
  for (auto&u : a) {
    cout << u << " ";
  } cout << "\n";
}
