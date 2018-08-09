e = [2]

def Calculate_E():
    for i in range(2, 300001, 2):
        e.extend([1, i, 1])

def ContinuedFraction(n):
    n -= 1
    fraction = [1, e[n]]
    
    for i in range(n - 1, 0, -1):
        nextFraction = [fraction[0] * 1 + e[i] * fraction[1], fraction[1]]
        fraction = nextFraction[::-1]
        
    fraction = [fraction[0] * 1 + (2 * fraction[1]), fraction[1]]
    res = 0
    
    while fraction[0] > 0:
        res += fraction[0] % 10
        fraction[0] //= 10
    return res

N = int(input())

if(N == 1):
    print("2")
    exit()

Calculate_E()
ans = ContinuedFraction(N)
print(ans)
