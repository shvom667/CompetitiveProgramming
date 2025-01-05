
import copy

# ''' # REGION FASTIO   1.7 sec average INTEST    -   best for Codeforces
import os,sys
from io import BytesIO,IOBase
BUFSIZ=8192
class FastIO(IOBase):
    newlines=0
    def __init__(self,file):
        self._fd=file.fileno()
        self.buffer=BytesIO()
        self.writable="n"in file.mode or "r" not in file.mode
        self.write=self.buffer.write if self.writable else None
    def read(self):
        while True:
            b=os.read(self._fd,max(os.fstat(self._fd).st_size,BUFSIZ))
            if not b:
                break
            ptr=self.buffer.tell()
            self.buffer.seek(0,2),self.buffer.write(b),self.buffer.seek(ptr)
        self.newlines=0
        return self.buffer.read()
    def readline(self):
        while self.newlines==0:
            b=os.read(self._fd,max(os.fstat(self._fd).st_size, BUFSIZ))
            self.newlines=b.count(b"\n")+(not b)
            ptr=self.buffer.tell()
            self.buffer.seek(0, 2),self.buffer.write(b),self.buffer.seek(ptr)
        self.newlines-=1
        return self.buffer.readline()
    def flush(self):
        if self.writable:
            os.write(self._fd,self.buffer.getvalue())
            self.buffer.truncate(0),self.buffer.seek(0)
class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer=FastIO(file)
        self.flush=self.buffer.flush
        self.writable=self.buffer.writable
        self.write=lambda s:self.buffer.write(s.encode("ascii"))
        self.read=lambda:self.buffer.read().decode("ascii")
        self.readline=lambda:self.buffer.readline().decode("ascii")
if sys.version_info[0]<3:
    sys.stdin,sys.stdout=FastIO(sys.stdin),FastIO(sys.stdout)
else:
    sys.stdin,sys.stdout=IOWrapper(sys.stdin),IOWrapper(sys.stdout)
input=lambda:sys.stdin.readline().rstrip("\r\n")

def solve():
    n, m, k = map(int, input().split())

    g = [[0 for _ in range(m)] for _ in range(n)]

    for i in range(n):
        g[i] = list(map(int, input().split()))

    s = [[[0 for _ in range(m + 1)] for _ in range(m)] for _ in range(n)]

    for l in range(1, m + 1, 1):
        for i in range(n):
            for j in range(m):
                s[i][j][l] = s[i][j][l - 1] + g[i][(j + l - 1) % m]

    for l in range(m + 1):
        for i in range(n):
            for j in range(m):
                s[i][j][l] += j * k
    
    sp = copy.deepcopy(s)
    ss = copy.deepcopy(s)
    
    for l in range(m + 1):
        for i in range(n):
            for j in range(1, m):
                sp[i][j][l] = min(sp[i][j][l], sp[i][j - 1][l])
    
    for l in range(m + 1):
        for i in range(n):
            for j in range(m - 2, -1, -1):
                ss[i][j][l] = min(ss[i][j][l], ss[i][j  + 1][l])
    
    inf = 10**18
    f = [[[inf for _ in range(m + 1)] for _ in range(m)] for _ in range(n)]

    for l in range(m + 1):
        for i in range(n):
            for j in range(m):
                f[i][j][l] = min(f[i][j][l], -k * j + ss[i][j][l])
                assert(-k * j + ss[i][j][l] >= 0)
                if j - 1 >= 0:
          
                    f[i][j][l] = min(f[i][j][l], -k * j + m * k + sp[i][j - 1][l])

    dp = [[inf for _ in range(m)] for _ in range(n)]

    for j in range(m):
        dp[0][j] = f[0][0][j + 1]

    for i in range(1, n):
        for j in range(m):
            for k in range(j + 1):
                
                dp[i][j] = min(dp[i][j], dp[i - 1][k] + f[i][k][j - k  + 1])


    print(dp[n - 1][m - 1])

if __name__ == "__main__":
    tt = int(input())
    while tt:
        solve()
        tt -= 1
