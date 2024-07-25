#include <bits/stdc++.h>

using namespace std;

const vector<int> vid = vector<int> {-1};

void print(vector<int> c) {
    for(auto x:c){
        cout<<x<<" ";
    }   cout<<'\n';
}

vector<int> get_res(int s, int e, int g) {
    vector<int> a, b, final;
    a.push_back(s);
    b.push_back(e);
    while (s != e) {
        if (s > e) {
            a.push_back(s/2);
            s /= 2;
        } else {
            b.push_back(e/2);
            e /= 2;
        }
    }
    b.pop_back();
    reverse(begin(b), end(b));
    final = a;
    
    for (auto&x:b) {
        final.push_back(x);
    }
    
    if (g%2 != ((int)final.size())%2 || g + 2 < final.size()) {
        return vid;
    }

    final.clear();
    int d_cnt = 0;
    while (((int)a.size()) + ((int)b.size()) != g+2) {
        if (d_cnt%2==0){
            a.push_back(2*a.back());
        }else{
            a.push_back(a.back()/2);
        }
        d_cnt++;
    }
    final=a;
    for (auto&x:b) {
        final.push_back(x);
    }

    final.pop_back();
    reverse(begin(final), end(final));
    final.pop_back();
    reverse(begin(final), end(final));
    return final;
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    int fi=-1,li=-1;
    for(int i=0;i<n;i++){
        if(v[i]!=-1){
            li=i;
        }
        if(v[i]!=-1&&fi==-1){
            fi=i;
        }
    }
    for(int i=fi-1,c=0;i>=0;i--,c++){
        if (c%2==0){
            v[i]=v[i+1]*2;
        }else{
            v[i]=v[i+1]/2;
        }
    }
    for(int i=li+1,c=0;i<n;i++,c++){
        if (c%2==0){
            v[i]=v[i-1]*2;
        }else{
            v[i]=v[i-1]/2;
        }
    }
    if (fi == -1) {
        for(int i =0;i<n;i++){
            if(i&1){
                v[i]=2;
            }else{
                v[i]=1;
            }
        }
        print(v);
        return;
    }
    bool in=false;
    int pp = -1;
    int gc = 0;
    for(int i=0;i<n;i++){
        if (v[i]>0){
            if (in==true){
                vector<int> res = get_res(pp,v[i],gc);
                if (res==vid){
                    cout<<-1<<'\n';
                    return;
                }
                int j=i-1;
                while(!res.empty()){
                    v[j]=res.back();
                    j--;
                    res.pop_back();
                }
                in=false;
            }
            in=true;
            pp=v[i];
            gc=0;
        } else {
            gc++;
        }
    }

    print(v);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}