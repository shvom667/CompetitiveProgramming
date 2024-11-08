#include <iostream>
using namespace std;

const int MMAX = 33;
const int NMAX = MMAX/2;

class Rat {
public :
    long long num, den;
    Rat(long long n=0, long long d=1) { set(n,d); }

    void set(long long n, long long d) {
        num = n;
        den = d;
        reduce();
    }

    void reduce() {
        if (num == 0) {
            den = 1;
            return;
        }
        long long factor = gcd(num, den);
        num = num / factor;
        den = den / factor;
        return;
    }

    long long gcd(long long a, long long b) {
        while (b != 0) {
            long long temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    Rat& operator=(const Rat& other)
    {
        num = other.num;
        den = other.den;
        return *this;
    }
};

int main()
{
    int m = 1, n = 1, p = 0;
    Rat arr[NMAX+1][MMAX+1];

    cin >> m >> n >> p;
    // base cases

    arr[0][0].set(1,1);
    arr[0][1].set(m-2*n, m);
    for(int j = 2; j<=p; j++) {
        arr[0][j].set(arr[0][j-1].num*(m-2*n-j+1), arr[0][j-1].den*(m-j+1));
    }
    arr[1][0].set(0,1);
    for(int i=2; i<=n; i++)
        arr[i][0] = arr[1][0];
    // fill in table
    for(int i=0; i<n; i++) {
        for(int j=0; j<p; j++) {
            Rat t1(arr[i][j].num*2*(n-i), arr[i][j].den*(m-j));
            Rat t2(arr[i+1][j].num*(m-j-2*(n-i-1)), arr[i+1][j].den*(m-j));
            arr[i+1][j+1].set(t1.num*t2.den + t1.den*t2.num, t1.den*t2.den);
        }
    }
                            // now determine prob of winning on exactly the p-th ball
    Rat ans;
    if (p == 0)
        ans = arr[n][p];
    else
        ans.set(arr[n][p].num*arr[n][p-1].den - arr[n][p].den*arr[n][p-1].num, arr[n][p].den*arr[n][p-1].den);
//		System.out.println("Probability of winning on selection " + p + " =\n  " + ans + ".");
    cout << ans.num << "/" << ans.den << endl;
}


