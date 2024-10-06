//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
//~ #pragma GCC target ("avx2")
//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

#define shandom_ruffle random_shuffle

using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
const int nax=107;
const ll mod=998244353;
const int alfa=26;

int n, k;

char wcz[nax];

vi wek[nax];

ll wyn;

int tso[nax][nax];

int naj;

void rek(int v, int parz)
{
	if (v==n)
	{
		if (!parz)
			return;
		ll y=0;
		ll x=1;
		for (int i=0; i<naj; i++)
		{
			if (tso[n][i]==alfa)
			{
				x=0;
			}
			else
			{
				if (tso[n][i]==-1)
					x=x*26%mod;
			}
			y+=x;
		}
		y%=mod;
		if (parz&1)
			wyn=(wyn+y)%mod;
		else
			wyn=(wyn+mod-y)%mod;
		return;
	}
	for (int i=0; i<naj; i++)
		tso[v+1][i]=tso[v][i];
	rek(v+1, parz);
	for (int i=0; i<naj; i++)
	{
		if ((int)wek[v].size()<=i)
		{
			tso[v+1][i]=alfa;
		}
		else
		{
			if (tso[v+1][i]>=0 && wek[v][i]>=0 && tso[v+1][i]!=wek[v][i])
			{
				tso[v+1][i]=alfa;
			}
			else
			{
				tso[v+1][i]=max(tso[v+1][i], wek[v][i]);
			}
		}
	}
	rek(v+1, parz+1);
}

void test(int czyrobic)
{
	wyn=1;
	scanf("%d", &n);
	naj=0;
	for (int i=0; i<n; i++)
	{
		wek[i].clear();
		scanf("%s", wcz+1);
		int r=strlen(wcz+1);
		naj=max(naj, r);
		for (int j=1; j<=r; j++)
		{
			if (wcz[j]=='?')
				wek[i].push_back(-1);
			else
				wek[i].push_back(wcz[j]-'A');
		}
	}
	if (!czyrobic)
		return;
	for (int i=0; i<naj; i++)
		tso[0][i]=-1;
	rek(0, 0);
	wyn%=mod;
	wyn+=mod;
	wyn%=mod;
	printf("%lld\n", wyn);
}

int main(int argc, char *argv[])
{
	int dol=atoi(argv[1]);
	int gor=atoi(argv[2]);
	int t;
	scanf("%d", &t);
	for (int i=1; i<=t; i++)
	{
		if (dol<=i && i<=gor)
			printf("Case #%d: ", i);
		test(dol<=i && i<=gor);
		fflush(stdout);
	}
	return 0;
}
