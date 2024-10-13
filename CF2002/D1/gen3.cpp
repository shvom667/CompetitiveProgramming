#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define endl "\n"
using namespace __gnu_pbds;
//#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
//order_of_key (k) : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).
typedef long long int ll;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
    auto start=chrono::high_resolution_clock::now();
    default_random_engine generator;
    //uniform_int_distribution<int> distribution(l,r); 
    //int nn=distribution(generator); A random number from l to r
    //code here
    int t=1;
    // cin>>t;
    cout<<t<<endl;
    while(t--)
    {
        int n = 65535, q = 50000;
        cout<<n<<" "<<q<<endl;
        vector<vector<int>> graph(n+1);
        for(int i=2;i<=n;i++){
            cout<<i/2;
            if(i!=n)
                cout<<" ";
            graph[i].push_back(i/2);
            graph[i/2].push_back(i);
        }
        cout<<endl;
        vector<int> p;
        stack<int> s;
        s.push(1);
        while(!s.empty()){
            int u=s.top();
            s.pop();
            p.push_back(u);
            for(int v:graph[u]){
                if(v!=u/2){
                    s.push(v);
                }
            }
        }
        int pos[n+1];
        for(int i=0;i<n;i++){
            cout<<p[i];
            if(i!=n-1)
                cout<<" ";
            pos[p[i]]=i+1;
        }
        cout<<endl;
        while(q--){
            cout<<pos[n]<<" "<<pos[n-1]<<endl;
            // if(q!=0)
            //     cout<<endl;
        }
    }
    auto stop=chrono::high_resolution_clock::now();
    auto duration=chrono::duration_cast<chrono::microseconds>(stop-start);
    cerr<<duration.count()/1000.0<<" ms\n";
}
