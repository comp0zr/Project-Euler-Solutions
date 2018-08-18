#include <bits/stdc++.h>
using namespace std;

typedef unsigned int ULL;
const ULL MAX = 20000010;

ULL caller[MAX], called[MAX], S[MAX];

ULL size[MAX] = {0};
ULL parent[MAX] = {0};

ULL N, p;

ULL Find(ULL id)
{    
    while(parent[id] != id)
    {
        parent[id] = parent[parent[id]];
        id = parent[id];
    }
    return id;
}

void Union(ULL x, ULL y)
{
    ULL x_root = Find(x);
    ULL y_root = Find(y);
    
    if(x_root == y_root) return;
    
    if(size[x_root] < size[y_root])
    {        
        swap(x_root, y_root);
    }
    parent[y_root] = x_root;
    size[x_root] += size[y_root];            
}

ULL Generate()
{
    const ULL mod = 1000000;
    ULL calls = 0;
    
    for(ULL k = 1; k <= MAX; k++)
    {
        if(k < 56)
        {
            ULL K = k, b, c;
            
            ULL num = (300007ULL * (K * K * K) - 200003 * k + 100003) % mod; 
            S[k] = num;
            
            if(S[k] < 0) S[k] += mod;
        }
        else 
        {            
            S[k] = (S[k-24] + S[k-55]) % mod;
        } 
        if(k % 2 == 0)
        {            
            called[(k / 2)] = S[k];
            caller[(k / 2)] = S[k-1];
            
            if(called[k/2] != caller[k/2]) 
            {
                calls++;
            }
            else 
            {
                continue;
            }
            Union(caller[k/2], called[k/2]);
            
            ULL sz = size[Find(N)];
                        
            if((double)sz >= 1000000.0 * (double)p / 100.0)
            {
                return calls;
            }            
        }
    }
    return 0;
}

int main() 
{
    cin >> N >> p;    
    
    for(ULL i=0; i <= MAX - 10; i++)
    {
        parent[i] = i;
        size[i] = 1;
    }
    
    ULL ans = Generate();    
    cout << ans;
    
    return 0;
}

