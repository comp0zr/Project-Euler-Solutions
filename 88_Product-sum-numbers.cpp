#include <bits/stdc++.h>
#define end END
using namespace std;

int N, end;
vector<int> *factors;
vector<int> M(2000010, 1e9);

void Solve(int start, int prod, int sum, int size, int prev)
{        
    if(prod == 1)
    {
        if(sum == 0) 
        {
            if(start < M[size]) M[size] = start;
        }
        else if(size + sum <= N) 
        {            
            M[size + sum] = min(M[size + sum], start);
        }        
        return;
    }        
    if(size == end || size >= start / 2 + 1) return;    
    
    for(auto f : factors[prod])
    {                
        if(f < prev) continue;                
        if(f > sum) break;
  
        Solve(start, prod / f, sum - f, size + 1, f);
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    end = N * 2;
    
    factors = new vector<int>[end + 1];

    for(int i = 2; i <= N; i++)
    {
        for(int j = i; j <= end; j += i)
        {            
            factors[j].push_back(i);                        
        }
    }
    for(int i = 4; i <= end; i++)
    {                   
        Solve(i, i, i, 0, 2);
    }    
    long long ans = 0;
    bool used[1000000] = {0};
        
    for(int i = 2; i <= N; i++)
    {        
        if(M[i] == 1e9) continue;
        if(!used[M[i]])
        {               
            ans += M[i];
            used[M[i]] = 1;
        }
    }
    cout << ans;
    return 0;
}  
  
