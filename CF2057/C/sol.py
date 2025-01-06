
a, b, c = map(int, input().split())

fans = 0
fans += a ^ b
fans += a ^ c
fans += b ^ c

print(fans)
print(fans / 2)