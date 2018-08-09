#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;

ULL sums[1000010] = {0};
ULL MAX = 1000000000000;
ULL N, limit;

char *sieve;

ULL Multiply(ULL a, ULL b, ULL mod)
{
    a %= mod;
    b %= mod;
    
    if(a <= 0xFFFFFFF && b <= 0xFFFFFFF) return (a * b) % mod;
    
    ULL res = 0;    
    
    __asm__
    (
        "mulq %2\n"
        "divq %3"
        : "=&d" (res), "+%a" (a)
        : "rm" (b), "rm" (mod)
        : "cc"
    );
    return res;
}

ULL Power(ULL n, ULL e, ULL mod)
{
    ULL res = 1;
    
    while(e > 0)
    {
        if(e & 1) res = Multiply(res, n, mod);
        
        n = Multiply(n, n, mod);
        e >>= 1;
    }
    return res;
}

bool MillerRabin(ULL n)
{
    const unsigned int mask = 0x208A28Ac; 
    
    vector<int> smallPrimes = {2, 3, 5, 7, 11, 13, 17};
    
    if(n < 31) return (mask & (1 << n)) != 0;
    for(auto p : smallPrimes)
    {
        if(n % p == 0) return 0;
    }
    if(n < 17 * 19) return 1;
    
    const unsigned int STOP = 0;
    const unsigned int A[] = {377687, STOP}, 
                       B[] = {31, 73, STOP},
                       C[] = {2, 7, 61, STOP},
                       D[] = {2, 13, 23, 1662803, STOP},
                       E[] = {2, 3, 5, 7, 11, STOP},
                       F[] = {2, 3, 5, 7, 11, 13, STOP},
                       G[] = {2, 3, 5, 7, 11, 13, 17, STOP},
                       H[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, STOP},
                       I[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, STOP},
                       J[] = {2, 325, 9375, 28178, 450775, 978054, 1795265022, STOP};
    
    const unsigned int *test = J;
    
    if(n < 5329) test = A;
    else if(n < 9080191) test = B;
    else if(n < 4759123141ULL) test = C;
    else if(n < 1122004669633ULL) test = D;
    else if(n < 2152302898747ULL) test = E;
    else if(n < 3474749660383ULL) test = F;
    else if(n < 341550071728321ULL) test = G;
    else if(n < 3825123056546413051ULL) test = H;
    else if(n <= 18446744073709551615ULL) test = I;
    
    auto d = n - 1;
    d >>= 1;
    
    unsigned int shift = 0;
    
    while((d & 1) == 0)
    {
        shift++;
        d >>= 1;
    }
    
    do
    {
        auto x = Power(*test++, d, n);
        
        if(x == 1 || x == n - 1) continue;
        
        bool possible = false;
        
        for(unsigned int r = 0; r < shift; r++)
        {
            x = Multiply(x, x, n);
            
            if(x == 1) return 0;
            if(x == n - 1)
            {
                possible = true;
                break;
            }
        }
        if(!possible) return 0;
    } 
    while(*test != STOP);
                           
    return 1;
}

bool IsPrime(ULL n)
{
    if(n < 2) return 0;
    if(n < 4) return 1;
    if(n % 2 == 0 || n % 3 == 0) return 0;    
    
    return (n >= limit * 2) ? MillerRabin(n) : sieve[n/2];
}

void Sieve(ULL n)
{
    limit = n / 2 + 1;
    sieve = new char[limit];
    fill(sieve, sieve + limit, 1);
    sieve[0] = 0;
    
    for(ULL p = 1; p * p * 2 < limit; p++)
    {
        if(sieve[p])
        {
            for(ULL i = p * 3 + 1; i < limit; i += (p * 2 + 1))
            {
                sieve[i] = 0;
            }
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    
    vector<long long> queries(t);
    long long mx = 0;
    
    for(int i=0; i<t; i++)
    {
        cin >> queries[i];
        mx = max(mx, queries[i]);
    }    
    Sieve(10000000);        
    
    sums[1] = 2;         
    ULL p = 3;    
    
    int size = 1;
    int maxLength = 0;
    int min_r[33] = {0};
    
    vector<pair<ULL, ULL>> results;        
    
    for(ULL p = 3; p <= mx; p += 2)
    {
        if(sums[size] + p > mx) break;
        
        if(IsPrime(p))
        {
            size++;
            sums[size] = sums[size - 1] + p;
                    
            for(int i = 0; i <= 32 && i + maxLength + 1 <= size; i++)
            {                        
                for(int j = max(i + maxLength + 1, min_r[i]); j <= size; j++)
                {
                    ULL sum = sums[j] - sums[i];
                    
                    if(sum > mx) break;
                    
                    min_r[i] = j + 1;
                    
                    if(IsPrime(sum))
                    {
                        results.push_back({sum, (j - i)});
                        maxLength = j - i;
                        goto next;
                    }
                }
            }
        }
        next:
        continue;
    }  
    
    for(auto n : queries)
    {
        pair<ULL, ULL> prev;
        
        for(auto it : results)
        {
            if(it.first > n) break;
            
            prev = it;
        }
        cout << prev.first << " " << prev.second << "\n";
    }
    return 0;
}
