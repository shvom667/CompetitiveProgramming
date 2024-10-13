#include <bits/stdc++.h>
using namespace std;
#define ll long long

set <ll> s;
ll n;
ll parent[100005];
ll p[100005];
ll pos[100005];
vector <ll> vv[100005];

void update(ll x){
    if(s.count(x)){
        s.erase(s.find(x));
    }
    for(auto it:vv[x]){
        if(s.count(it)){
            s.erase(s.find(it));
        }
    }
    return;
}

void update2(ll x){
    if(p[pos[x]]!=parent[p[x]]){
        s.insert(x);
    }
    for(auto it:vv[x]){
        if(p[x]!=parent[p[it]]){
            s.insert(it);
        }
    }
    return;
}

ll tt;
void dfs(ll pp,ll x){
    if(pp>n){
        return;
    }
    tt++;
    pos[tt]=x;
    vv[x].push_back(tt);
    ll lol=tt;
    dfs(pp*2,lol);
    dfs(pp*2+1,lol);
    return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    ll kitne_cases_hain;
    kitne_cases_hain=1;
    cin>>kitne_cases_hain;
    while(kitne_cases_hain--){          
        ll q;
        cin>>n>>q;
        s.clear();
        for(int i=1;i<=n;i++){
            vv[i].clear();
        }
        for(int i=2;i<=n;i++){
            cin>>parent[i];
        }
        tt=0;
        dfs(1,0);
        for(int i=1;i<=n;i++){
            cin>>p[i];
            if(p[pos[i]]!=parent[p[i]]){
                s.insert(i);
            }
        }
        ll x,y;
        while(q--){
            cin>>x>>y;
            swap(p[x],p[y]);
            update(x);update(y);
            update2(x);update2(y);
            if(s.size()){
                cout<<"NO\n";
            }else{
                cout<<"YES\n";
            }
        }
    }
	return 0;
}
