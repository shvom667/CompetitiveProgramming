
def solve():
    n = int(input())
    v = n // 3 + (n % 3 == 2)
    m1 = v
    m2 = n - v + 1
    l1 = m1 - 1 + 1
    l2 = m2 - 1 - m1 - 1 + 1    
    l3 = n - m2 + 1
    print(l1, l2, l3)

def ternary(n):
    if n <= 4:
        return 2
    return ternary(n // 4)  + 2


#position of 1 in 45 queries
# + 30 queries for k
#atleast we can do it in 75 queries!!!
#but we need to do it in 33 queries -_-

print(ternary(1 << 30))
