#include<bits/stdc++.h>
using namespace std;
void solve(){
	int a[6];
	for(int i = 0;i < 6;i++) cin >> a[i];
	sort(a, a+6);
	int n;cin >> n;
	int b[n][6];
	vector<int> v;
	set<pair<int, pair<int, int>>> s;
	for(int i = 0;i < n;i++){
		int x;cin >> x;
		for(int j = 0;j < 6;j++) {
			v.push_back(x-a[j]);
			b[i][j] = x-a[5-j];
		}
		s.insert({b[i][0], {i, 0}});
	}
	sort(v.begin(), v.end());
	int ans = INT_MAX;
	for(int x : v){
		while(s.begin()->first < x){
			auto p = *s.begin();
			if(p.second.second == 5) {
				cout << ans << '\n';
				return;
			}
			p.second.second++;
			s.erase(s.begin());
			p.first = b[p.second.first][p.second.second];
			s.insert(p);
		}
		ans = min(ans, s.rbegin()->first-x);
	}
	cout << ans << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
