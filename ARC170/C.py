
f = 0
for i in range(1,3):
    for j in range(1,3):
        for k in range(1,3):
            for l in range(1,3):
                cnt1=0
                cnt2=0
                # cnt3=0
                cnt1 = cnt1+(i==1)
                cnt1 = cnt1+(j==1)
                cnt1 = cnt1+(k==1)
                cnt1 = cnt1+(l==1)

                cnt2 = cnt2+(i==2)
                cnt2 = cnt2+(j==2)
                cnt2 = cnt2+(k==2)
                cnt2 = cnt2+(l==2)

                # cnt3 = cnt3+(i==3)
                # cnt3 = cnt3+(j==3)
                # cnt3 = cnt3+(k==3)
                # cnt3 = cnt3+(l==3)


                if cnt1 >= 1 and cnt2 >= 1:               
                    print(i,j,k,l)

                    f += 1

print(f)
