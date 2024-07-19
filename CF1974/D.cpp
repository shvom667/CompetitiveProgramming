#define ONLINE_JUDGE

/*
  And all I am is a man
  I want the world in my hands
  I hate the beach
  But I stand in California with my toes in the sand
  Use the sleeves of my sweater
  Let's have an adventure
  Head in the clouds but my gravity centered
  Touch my neck and I'll touch yours
  You in those little high waisted shorts, oh
*/

#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
template <typename T>
using Vec = vector<T>;

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
void solve();
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll t; 
  cin >> t; 
  while (t--) solve();
}
bool check(string res, string s) {
  ll n = (int)s.size();
  ll xr,yr,xh,yh;
  xr=yr=xh=yh=0;
  for(ll i =0;i<n;i++){
    if (res[i]=='H') {
      if (s[i] == 'N') yh++;
      if (s[i] == 'S') yh--;
      if (s[i] == 'W') xh--;
      if (s[i] == 'E') xh++;

    }
    if (res[i] == 'R') {
      if (s[i] == 'N') yr++;
      if (s[i] == 'S') yr--;
      if (s[i] == 'W') xr--;
      if (s[i] == 'E') xr++;
    }
  }
  dbg(xr,yr,xh,yh);
  if(xr==xh && yr==yh)return true;
  return false;
}
void solve() {
  ll n;
  string s;
  cin >> n >> s;
  ll x, y;
  x=y=0;
  ll cn,cs,cw,ce;
  cn=cs=cw=ce=0;
  for(ll i = 0; i < n; i++) {
    if (s[i] == 'N') {y++;cn++;}
    if (s[i] == 'S') {y--;cs++;}
    if (s[i] == 'W') {x--;cw++;}
    if (s[i] == 'E') {x++;ce++;}
  }
  if (abs(y)%2==1 || abs(x)%2==1) {
    cout << "NO\n";
    return;
  }
  if (max(ce,cw)==0 && cn==1&&cs==1){
    cout<<"NO\n";
    return;
  }
  if(max(cn,cs)==0&&ce==1&&cw==1){
    cout<<"NO\n";
    return;
  }
  string res = s;
  Vec<bool> seen(n,false);
  dbg(cn,cs,cw,ce);
  if (cn>cs) {
    ll c1,c2;
    c1=c2=cs;
    ll d=abs(cn-cs)/2;
    ll d1,d2;
    d1=d2=d;
    dbg(d1,d2);
    for(ll i=0;i<n;i++){
      if (s[i] == 'N' && !seen[i] && d1) {
        seen[i]=true;
        res[i]='R';
        d1--;
      }
    }
    for(ll i=0;i<n;i++){
      if (s[i] == 'N' && !seen[i] && d2) {
        seen[i]=true;
        res[i]='H';
        d2--;
      }
    }
    for (ll i = 0; i < n; i++) {
      if ((s[i] == 'N' || s[i] == 'S') && !seen[i]) {
        seen[i]=true;
        res[i]='R';
      }
    }
    dbg("hi", res);
  }
  else{
    //cs>=cn
    ll c1,c2;
    c1=c2=cs;
    ll d=abs(cn-cs)/2;
    ll d1,d2;
    d1=d2=d;
    for(ll i=0;i<n;i++){
      if (s[i] == 'S' && !seen[i] && d1) {
        seen[i]=true;
        res[i]='R';
        d1--;
      }
    }
    for(ll i=0;i<n;i++){
      if (s[i] == 'S' && !seen[i] && d2) {
        seen[i]=true;
        res[i]='H';
        d2--;
      }
    }
    for (ll i = 0; i < n; i++) {
      if ((s[i] == 'N' || s[i] == 'S') && !seen[i]) {
        seen[i]=true;
        res[i]='R';
      }
    }
  }
  dbg(res);
  if (ce>cw) {
    ll c1,c2;
    c1=c2=cs;
    ll d=abs(ce-cw)/2;
    ll d1,d2;
    d1=d2=d;
    for(ll i=0;i<n;i++){
      if (s[i] == 'E' && !seen[i] && d1) {
        seen[i]=true;
        res[i]='R';
        d1--;
      }
    }
    for(ll i=0;i<n;i++){
      if (s[i] == 'E' && !seen[i] && d2) {
        seen[i]=true;
        res[i]='H';
        d2--;
      }
    }
    for (ll i = 0; i < n; i++) {
      if ((s[i] == 'W' || s[i] == 'E') && !seen[i]) {
        seen[i]=true;
        res[i]='H';
      }
    }
  }
  
  else{
    ll c1,c2;
    c1=c2=cs;
    ll d=abs(ce-cw)/2;
    ll d1,d2;
    d1=d2=d;
    for(ll i=0;i<n;i++){
      if (s[i] == 'W' && !seen[i] && d1) {
        seen[i]=true;
        res[i]='R';
        d1--;
      }
    }
    for(ll i=0;i<n;i++){
      if (s[i] == 'W' && !seen[i] && d2) {
        seen[i]=true;
        res[i]='H';
        d2--;
      }
    }
    for (ll i = 0; i < n; i++) {
      if ((s[i] == 'W' || s[i] == 'E') && !seen[i]) {
        seen[i]=true;
        res[i]='H';
      }
    }
  }
  if (ce==0 && cw == 0 && cn == cs) {
    Vec<ll> ni, si;
    for (ll i = 0; i < n; i++) {
      if (s[i] == 'N')
        ni.pb(i);
      if (s[i] == 'S')
        si.pb(i);
    }
    for (ll j = 0; j <(int) ni.size(); j++) {
      if (j&1){
        res[ni[j]]='R';
        res[si[j]]='R';
      }else{
        res[ni[j]]='H';
        res[si[j]]='H';
      }
    }
  }
  if (cs==0 && cn == 0 && ce == cw) {
    Vec<ll> ei, wi;
    for (ll i = 0; i < n; i++) {
      if (s[i] == 'E')
        ei.pb(i);
      if (s[i] == 'W')
        wi.pb(i);
    }
    for (ll j = 0; j < (int)ei.size(); j++) {
      if (j&1){
        res[ei[j]]='R';
        res[wi[j]]='R';
      }else{
        res[ei[j]]='H';
        res[wi[j]]='H';
      }
    }
  }
  cout << res << '\n';
}
