
N = 2000 + 10
eps = 1e-9
ten = 10.0
f = [[0 for _ in range(N)] for _ in range(N)]

def init():    
    f[1][1] = 4.5 

    for sz in range(2, N):
        for num in range(10):
            pos = 1
            while pos + 1 <= sz and f[sz - 1][pos] - num * 1.0 >= eps:
                pos += 1
            itr = 1
            for j in range (1, sz + 1):
                if j == pos:
                    f[sz][j] += num / ten
                else:
                    f[sz][j] += f[sz - 1][itr] / ten
                    itr += 1



if __name__ == "__main__":

    init()

    t = int(input())

    for tc in range(t):
        n = int(input())
        s = input()
        # print(n, s)     

        cnt = 0
        for i in range(n):
            if s[i] == '?':
                cnt += 1
        
        itr = 1
        for i in range(n):
            if (s[i] != '?'):
                print(s[i] + ".0", end=" ")
            else:
                formatted_value = f"{f[cnt][itr]:.10f}"
                print(formatted_value, end=" ")
                itr += 1
        print()