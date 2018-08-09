from __future__ import division
from decimal import *
from fractions import Fraction

import sys
import math

getcontext().prec = 420

EPSILON = Decimal(0.0000000001)
ans, max_num = 0, 0

def IsPerfectSquare(n):
    sqrt = Decimal(math.floor(Decimal.sqrt(n)))    
    return (sqrt * sqrt == n)

def ContinuedFraction(n):
    R = Decimal(math.floor(Decimal.sqrt(n)))
    P = [0, 1, 0]
    Q = [1, 0, 0]        
    
    x = Decimal.sqrt(Decimal(n))
    
    for i in range(2, 500):
        A = Decimal(math.floor(x))
        P[2] = Decimal(A) * Decimal(P[1]) + Decimal(P[0])
        Q[2] = Decimal(A) * Decimal(Q[1]) + Decimal(Q[0])
                        
        X = Decimal(P[2] * P[2])
        Y = Decimal(Q[2] * Q[2])        
        solution = Decimal(X - (n * Y))
                
        if(solution >= 0 and solution < 2): return [P[2], Q[2]]                
        if(Decimal(math.fabs(x - A)) < EPSILON): return [P[2], Q[2]]
        if(Q == 1 and i % 2 == 0): return [P[2], Q[2]]
        
        P = [P[1], P[2], 0]
        Q = [Q[1], Q[2], 0]
        x = Decimal(1.0000000000) / Decimal(x - A)        
        
    return [-1, -1]


N = int(input())

for D in range(5, N + 1, 2):
    
    if(IsPerfectSquare(Decimal(D))): continue
        
    fraction = ContinuedFraction(Decimal(D))
    
    if(fraction[1] > max_num):
        ans = D
        max_num = fraction[1]
        
print(ans)
