#include <bits/stdc++.h>
using namespace std;

long long N;
int a, b;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> a >> b;
    
    queue<long long> tri, pent, hex;
    long long ans = 0;
    
    if(a == 3)
    {
        long long next = 1;
        
        for(long long i = 1; i < N; i += next)
        {
            tri.push(i);
            next++;
        }
        
        next = 1;
        
        for(long long i = 1; i < N; )
        {
            if(tri.empty()) break;            
            if(i > tri.front())
            {
                tri.pop();
                continue;
            }            
            if(i == tri.front())
            {                
                cout << i << "\n";
            }      
            next += 3;    
            i += next;            
        }
    }
    else
    {
        long long next = 1;
        
        for(long long i = 1; i < N; i += next)
        {
            pent.push(i);
            next += 3;    
        }        
        
        next = 1;
        
        for(long long i = 1; i < N; )
        {
            if(pent.empty()) break;
            if(i > pent.front())
            {
                pent.pop();
                continue;
            }            
            if(i == pent.front())
            {
                cout << i << "\n";
                pent.pop();
            }
            next += 4;
            i += next;            
        }
    }
    return 0;
}

