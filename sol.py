M = 100
F = [0] * M

F[0] = 1

for i in range(1, M):
    F[i] = F[i - 1] * i

for i in range(M):
    print(i, F[i])
