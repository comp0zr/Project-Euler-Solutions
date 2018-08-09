import sys
import math
from decimal import *

def GetSum(root, P):      
    digits = str(root).replace('.', '')[0:P]
    return sum([int(d) for d in digits])        

def GetPrimes(n): 
    if(n < 3): return [] if n < 2 else [2]
    
    primes = [2, 3]
    
    for p in range(5, n + 1, 2):        
        if(p % 2 == 0 or p % 3 == 0): continue
            
        valid = True
        
        for i in range(5, int(math.sqrt(p))+1, 6):
            if(p % i == 0 or p % (i + 2) == 0): 
                valid = False
                break            
        
        if(valid): primes.append(p)
    
    return primes   


N = int(input())
P = int(input())

getcontext().prec = P + 15

squares = [ i * i for i in range(0, N + 1) ]
roots   = { k: v for k, v in [( i, Decimal.sqrt(Decimal(i)) ) for i in range(1, N+1)] }
primes  = GetPrimes(N)
ans = 0

for i in range(1, N + 1):    
    
    if(i in squares): continue
    if(i in primes): 
        ans += GetSum(roots[i], P)
        continue
        
    for factor in range(2, i):
        if(factor * factor > i): break
        if(i % factor == 0):                        
            s_a = roots[factor]
            s_b = roots[i // factor]
            square_root = s_a * s_b            
            ans += GetSum(square_root, P)            
            roots[i] = square_root
            break 
print(ans)
