from math import gcd
from math import factorial
# from math import max, min

M = 50
C = [[0] * M for _ in range(M)]
F = [0] * M
dp = [[[0] * M for _ in range(M)] for _ in range(M)]

def mygcd(a, b):
    if min(a, b) == 0:
        return max(a, b)
    return gcd(a, b)

def init():
    C[0][0] = 1
    for i in range(1, M):
        C[i][0] = 1

    for i in range(1, M):
        for j in range(1, i + 1):
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1]

    F[0] = 1
    for i in range(1, M):
        F[i] = F[i - 1] * i

    dp[0][0][0] = 1
    dp[1][0][0] = 1
    dp[1][1][0] = 1

    for i in range(2, M):
        for p in range(i + 1):
            for s in range(i + 1):
                if s + p <= i:
                    if p >= s:
                        dp[i][p][s] += dp[i - 1][p][s]
                        dp[i][p][s] += dp[i - 1][p][s - 1] * (p - s + 1)
                        if p >= s + 1:
                            dp[i][p][s] += dp[i - 1][p - 1][s]

def solve():
    M_val, N, P = map(int, input().split())
    num = 0

    if P == 0:
        if N == 0:
            print("1/1")
        else:
            print("0/1")
        return



    for s in range(N): 
        num += dp[P - 1][N - 1][s] * C[M_val - P][N - s] * F[N - s]

    den = (C[M_val][2 * N] * F[2 * N] // F[N]) // (1 << N)

    g = mygcd(num, den)

    num //= g
    den //= g

    if num > den:
        num = 0
        den = 1

    print(f"{num}/{den}")

if __name__ == "__main__":
    init()
    T = 1
    for _ in range(T):
        solve()
