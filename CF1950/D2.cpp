#include <bits/stdc++.h>
using namespace std;
#define newl "\n"
#define deb(x) cout << (#x) << ": " << x << endl;
// #define deb(x) ;
#define yes "YES"
#define no "NO"
int mod = 1000000007;

// =================

// Debugging template
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename A>
void __print(const A &x);
template <typename A, typename B>
void __print(const pair<A, B> &p);
template <typename... A>
void __print(const tuple<A...> &t);
template <typename T>
void __print(stack<T> s);
template <typename T>
void __print(queue<T> q);
template <typename T, typename... U>
void __print(priority_queue<T, U...> q);
/*
void __print(Mint x) {
	cerr << x;
}
*/
template <typename A>
void __print(const A &x) {
	bool first = true;
	cerr << '{';
	for (const auto &i : x) {
		cerr << (first ? "" : ","), __print(i);
		first = false;
	}
	cerr << '}';
}
template <typename A, typename B>
void __print(const pair<A, B> &p) {
	cerr << '(';
	__print(p.first);
	cerr << ',';
	__print(p.second);
	cerr << ')';
}
template <typename... A>
void __print(const tuple<A...> &t) {
	bool first = true;
	cerr << '(';
	apply([&first](const auto & ...args) { ((cerr << (first ? "" : ","), __print(args), first = false), ...); }, t);
	cerr << ')';
}
template <typename T>
void __print(stack<T> s) {
	vector<T> debugVector;
	while (!s.empty()) {
		T t = s.top();
		debugVector.push_back(t);
		s.pop();
	}
	reverse(debugVector.begin(), debugVector.end());
	__print(debugVector);
}
template <typename T>
void __print(queue<T> q) {
	vector<T> debugVector;
	while (!q.empty()) {
		T t = q.front();
		debugVector.push_back(t);
		q.pop();
	}
	__print(debugVector);
}
template <typename T, typename... U>
void __print(priority_queue<T, U...> q) {
	vector<T> debugVector;
	while (!q.empty()) {
		T t = q.top();
		debugVector.push_back(t);
		q.pop();
	}
	__print(debugVector);
}
void _print() { cerr << "]\n"; }
template <typename Head, typename... Tail>
void _print(const Head &H, const Tail &...T) {
	__print(H);
	if (sizeof...(T))
		cerr << ", ";
	_print(T...);
}
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "Line:" << __LINE__ << " [" << #__VA_ARGS__ << "] = ["; _print(__VA_ARGS__)
#else
#define dbg(...)
#endif

// =================
// why &c not works
void convertTime(int hour, int minute)
{
    if (hour >= 0 && hour < 24 && minute >= 0 && minute < 60)
    {
        string meridian = (hour < 12) ? "AM" : "PM";
        hour = (hour > 12) ? hour - 12 : hour;
        if (hour == 0)
            hour = 12;
        if (hour < 10)
            cout << "0";
        cout << hour << ":";
        if (minute < 10)
            cout << "0";
        cout << minute << " " << meridian << endl;
    }
    else
    {
        cout << "Invalid time entered!" << endl;
    }
}
void solve(int test_case, int total_cases)
{
    int n;
    cin >> n;
    for (int i = 64; i >= 2; i--)
    {
        bitset<7> temp(i);
        string s = temp.to_string();
        int dec = stoll(s);
        dbg(i, s, dec);
        while (n % dec == 0)
        {
            n /= dec;
        }
    }
    if (n == 1)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    cout << endl;
    // cout << n << endl;
}
signed main()
{

    int i = 0;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t{1};
    cin >> t;
    int total_cases = t;
    while (t--)
    {
        solve(t + 1, total_cases);
        // cout << newl;
    }
    return 0;
}
