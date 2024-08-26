
# Counting Rectangles

N = 2005

g = [[0]*N for _ in range(N)]

for i in range(N):
    g[i][1] = (i * (i + 1)) /2
    g[1][i] = g[i][1]
        
for i in range(2, N):
    for j in range(2, N):
        g[i][j] = 2*g[i-1][j] - g[i-2][j] + j * (j + 1) / 2


v = 1e9
r = 2e6
res = [-1,-1]
for i in range(1, N):
    for j in range(1, N):
        mod = abs(g[i][j]-r)
        if mod < v:
            v = mod
            res = [i,j]

def sum(n):
    return (n*(n+1))/2
print(res[0], res[1], g[36][77], res[0]*res[1])
print((sum(36))* (sum(77)))