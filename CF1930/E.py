import sys

dict = {}

def prod(n):    
    if n in dict:
        return dict[n]
    if n<=1:
        return 1
    else:
        dict[n] = n*prod(n-1)
        return n*prod(n-1)

def nCx(n,x):
    return prod(n)/(prod(x)*prod(n-x))



def get1(x, y):
    res = 0
    for i in range(y-x+1):
        assert(i<=y-x)
        res += nCx(x+i,x)*nCx(y-i,x)
    return res

def get2(x, y):
    res = nCx(x+y+1,y-x)
    return res

if __name__ == "__main__":
    sys.setrecursionlimit(150000000)

    # res1 = get1(3,4)
    # res2 = get2(3,4)
    # print(res1, res2)
    for x in range(1, 10):
        for y in range(x+1, 10):
            
            if (get1(x,y) != get2(x,y)):
                print(x,y)
            
