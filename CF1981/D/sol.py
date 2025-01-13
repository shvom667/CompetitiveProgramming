from  collections import defaultdict

def chk(a, n):
    assert(len(a) == n)
    d = defaultdict(int)
    for i in range(len(a) - 1):
        d[a[i] * a[i + 1]]+=1


    print(d)

    for key in d:
        print(key, d[key])
        if d[key] > 1:
            assert(False)
chk([1, 1, 5, 2, 2, 5, 3, 3, 5, 5], 10)    


# def cond(a):
#     d = defaultdict(int)
#     for i in a:
#         for j in a:
#             d[i * j] += 1

#     print(d)
#     print(len(d))
#     return len(d) >= 10**6

# cond([1,2,3,5,7])

# L = 1
# R = 2043

# while L <= R:
#     # print(L)
#     mid = L + ((R - L) >> 1)
#     if (cond(mid)):
#         R = mid - 1
#     else:
#         L = mid + 1
    
# print(L)