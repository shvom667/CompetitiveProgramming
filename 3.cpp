#include<bits/stdc++.h>
#define ll long long
using namespace std;

void dfs(int target,vector<int>&height,vector<vector<int>>&adj){
    visited[target]=1;
    for (auto i:adj[target]){
        if (visited[i]==0){
            dfs(i);
        }
        height[target]=max(height[i]+1,height[target]);
    }
}
int function1(int target,int network_nodes,vector<int>network_from,vector<int>network_to){
    int n=network_nodes;
    vector<vector<int>>adj(n+1);
    for (int i=0;i<network_from.size();i++){
        adj[network_from[i]].push_back(newtork_to[i]);
        adj[network_to[i]].push_back(network_from[i]);
    }
    vector<int>visited(n+1,0);
    vector<int>height(n+1,0);
    return height[target];
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tts=1;
    cin>>tts;
    while(tts--)
    {
        
    }
}
