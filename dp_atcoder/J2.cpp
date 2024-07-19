#include <bits/stdc++.h>
using namespace std;
#define double long double
int main() {
    const long long INF = 1e18;
    const long long mod = 1e9 + 7;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long N; cin >> N;
    vector<long long> freq(4,0);
    for(int i=0; i<N; i++){
        long long g; cin >> g;
        freq[g]++;
    }
    double dp[freq[1]+1][freq[2]+1][freq[3]+1];
    dp[0][0][0]=1;
    for(long long k=0;k<=freq[3]; k++){
        for(long long j=0; j<=freq[2]; j++){
            for(long long i=0; i<=freq[1]; i++){
                if (i + j + k == 0) continue;
                double p1 = (double) (i/N);
                double p2 = (double) (j/N);
                double p3 = (double) (k/N);
                double p0 = (double)((N-(i+j+k))/N);
                dp[i][j][k]=(1+p1*(i-1>=0?dp[i-1][j][k]:(double)0)+p2*(j-1>=0?dp[i+1][j-1][k]:(double)0)+p3*(k-1>=0?dp[i][j+1][k-1]/(1-p0):(double)0));
            }
        }
    }
    cout << setprecision(30) << dp[freq[1]][freq[2]][freq[3]];
}
