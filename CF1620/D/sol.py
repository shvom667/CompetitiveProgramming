from collections import defaultdict

mp = defaultdict(int)

def check(x):
    if mp[3] < 0:
        return False

    a = []
    for j in range(mp[1]):
        a.append(1)
    for j in range(mp[2]):
        a.append(2)
    dp = [0] * 15
    dp[0] = 1

    for j in range(1 << len(a)):
        cur = 0
        for b in range(len(a)):
            if (j & (1 << b)) > 0:
                cur += a[b]
        dp[cur] = 1

    for i in range(15):
        if dp[i] == 1:
            if x >= i and (x - i) % 3 == 0:
                if mp[3] >= ((x - i) // 3):
                    return True
    return False






def solve():
    n = int(input())
    a = list(map(int, input().split()))

    a.sort()

    ok = True
    for i in range(n):
        if a[i] % 3 > 0:
            ok = False

    fans = -1

    mp.clear()
    mp[3] = 1
    mp[1] = 1

    res = check(5)

    if ok:
        fans = a[n - 1] // 3
    else:
        found = False

        if not found:
            mp.clear()
            mp[3] = a[n - 1] // 3
            mp[1] = 1

            good = True
            for i in range(n):
                if not check(a[i]):
                    good = False

            if good:
                found = True
                fans = a[n - 1] // 3 + 1

        if not found:
            mp.clear()
            mp[3] = a[n - 1] // 3
            mp[2] = 1

            good = True
            for i in range(n):
                if not check(a[i]):
                    good = False

            if good:
                found = True
                fans = a[n - 1] // 3 + 1

        if not found:
            mp.clear()
            mp[3] = a[n - 1] // 3 - 1
            mp[1] = 2

            good = True
            for i in range(n):
                if not check(a[i]):
                    good = False

            if good:
                found = True
                fans = a[n - 1] // 3 + 1

        if not found:
            mp.clear()
            mp[3] = a[n - 1] // 3 - 1
            mp[2] = 2

            good = True
            for i in range(n):
                if not check(a[i]):
                    good = False

            if good:
                found = True
                fans = a[n - 1] // 3 + 1

        if not found:
            mp.clear()
            mp[3] = a[n - 1] // 3 - 1
            mp[1] = 1
            mp[2] = 1

            good = True
            for i in range(n):
                if not check(a[i]):
                    good = False

            if good:
                found = True
                fans = a[n - 1] // 3 + 1

        if not found:
            mp.clear()
            mp[3] = a[n - 1] // 3 - 2
            mp[2] = 3

            good = True
            for i in range(n):
                if not check(a[i]):
                    good = False

            if good:
                found = True
                fans = a[n - 1] // 3 + 1

        if not found:
            fans = a[n - 1] // 3 + 2




    print(fans)





if __name__ == "__main__":
    t = int(input())

    for tc in range(t):
        solve()

#a[i] % 3 == 0, a[n - 1] / 3
#
#ans <= a[n - 1] / 3 + 2
#ans >= a[n - 1] / 3
#
#When a[n - 1] / 3 + 1 ??
#
#a[n - 1] / 3 -> 3
#1 -> 1
#
#a[n - 1] / 3 -> 3
#1 -> 2
#
#a[n - 1] / 3 - 1 -> 3
#2 -> 1
#
#a[n - 1] / 3 - 1 -> 3
#2 -> 2
#
#a[n - 1] / 3 - 1 -> 3
#1 -> 1
#1 -> 2
#
#a[n - 1] / 3 - 2 -> 3
#3 -> 2
#
#
#done
