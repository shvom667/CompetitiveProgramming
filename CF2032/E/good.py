import random

def Layer1(inp, n):
    res = [0] * n
    for i in range(n):
        res[i] = inp[i - 2]
    return res

def lb(x, y):
    return x // y
def ub(x, y):
    return (x + y - 1) // y

def Layer2(times, n):
    ro = [0] * lb(n, 2) 
    re = [0] * ub(n, 2)
    for i in range(n):
        sp = (i + 1) % n
        ep = sp + 2 * (n // 2 - 1); ep %= n

        if sp < ep:
            if sp % 2 == 0:
                re[sp // 2] += times[i]
                if ep // 2 + 1 < len(re):
                    re[ep // 2 + 1] -= times[i]
            if sp % 2 == 1:
                ro[sp // 2] += times[i]
                if ep // 2 + 1 < len(ro):
                    ro[ep // 2 + 1] -= times[i]

        else:
            assert(sp % 2 != ep % 2)
            if sp % 2 == 0:
                ep1 = n - 1
                re[sp // 2] += times[i]
                if ep1 // 2 + 1 < len(re):
                    re[ep1 // 2 + 1] -= times[i]
                nsp = 1
                nep = ep
                ro[nsp // 2] += times[i]
                if nep // 2 + 1 < len(ro):
                    ro[nep // 2 + 1] -= times[i]

            if sp % 2 == 1:
                ep1 = n - 2
                ro[sp // 2] += times[i]
                if ep1 // 2 + 1 < len(ro):
                    ro[ep1 // 2 + 1] -= times[i]
                nsp = 0
                nep = ep
                re[nsp // 2] += times[i]
                if nep // 2 + 1 < len(re):
                    re[nep // 2 + 1] -= times[i]


    res = [0] * n
    itr = 0



    for i in range(len(re)):
        if i > 0:
            re[i] += re[i - 1]
        res[itr] = re[i]
        itr += 2

    itr = 1
    for i in range(len(ro)):
        if i > 0:
            ro[i] += ro[i - 1]
        res[itr] = ro[i]
        itr += 2


    return res


def Layer3(times, n):
    ro = [0] * lb(n, 2) 
    re = [0] * ub(n, 2)
    for i in range(n):
        sp = (i + 1) % n
        ep = sp + 2 * (n // 2 - 1); ep %= n
        

        if sp < ep:
            if sp % 2 == 0:
                re[sp // 2] += times[i]
                if ep // 2 + 1 < len(re):
                    re[ep // 2 + 1] -= times[i]
            if sp % 2 == 1:
                ro[sp // 2] += times[i]
                if ep // 2 + 1 < len(ro):
                    ro[ep // 2 + 1] -= times[i]

        else:
            assert(sp % 2 != ep % 2)
            if sp % 2 == 0:
                ep1 = n - 1
                re[sp // 2] += times[i]
                if ep1 // 2 + 1 < len(re):
                    re[ep1 // 2 + 1] -= times[i]
                nsp = 1
                nep = ep
                ro[nsp // 2] += times[i]
                if nep // 2 + 1 < len(ro):
                    ro[nep // 2 + 1] -= times[i]

            if sp % 2 == 1:
                ep1 = n - 2
                ro[sp // 2] += times[i]
                if ep1 // 2 + 1 < len(ro):
                    ro[ep1 // 2 + 1] -= times[i]
                nsp = 0
                nep = ep
                re[nsp // 2] += times[i]
                if nep // 2 + 1 < len(re):
                    re[nep // 2 + 1] -= times[i]


    res = [0] * n
    itr = 0



    for i in range(len(re)):
        if i > 0:
            re[i] += re[i - 1]
        res[itr] = re[i]
        itr += 2

    itr = 1
    for i in range(len(ro)):
        if i > 0:
            ro[i] += ro[i - 1]
        res[itr] = ro[i]
        itr += 2


    return res

def Layer4(ap, sp, times, n):
    # O(len(ap) + O(n))
    # a[ap] += 1
    # a[sp] -= 1
    res = [0] * n
    for i in range(len(ap)):
        if ap[i] < sp[i]:
            res[ap[i]] += times[i]
            res[sp[i]] -= times[i]
        else:
            res[ap[i]] += times[i]
            res[0] += times[i]
            res[sp[i]] -= times[i]


    for i in range(1, n):
        res[i] += res[i - 1]


    return res


def solve(n, a):
    op = [0] * n
    d = [0] * n

    for i in range(n):
        d[i] = a[(i + 1) % n] - a[i]
  
    ap = []
    sp = []
    times = []
    for i in range(1, n):
        if d[i] > 0:
            ap.append(0)
            sp.append(i)
            times.append(abs(d[i]))

        if d[i] < 0:
            ap.append(i)
            sp.append(0)
            times.append(abs(d[i]))
    
    res4 = Layer4(ap, sp, times, n)
    res3 = Layer3(res4, n)
    res2 = Layer2(res3, n)

    res1 = Layer1(res2, n)

    return res1

def verify(n, a, op):
    
    for i in range(n):
        a[i] += 2 * op[i]
        a[i - 1] += op[i]
        a[(i + 1) % n] += op[i]

    ok = True


    for i in range(n):
        if a[i] != a[0]:
            ok = False

    return ok  

def bf():
    n = random.randint(3, 200)
    n = 2 * n - 1
    a = [0] * n 
    
    for j in range(n):
        a[j] = random.randint(1, 1000)
    
    op = solve(n, a)

    verify(n, a, op)

if __name__ == "__main__":

    # while True:
    #     bf()

    tt = int(input())
    while tt > 0:
        n = int(input())
        a = list(map(int, input().split()))

        if n == 1:
            print(0)
            tt -= 1
            continue
        if n == 3:
            i = 0
            v = a[0]
            for j in range(3):
                if a[j] < v:
                    v = a[j]
                    i = j

            op = [0] * n
            op[i] = max(a[i - 1], a[i - 2]) - a[i]
            a[i] += op[i]
        

            i = 0
            v = a[0]
            for j in range(3):
                if a[j] < v:
                    v = a[j]
                    i = j
            
            nv = max(a[i - 1], a[i - 2]) - a[i]
            op[i] += nv
            a[i] += nv
            for x in op:
                print(x, end = " ")
            print()
            tt -= 1
            continue


        if n > 3:
            op = solve(n, a)
            i = 0
            v = op[0]
            for j in range(n):
                if op[j] < v:
                    v = op[j]
                    i = j
            for j in range(n):
                op[j] -= v



        
        for x in op:
            print(x, end = " ")
        print()

        assert(verify(n, a, op))

        tt -= 1
