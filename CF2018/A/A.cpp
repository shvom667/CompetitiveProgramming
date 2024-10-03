#include <iostream>
#include <vector>

using namespace std;

const int N = 1e6;

vector<int> ch [N];
int depth [N];

void dfs (int u, int d) {
  depth[u] = d;
  for (int nxt : ch[u])
    dfs(nxt, 1 + d);
}

int main () {
  for (int i = 1; i < N; i++) {
    int p = i - 1 - rand() % 5;
    if (p < 0)
      p = 0;

    ch[p].push_back(i);
  }

  dfs(0, 0);
  cout << depth[N - 1] << '\n';
} 
