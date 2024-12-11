a=[1,10,9,8,7,6,5,4,3,2]
res = 0
for i in range(len(a)):
    res+=2**a[i]
print(res)
