import sys

sieve = []
limit = 0
S = set()

def Sieve(n):    
    global sieve
    
    limit = n // 2 + 1    
    sieve = [True] * limit
    sieve[0] = False
    
    p = 1
    
    while(p * p * 2 < limit):
        if(sieve[p]):
            for i in range(3*p+1, limit, 2*p+1):
                sieve[i] = 0                            
        p += 1        

def MillerRabin(n):
    mask = 0x208A28Ac
    smallPrimes = [2,3,5,7,11,13,17]
    
    if(n < 31): return (mask & (1 << n)) != 0
    
    for p in smallPrimes:
        if(n % p == 0): return False
    if(n < 17 * 19): return True
    
    A = [377687, 0]
    B = [31, 73, 0]
    C = [2, 7, 61, 0]
    D = [2, 13, 23, 1662803, 0]
    E = [2, 3, 5, 7, 11, 0]
    F = [2, 3, 5, 7, 11, 13, 0]
    G = [2, 3, 5, 7, 11, 13, 17, 0]
    H = [2, 3, 5, 7, 11, 13, 17, 19, 23, 0]
    I = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 0]
    J = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 0]
    K = [2, 325, 9375, 28178, 450775, 978054, 1795265022]
    
    test = K
    
    if(n < 5329): test = A
    elif(n < 9080191): test = B
    elif(n < 4759123141): test = C
    elif(n < 1122004669633): test = D
    elif(n < 2152302898747): test = E
    elif(n < 3474749660383): test = F
    elif(n < 341550071728321): test = G
    elif(n < 3825123056546413051): test = H
    elif(n < 318665857834031151167461): test = I
    elif(n < 3317044064679887385961981): test = J        
        
    d = n - 1
    d >>= 1
    
    shift = 0
    
    while((d & 1) == 0): 
        shift += 1
        d >>= 1

    for witness in test:
        if(witness == 0): break
        x = pow(witness, d, n)
        
        if(x == 1 or x == n - 1): continue
            
        possible = False
        
        for r in range(shift):
            x = (x * x) % n
            
            if(x == 1): return False
            if(x == n - 1):
                possible = True
                break
        if(possible == False): return False
    return True
        
    
def IsPrime(n):
    if(n < limit * 2): return sieve[n//2]
    
    return MillerRabin(n)


def GenerateNumbers(num, size, n, d):
    global S

    if(len(num) == n):
        if(IsPrime(int(num))):
            S.add(str(num))
        return

    for i in range(0, 10):
        if(i == d): continue
        if(d % 2 == 0):            
            if(num[0] == '0'): 
                if(i != 0): 
                    GenerateNumbers(str(i) + num, size + 1, n, d)
                    continue
            elif(num[-1] == str(d)[0] and i % 2 == 1): 
                GenerateNumbers(num + str(i), size + 1, n, d)
                continue
        
        for j in range(len(num)+1):
            if(i == 0 and j == 0): continue
            if(i % 2 == 0 and size == n-1 and j == len(num)): break
            
            temp = num[0:j] + str(i) + num[j:]            
            GenerateNumbers(temp, size + 1, n, d)
        
######################

Sieve(1000000)

T = int(input())

for t in range(T):
    n, d = map(int, input().split())        
    S = set()

    if(d % 2 == 1 and IsPrime(int(str(d) * n))):
        print(str(d) * n)
        continue
    
    for i in range(n - 2 if d == 0 else n - 1, 0, -1):            
        num = str(d) * i        
        GenerateNumbers(num, i, n, d)
        
        if(len(S) > 0): break
    
    S = sorted(S)
    print(' '.join(str(num) for num in S))
