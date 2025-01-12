
def lb(x, y):
    return x // y
def ub(x, y):
    return (x + y - 1) // y

n = 10
res = lb(n, 2)
print(res)
print(n)
res = ub(n, 2)
print(res)