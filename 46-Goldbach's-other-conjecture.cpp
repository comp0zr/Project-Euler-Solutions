#include <bits/stdc++.h>
using namespace std;

set<int> primes, squares;

void Sieve(int n)
{
    vector<bool> sieve(1000010, false);
    int p = 2;
    sieve[2] = true;
    
    while(p <= n)
    {
        primes.insert(p);
        
        for(int i=2; p*i <= n; i++) sieve[p*i] = true;        
        while(p < sieve.size() && sieve[p]) p++;
        sieve[p] = true;        
    }
}

int main() 
{
    Sieve(500000);
    
    for(int i=1; i*i <= 500000; i++)
    {
        squares.insert(i*i);
    }
    
    int t;
    cin >> t;
    
    while(t--)
    {
        int n;
        cin >> n;
        
        int ans = 0;
        
        for(auto it : primes)
        {
            int diff = n - it;

            if(diff % 2 == 1) continue;
            
            if(squares.count(diff / 2)) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}

