#include <bits/stdc++.h>
#define int long long

using namespace std;

long long combine(vector<int>&a, int low, int high) {
    long long fans = 0;
    int mid = low + (high - low) / 2;
    
    for (int i = high, p = mid+1; i >= mid+1; i--) {
        while (p - 1 >= low && a[p-1] >= a[i]) {
            p--;
        }
        fans+=mid+1-p;
    }

    vector<int> temp;
    
    if (true) {
        int f = low, F = mid, s = mid+1, S = high;
        while (f <= F && s <= S) {
            if (a[f] < a[s]) {
                temp.push_back(a[f]);
                f++;
            }else{
                temp.push_back(a[s]);
                s++;
            }
        } 
        while (f <= F) {
            temp.push_back(a[f]);
            f++;
        }
        while (s <= S) {
            temp.push_back(a[s]);
            s++;
        }
    }
   
    for(int i=low;i<=high;i++){
        a[i] = temp[i-low];
    }

    return fans;
}

long long mergeSort(vector<int>&a, int low, int high) {
    if (low >= high) {
        return 0ll;
    }
    long long fans=0;
    int mid = low + (high - low) / 2;
    fans+=mergeSort(a, low, mid);
    fans+=mergeSort(a, mid+1, high);
    fans+=combine(a,low,high);
    return fans;
}

long long numberOfInversions(vector<int>&a, int n) {
    return mergeSort(a, 0, n - 1);
}


void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    

    long long ca = numberOfInversions(a, n);
    long long cb = numberOfInversions(b, n);

    sort(begin(a), end(a));
    sort(begin(b) ,end(b));
    if (a != b) {
        cout << "NO\n";
        return;
    }

    if (ca%2!=cb%2){
        cout<<"NO\n";
    }else{
        cout<<"YES\n";
    }
}


signed main() {
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}


/*
6
4
1 2 3 4
1 2 3 4
5
1 3 4 2 5
7 1 2 5 4
4
1 2 3 4
4 3 2 1
3
1 2 3
1 3 2
5
1 5 7 1000 4
4 1 7 5 1000
3
1 4 2
1 3 2
*/
    