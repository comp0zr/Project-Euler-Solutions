def IsLess(a, b): return (a[0] * b[1] < a[1] * b[0])

T = int(input())

queries = []

for t in range(T):
    p, q = map(int, input().split())
    queries.append(tuple([p, q]))
    
_sorted = sorted(queries, key=lambda x: x[0] / x[1])[::-1]

ans = {}

count = 1
total = 1
index = 0

while(index < len(_sorted)):
    _next = total * 2
    ratio = [count, _next]

    if(IsLess(ratio, _sorted[index])):        
        num = count * _sorted[index][1]
        den = _next * _sorted[index][0]        
        num *= _next                
        k = (num // den) + 1
        
        ans[_sorted[index]] = k * (k + 1)
        index += 1
    else:
        total = _next + 1  
        count += 1

for q in queries: print(ans[q])def IsLess(a, b): return (a[0] * b[1] < a[1] * b[0])

T = int(input())

queries = []

for t in range(T):
    p, q = map(int, input().split())
    queries.append(tuple([p, q]))
    
_sorted = sorted(queries, key=lambda x: x[0] / x[1])[::-1]

ans = {}

count = 1
total = 1
index = 0

while(index < len(_sorted)):
    _next = total * 2
    ratio = [count, _next]

    if(IsLess(ratio, _sorted[index])):        
        num = count * _sorted[index][1]
        den = _next * _sorted[index][0]        
        num *= _next                
        k = (num // den) + 1
        
        ans[_sorted[index]] = k * (k + 1)
        index += 1
    else:
        total = _next + 1  
        count += 1

for q in queries: print(ans[q])
