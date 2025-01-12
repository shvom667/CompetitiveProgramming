

n = 4 << 10
dp = [0] * n
dp[3] = 1

for j in range(4, n):
    sb = sum([1 for i in range(j.bit_length()) if j & (1 << i)])
    if sb == 1:
        dp[j] = 0
        continue
    if sb == 2:
        dp[j] = 1
        continue
    for k in range(1, j - 1):
        l = k ^ j
        if l < j:
            if dp[l] == 0 and dp[k] == 0:
                dp[j] = 1

for j in range(1, n):
    sb = sum([1 for i in range(j.bit_length()) if j & (1 << i)])
    assert(sb % 2 != dp[j])
    print(j, dp[j])