#include<bits/stdc++.h>
using namespace std;

/*
Euler Tour
-> O(n)
-> 1 based indexing
-> Each vertex is added to 
    the array twice: when we descend 
    into it and when we leave it. 
    Each leaf (except maybe root) has 
    two consecutive entries
-> Multiple Ways of Euler Tour : https://codeforces.com/blog/entry/18369 (this is one of the way, explained above)
*/


using ll=long long;


// ============
vector<vector<ll>> adj;
ll timer;
vector<ll> tin, tout, depth;

void dfs(ll v, ll p) {
    tin[v] = ++timer;
    
    for (auto& ch : adj[v]) {
        if (ch != p) {
            depth[ch] = depth[v]+1;
            dfs(ch, v);
        }
    }

    tout[v] = ++timer;
}


int main(){
    ll n;
    cin>>n;
    adj = vector<vector<ll>> (n+1);
    tout = tin = vector<ll> (n+1, 0);
    timer = 0;
    for (ll i=1;i<n;i++) {
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v;
        adj[v].push_back(u);
    }
    dfs(1, 0);
    return 0;
}

/*
Sample Tree:
7
1 2
1 7
2 3
2 4
4 5
4 6

ET : 1 2 3 3 4 5 5 6 6 4 2 7 7 1
*/