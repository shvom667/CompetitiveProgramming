#!/usr/bin/python3


def gcd(a,b):
    if a < 0:
        a = -a
    if b < 0:
        b = -b

    while b != 0:
        a,b = b,a%b

    return a


def add(f1,f2):
    num = f1[0] * f2[1] + f1[1] * f2[0]
    den = f1[1] * f2[1]

    g = gcd(num,den)

    num = num // g
    den = den // g

    return [num,den]


def mul(f1,f2):
    num = f1[0] * f2[0]
    den = f1[1] * f2[1]

    g = gcd(num, den)

    num = num // g
    den = den // g

    return [num, den]


def f(r,c):
    if c == 0:
        if r == 0:
            return [1,1]
        else:
            return [0,1]
    elif r < 0:
    	return [0,1]
    else:
#        table[r+1][c+1] = add(table[r+1][c+1],mul(table[r][c], [nGood,nBalls]))
# r' = r+1 ... r = r' - 1, c = c' - 1... nBalls = m - (c' - 1), nGood = 2 * (n - (r' - 1))
#        table[r][c+1] = add(table[r][c+1],mul(table[r][c], [nBalls-nGood,nBalls]))
# r' = r... r = r', c = c' - 1... nBalls = m - (c' - 1), nGood = 2 * (n - r')
        nBalls = m - c + 1
        nGood = 2 * (n - r + 1)
        nGood2 = 2 * (n - r)
        ans = add(mul(f(r-1,c-1),[nGood,nBalls]),mul(f(r,c-1),[nBalls-nGood2,nBalls]))
#        print(r,c,ans)
        return ans


m,n,p = map(int,input().split(' '))

#table = []

#for i in range(n+1):
#    table.append([])
#    for j in range(p+1):
#        table[i].append([0,1])

#table[0][0] = [1,1]

#for c in range(p):
#    nBalls = m - c
#    for r in range(n):
#        nGood = 2 * (n - r)
#        table[r+1][c+1] = add(table[r+1][c+1],mul(table[r][c], [nGood,nBalls]))
#        table[r][c+1] = add(table[r][c+1],mul(table[r][c], [nBalls-nGood,nBalls]))

ans = mul(f(n-1,p-1),[2,(m - p + 1)])

#for r in table:
#    print(r)
#print(ans)

if p == 0:
    if n == 0:
        print('1/1')
    else:
        print('0/1')
elif n == 0:
    print('0/1')
else:
    print(f'{ans[0]}/{ans[1]}')
