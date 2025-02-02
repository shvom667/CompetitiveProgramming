#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;

#ifndef ONLINE_JUDGE
#include "/home/shivom/Downloads/CP/DataStructures/debug.cpp"
#include "/home/shivom/Downloads/CP/DataStructures/random_gen.cpp"
#else
#define dbg(...) 42
#define rnd(...) 42
#endif
const ll INF=1e9+10;
auto solve() {
	ll n;
	cin>>n;
	vector<ll> L(n),R(n),C(n);
	vector<pair<pair<ll,ll>, ll>>byc[n];
	for(ll i=0;i<n;i++){
		cin>>L[i]>>R[i]>>C[i];
		C[i]--;
		byc[C[i]].pb({{L[i],R[i]},i});
	}
	vector<ll>ans(n,INF);

	auto upd = [&](ll i, ll v){
		ans[i]=min(ans[i],v);
	};

	if (true) {
		vector<ll>I(n,0);for(ll i=0;i<n;i++)I[i]=i;
		sort(begin(I),end(I),[&](ll x, ll y){
			if(R[x]>R[y]){
				return true;
			}
			if(R[x]<R[y]){
				return false;
			}
			return L[x]>L[y];
		});
		multiset<ll>st;
		set<ll>col[n];
		for(ll j=0;j<n;j++){
			ll i = I[j];
			dbg(i);
			ll rval = L[i];
			ll best = i;
			while(!col[C[i]].empty()){
				auto it = *col[C[i]].begin();
				if (L[it]<rval){
					rval=L[it];
					best=it;
				}
				st.erase(st.find(L[it]));
				col[C[i]].erase(it);
			}

			if(!st.empty()){
				auto it = *st.begin();
				if(it<=R[i]){
					upd(i,0ll);
				}else{
					upd(i,it-R[i]);
				}
			}

			st.insert(L[best]);
			col[C[i]].insert(best);
		}	
	}


	if (true) {
		vector<ll>I(n,0);for(ll i=0;i<n;i++)I[i]=i;
		sort(begin(I),end(I),[&](ll x, ll y){
			if(L[x]<L[y])return true;
			if(L[x]>L[y])return false;
			return R[x]<R[y];
		});
		multiset<ll>en;
		set<ll>col[n];
		for(ll j=0;j<n;j++){
			ll i = I[j];
			ll rval = R[i];
			ll been = i;
			while(!col[C[i]].empty()){
				auto it = *col[C[i]].begin();
				if (R[it]>rval){
					rval=R[it];
					been=it;
				}
				en.erase(en.find(R[it]));
				col[C[i]].erase(it);
			}

			if(!en.empty()){
				auto it = *en.rbegin();
				if(it>=L[i]){
					upd(i,0ll);
				}else{
					upd(i,-it+L[i]);
				}
			}

			en.insert(R[been]);
			col[C[i]].insert(been);
		}	
	}


	dbg(ans);

	multiset<ll>aep;
	for(ll c=0;c<n;c++){
		for(auto[x,y]:byc[c]){
			aep.insert(x.first);
			aep.insert(x.second);
		}
	}

	for(ll c=0;c<n;c++){
		for(auto[x,y]:byc[c]){
			aep.erase(aep.find(x.first));
			aep.erase(aep.find(x.second));
		}
		for(auto [x,y]:byc[c]) {
			auto it=aep.lower_bound(x.first);
			if (it != end(aep) && *it <= x.second) {
				if(*it<=x.second){
					upd(y,0);
				}
			}
		}	


		for(auto[x,y]:byc[c]){
			aep.insert(x.first);
			aep.insert(x.second);
		}
	}
	

	for(auto x:ans){
		cout<<x<<" ";
	}cout<<'\n';
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll T;
	cin >> T;
	for (ll tc = 1; tc <= T; tc++) {
		auto res = solve();
		// cout << res << "\n";
	}
	return 0;
}

/*
1
3
1 2 1
3 4 1
5 6 2


*/