t = int(input())
for _ in range(t):
    x = int(input())
    ans = -1
    for i in range(30):
        for j in range(30):
            y = (1 << i) | (1 << j)
            if y < x and x + y > (x ^ y) and y + (x ^ y) > x:
                ans = y
    print(ans)
