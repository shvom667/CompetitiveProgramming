#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve();
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll tes;cin>>tes;
    while(tes--)
        solve();
}

const ll N = 200005;
ll n,k;
ll a[N], b[N];
vector<ll> g1[N], g2[N];
ll vis1[N], vis2[N];

void dfs1(ll u, ll c)
{
    if(vis1[u]!=-1)
        return;
    vis1[u]=c;
    for(ll v:g1[u])
    {
        dfs1(v,(c+1)%k);
    }
}

void dfs2(ll u, ll c)
{
    if(vis2[u]!=-1)
        return;
    vis2[u]=c;
    for(ll v:g2[u])
    {
        dfs2(v,(c+1)%k);
    }
}

ll freq[N][2][2];

vector<ll> computePrefix(vector<ll> v) {

	ll m = ll(v.size());
	vector<ll> prefix(m);
	for(ll i=1,k=0;i<m;++i)
	{
		if(k>0&&v[i]!=v[k])
			k=prefix[k-1];
		if(v[k]==v[i])
			prefix[i]=++k;
		else
			prefix[i]=k;
	}
	return prefix;
}

bool KMP(vector<ll> v, vector<ll> pat) {
	ll m = ll(v.size());
    ll n = ll(pat.size());
	vector<ll> longestPrefix = computePrefix(pat);

	for (ll i = 0, k = 0; i < m; ++i) {
		if (k > 0 && pat[k] != v[i])
			k = longestPrefix[k - 1];
		if (v[i] == pat[k])
			++k;
		if (k == n) {
            return true;
		}
	}
    return false;
}

void solve()
{
    cin>>n>>k;
    for(ll i=0;i<=n;i++)
    {
        g1[i].clear(); g2[i].clear();
        freq[i][0][0]=freq[i][0][1]=freq[i][1][0]=freq[i][1][1]=0;
    }
    ll s1 = 0,s2 = 0;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
        s1 += a[i];
    }
    ll m1;cin>>m1;
    for(ll i=0;i<m1;i++)
    {
        ll u,v;cin>>u>>v;
        g1[u].push_back(v);
    }
    for(ll i=1;i<=n;i++)
    {
        cin>>b[i];
        s2 += b[i];
    }
    ll m2;cin>>m2;
    for(ll i=0;i<m2;i++)
    {
        ll u,v;cin>>u>>v;
        g2[u].push_back(v);
    }

    if(s1 + s2!=n)
    {
        cout<<"NO\n";
        return;
    }
    if(s1==0 || s2==0)
    {
        cout<<"YES\n";
        return;
    }
    for(ll i=1; i<=n; i++)
        vis1[i]=vis2[i]=-1;
    dfs1(1,0);dfs2(1,0);

    for(ll i=1;i<=n;i++)
    {
        // cout<<vis1[i]<<" "<<a[i]<<"\n";
        // cout<<vis2[i]<<" "<<b[i]<<" hello\n";
        // cout<<"\n";
        freq[vis1[i]][0][a[i]]++;
        freq[vis2[i]][1][b[i]]++;
    }

    vector<ll> v1(k), v2(2*k);
    for(ll i=0;i<k;i++)
    {
        v1[i] = freq[i][0][1]*(n+1) + freq[(i + 1) % k][0][0];
        v2[i] = freq[(i+1)%k][1][0]*(n+1) + freq[i][1][1];

        v2[i+k]=v2[i];
    }
    
    // for(int i=0;i<k;i++)    cout<<v1[i]<<" ";cout<<"\n";
    // for(int i=0;i<2*k;i++)    cout<<v2[i]<<" ";cout<<"\n";
    
    if(KMP(v2, v1))
    {
        cout<<"YES\n";
    }
    else
    {
        cout<<"NO\n";
    }

}
