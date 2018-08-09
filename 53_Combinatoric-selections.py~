factorial = [0, 1]

for i in range(2, 1001):
    factorial.append(factorial[-1] * i)

C = [[0], [0]] + [
        [0]+[factorial[i] / (factorial[j] * factorial[i-j]) for j in range(1, i)] 
        for i in range(2, 1001)
    ]

N, K = map(int, input().split())
ans = 0

for i in range(1, N+1):
    for j in C[i]:
        if(j > K): ans += 1
        
print(ans)
