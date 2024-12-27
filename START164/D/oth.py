def testcase():

    global cn, cp

    N = int(input())

    S = input()

    cnt = 0

    for c in S:

        if c == "?":

            cnt += 1

    cp[0] = 4.5

    for k in range(2, cnt + 1):

        for j in range(k):

            cn[j] = 0

        p = 0

        for d in range(10):

            while (p < k - 1) and (d > cp[p]):

                p += 1

            for i in range(k):

                if i < p:

                    cn[i] += cp[i]

                elif i == p:

                    cn[i] += d

                else:

                    cn[i] += cp[i - 1]

        for i in range(k):

            cp[i] = cn[i] / 10.0

    k = cnt - 1

    R = [0] * N

    for i in range(N):

        if S[i] == "?":

            R[i] = cp[k]

            k -= 1

        else:

            R[i] = ord(S[i]) - ord("0")

    return R

N = 2000

cn = [-1] * N

cp = [-1] * N

t = 1

t = int(input())

for _ in range(t):

    print(" ".join(map(str, testcase())))
