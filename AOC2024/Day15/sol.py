import sys
input = sys.stdin.readline
def inp():
    return(int(input()))
def inlt():
    return(list(map(int,input().split())))
def insr():
    s = input()
    return(list(s[:len(s) - 1]))
def invr():
    return(map(int,input().split()))

n = inp()
g = [['a']*n]*n

for i in range(0, n):
    g[i] = insr()

rx = -1
ry = -1



for i in range(0, n):
    for j in range(0, n):
        if (g[i][j] == '@'):
            rx = i
            ry = j


m = inp()
moves = ['a']*m

moves = insr()

def ok(x, y):
    return x >= 0 and x < n and y >= 0 and y < n and g[x][y] == '.'


print(len(moves))

print(n, m)

for k in range(0, m):
    bx = -1
    by = -1
    if moves[k] == '<':
        for j in range(ry,-1,-1):
            if (g[rx][j] == '#'):
                bx = rx
                by = j
                break
            if (g[rx][j] == 'O'):
                continue;
            if (g[rx][j] == '.'):
                bx = rx
                by = j
                break
        if ok(bx, by):
            g[bx][by] = 'O'
            g[rx][ry] = '.'
            g[rx][ry - 1] = '@'
            rx = rx
            ry = ry - 1

    if moves[k] == '>':
        for j in range(ry,n+1,1):
            if (g[rx][j] == '#'):
                bx = rx
                by = j
                break
            if (g[rx][j] == 'O'):
                continue;
            if (g[rx][j] == '.'):
                bx = rx
                by = j
                break
        if ok(bx, by):
            g[bx][by] = 'O'
            g[rx][ry] = '.'
            g[rx][ry + 1] = '@'
            rx = rx
            ry = ry + 1
            
    if moves[k] == '^':
        for i in range(rx,-1,-1):
            if (g[i][ry] == '#'):
                bx = i
                by = ry
                break
            if (g[i][ry] == 'O'):
                continue;
            if (g[i][ry] == '.'):
                bx = i
                by = ry
                break
        if ok(bx, by):
            g[bx][by] = 'O'
            g[rx][ry] = '.'
            g[rx - 1][ry] = '@'
            rx = rx - 1
            ry = ry

    if moves[k] == 'v':
        for i in range(rx,n + 1,1):
            if (g[i][ry] == '#'):
                bx = i
                by = ry
                break
            if (g[i][ry] == 'O'):
                continue;
            if (g[i][ry] == '.'):
                bx = i
                by = ry
                break
        if ok(bx, by):
            g[bx][by] = 'O'
            g[rx][ry] = '.'
            g[rx + 1][ry] = '@'
            rx = rx + 1
            ry = ry


# for i in range(0, n):
#     for j in range(0, n):
#         print(g[i][j], end="")
    # print()
res = 0

for i in range(0, n):
    for j in range(0, n):
        if g[i][j] == 'O':
            res = res + 100 * (i) + (j)

print(res)