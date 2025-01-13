tt = int(input())

for tc in range(tt):
    n, k, l = map(int, input().split())
    a = list(map(int, input().split()))
    time = a[0]
    pc = k

    sgn = lambda x: 1 if x > 0 else 0 if x == 0 else -1

    

    for i in range(1, n):
        if sgn(pc - a[i]) == 1:
            np = min(pc, a[i] + time)
        elif sgn(pc - a[i]) == -1:
            np = max(pc, a[i] - time)
        else:
            np = a[i]
        
        if np > pc:
            mid = (np + pc) / 2
            time += abs(pc - np) / 2
            pc = min(l, mid + k)    
        else:
            pc = np + k
            pc = min(pc, l)
    time += l - pc

    print(round(2 * time))



# Only 1 scarecrow
#   ans = position_scarecrow + L - K

# maximize the distance that the crow can teleport
# each scarecrow can teleport the crow atmax once
# every scarecrow will teleport the distance of teleport can range form 0 to n
# so goal is to maximize the teleportation distance
# a scarecrow that was with lesser index will teleport first, and then the scarecrow with more index
# so scarecrow will compute how previous scarecrows have landed crow and then it will move 
# once the crow starts moving to the right it will always move with the same speed
