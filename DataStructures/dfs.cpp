// ===============

vector<bool> seen(N+1, false);
function<void(ll)> dfs = [&] (ll i) {
  seen[i] = true;
  for (auto& ch : adj[i]) {
    if (!seen[ch]) {
      dfs (ch);
    }
  }
};

// ===============
