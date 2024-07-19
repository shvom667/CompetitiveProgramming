#include<bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int x,y,z;
  cin>>n>>x>>y>>z;
  if (z >= min(x,y) && z <= max(x,y))
    cout<<"Yes\n";
  else
    cout<<"No\n";
}
