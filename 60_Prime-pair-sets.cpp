#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;

int N, K;
long limit;

vector<long> sums;
vector<long> primes;
vector<vector<int>> pairs;
unordered_set<int> check;

bool is_pair[2265][2265];
char *sieve;

vector<long> powers = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};


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
        
    if(n < 31) return (mask & (1 << n)) != 0;
    
    vector<int> smallPrimes = {2, 3, 5, 7, 11, 13, 17};    
    
    for(auto p : smallPrimes)
    {
        if(n % p == 0) return 0;
    }
    if(n < 17 * 19) return 1;

    const unsigned int A[] = {377687, 0}, 
                       B[] = {31, 73, 0},
                       C[] = {2, 7, 61, 0},                       
                       D[] = {2, 325, 9375, 28178, 450775, 978054, 1795265022, 0};
    
    const unsigned int *test;
    
    if(n < 5329) test = A;
    else if(n < 9080191) test = B;
    else if(n < 4759123141ULL) test = C;
    else test = D;
    
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
        
        bool possible = 0;
        
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
    while(*test != 0);                           
    
    return 1;
}


bool IsPrime(long n)
{
    if(n < 2) return 0;
    if(n < 4) return 1;
    if(n % 2 == 0 || n % 3 == 0) return 0;    
    
    if(n >= limit * 2)
    {
        return MillerRabin(n);
    }    
    return sieve[n / 2];
}

void Sieve(long n)
{
    limit = (n / 2) + 1;
    sieve = new char[limit];
    fill(sieve, sieve + limit, 1);
    sieve[0] = 0;    

    for(long i = 1; i*i*2 < limit; i++)
    {
        if(sieve[i])
        {
            for(long j = (i * 3) + 1; j < limit; j += (i * 2) + 1)
            {
                sieve[j] = 0;
            }
        }
    }    
}

int Concatenate(long a, long b)
{
    int x = log10(b);    
    a *= powers[x + 1];
    
    return a + b;
}

void Solve(int k, vector<int> S, bool used[], long sum)
{
    if(k == K)
    {
        sums.push_back(sum);
        return;
    }
        
    if(k == 0)
    {
        for(auto i : check)
        {                                                            
            bool used_temp[2265];                                
            copy(used, used + 2265, used_temp);
                
            S[k] = i;
            Solve(k+1, S, used_temp, sum + primes[i]);           
        }       
        return;
    }
    used[S[k-1]] = 1;
       
    for(auto p : pairs[S[k-1]])
    {
        if(used[p]) 
        {
            continue;
        }

        bool valid = 1;            

        for(int j=0; j<k-1; j++)
        {
            if(!is_pair[S[j]][p])
            {
                valid = false;
                break;
            }
        }
        used[p] = 1;

        if(valid)
        {                 
            bool used_temp[2265];            
            copy(used, used + 2265, used_temp);
            
            S[k] = p;            
            Solve(k+1, S, used_temp, sum + primes[p]);
        }            
    }   
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    Sieve(100000000);
    
    cin >> N >> K;    
    
    pairs.resize(N + 1);    
    primes = {2, 3};
    
    for(int i = 5; i < N; i += 2)
    {
        if(IsPrime(i)) primes.push_back(i); 
    }    
    for(int i = 1; i < primes.size()-1; i++)
    {
        if(i == 2) continue;
        
        int a = primes[i];
        
        for(int j = max(i + 1, 3); j < primes.size(); j++)
        {                        
            int b = primes[j];                                    
            long concat = Concatenate(a, b), concat_2;            
            
            if(IsPrime(concat))
            {                                      
                concat_2 = Concatenate(b, a);
                
                if(IsPrime(concat_2))
                {                                        
                    pairs[i].push_back(j);
                    check.insert(i);
                    is_pair[i][j] = 1;                    
                }
            }
        }
    }
    vector<int> S(K, 0);
    bool used[2265] = {0};
    
    Solve(0, S, used, 0);
    sort(sums.begin(), sums.end());    
    
    for(auto it : sums) cout << it << "\n";    
    return 0;
}

