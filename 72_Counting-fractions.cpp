#include <bits/stdc++.h>
using namespace std;

vector<bool> sieve;
bool db = 0;

vector<long long> primes;

void Sieve(int n)
{
    sieve.resize(n + 10, 1);    
    sieve[0] = sieve[1] = 0;    
    
    long long p = 2;
        
    while(p <= n)
    {
        primes.push_back(p);
        
        for(long long i=p*2; i <= n; i += p)
        {
            sieve[i] = 0;
        }                
        while(++p <= n && !sieve[p]);                                            
    }    
}

long long Totient(long long n)
{    
    set<long long> factors;
    long long temp = n;
    
    while(!sieve[temp] && temp > 1)
    {        
        for(auto p : primes)
        {            
            if(temp % p == 0)
            {                
                factors.insert(p);                                                
                temp /= p;
                
                if(sieve[temp]) factors.insert((long long)(temp));
                
                break;
            }        
            if(p*p > temp) break;
        }
    }
    double res = (double)n;
    
    for(auto p : factors)
    {
        double fraction = 1.0 - (1.0 / (double)p);
        res *= fraction;        
    }            
    return round(res);
}

int main()
{
    Sieve(1000000);
    
    long long sum = 0;
    vector<long long> ans(1000001);
    
    for(long long i = 1; i <= 1000000; i++)
    {   
        long long totient = (sieve[i]) ? i - 1 : Totient(i);
        
        sum += totient;
        ans[i] = sum;
    }
    int t;
    cin >> t;
    
    while(t--)
    {
        int n;
        cin >> n;
                
        cout << ans[n]-1 << endl;
    }
}
