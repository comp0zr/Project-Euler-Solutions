prev = {(0, 0): 1}
M = {}

for move in range(65):                
    M[move] = [0, 0]    
    _next = {}
    
    for i in sorted(prev.items()):
        poss = i[0]
        count = i[1]                
                
        if(poss[0] > poss[1]): 
            M[move][0] += count
        M[move][1] += count
        
        a = (poss[0], poss[1] + 1)
        b = (poss[0] + 1, poss[1])
        
        if(a not in _next): _next[a] = 0
        if(b not in _next): _next[b] = 0
        
        _next[a] += count * (move + 1)
        _next[b] += count
    prev = _next
    
T = int(input())

for i in range(T):
    N = int(input())
    print(M[N][1] // M[N][0])
