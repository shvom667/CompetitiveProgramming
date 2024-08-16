#include<bits/stdc++.h>

using namespace std;

using ll =int;
int main() {
  ll n = 10;
  cin >> n;
  cout << n << "\n";

  for (ll k = 1; k <= n; k++) {
    cout << n << " " << k << "\n";
    for (ll v = 1; v<=n; v++) {
      cout << 1 << " ";
    }
    cout<<"\n\n";
  }

}
