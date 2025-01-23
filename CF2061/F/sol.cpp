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

auto solve() {
	string a, b;
	cin >> a >> b;
	int n = (int) a.size();

	if (count(begin(a), end(a), '1') != count(begin(b), end(b), '1')) {
		cout << -1 << '\n';
		return;
	}
	if (a == b) {
		cout << 0 << '\n';
		return;
	}

	deque<int> fa, fb;

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (i > 0 && a[i] != a[i - 1]) {
			fa.pb(cnt);
			cnt = 1;
			continue;
		}
		cnt++;
	}
	fa.pb(cnt);
	cnt = 0;
	for (int i = 0; i < n; i++) {
		if (i > 0 && b[i] != b[i - 1]) {
			fb.pb(cnt);
			cnt = 1;
			continue;
		}
		cnt++;
	}
	fb.pb(cnt);

	int op = 0;

	auto do_op = [&] () {
		op++;
		int f1 = fa.front();
		fa.pop_front();
		int f2 = fa.front();
		fa.pop_front();
		int f3 = fa.front();
		fa.pop_front();

		if (fa.empty())  {
			fa.push_front(f2);
			fa.push_front(f1 + f3);
		} else {
			int f4 = fa.front();
			fa.pop_front();
			fa.push_front(f2 + f4);
			fa.push_front(f1 + f3);
		}
	};
	
	if (a[0] != b[0]) {
		op++;
		int f1 = fa.front();
		fa.pop_front();
		int f2 = fa.front();
		fa.pop_front();

		if (fa.empty())  {
			fa.push_front(f1);
			fa.push_front(f2);
		} else {
			int f3 = fa.front();
			fa.pop_front();
			fa.push_front(f1 + f3);
			fa.push_front(f2);
		}
	}
	dbg(op);
	dbg(fa);
	dbg(fb);

	while (!fb.empty()) {
		dbg(fa);
		dbg(fb);
		if (fa.front() > fb.front()) {
			cout << -1 << '\n';
			return;
		}
		else if (fa.front() == fb.front()) {
			fa.pop_front();
			fb.pop_front();
		}
		else {
			do_op();
		}
	}
	cout << op << '\n';

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
	    solve();
    }
    return 0;
}
