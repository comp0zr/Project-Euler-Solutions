#include <bits/stdc++.h>
using namespace std;

set<map<int, int>> S;
set<int> primes;
map<vector<int>, long long> memo;

void Sieve(int n)
{
    vector<bool> sieve(n+10, false);
    
    int p = 2;
    
    while(p <= n)
    {
        primes.insert(p);
        sieve[p] = true;
        
        for(int i=2; i*p <= n; i++)
        {
            sieve[i*p] = true;
        }
        while(p <= n && sieve[p]) ++p;
    }
}

long long Solve(int N, int prev)
{
    if(N == 0) 
    {
        return 1;
    }
    
    if(memo.count({N, prev})) 
    {
        return memo[{N, prev}];
    }
    long long res = 0;
    
    for(auto it : primes)
    {
        if(N - it < 0) break;
        if(prev != -1 && it > prev) break;
        
        res += Solve(N - it, it);
    }
    memo[{N, prev}] = res;
    return res;
}

int main() 
{
    Sieve(1000);
    
    int t;
    cin >> t;   
    
    while(t--)
    {
        int N;
        cin >> N;
        
        long long ans = Solve(N, -1);
        cout << ans << endl;
    }
    
    return 0;
}

