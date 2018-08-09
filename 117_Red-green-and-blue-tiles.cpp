#include <bits/stdc++.h>
using namespace std;

long long MOD = 1000000007;

long long Solve(long long n)
{
    long long a = 0, b = 0, c = 0, d = 1;    
    
    string bits = bitset<64>(n).to_string();
    bits = bits.substr(bits.find('1'));
    
    int length = bits.size();
            
    for(long long i = length-1; i >= 1; i--)
    {                        
        long long next_a, next_b, next_c, next_d;

        next_a = (b * (2 * c - b) % MOD) % MOD + ((a * (2 * (d - c - b) - a) % MOD) % MOD);
        next_b = (a * a) % MOD + (c * c) % MOD + (b * ((2 * (d - c) - b)) % MOD) % MOD;
        next_c = (b * ((2 * a + b) % MOD)) % MOD + (c * ((2 * d - c)) % MOD) % MOD;
        next_d = (b * b) % MOD + (d * d) % MOD + c * ((2 * (a + b) + c)) % MOD;
            
        
        a = next_a % MOD;
        b = next_b % MOD;        
        c = next_c % MOD;
        d = next_d % MOD;
        
        if(((n >> i) & 1) == 1)
        {            
            long long next = a + b + c + d; 
            next = (((((a + b) % MOD) + c) % MOD) + d) % MOD;                        
            
            a = b;
            b = c;
            c = d;           
            d = next;
            
            if(a < 0) a += MOD;
            if(b < 0) b += MOD;
            if(c < 0) c += MOD;
            if(d < 0) d += MOD;
        }
    }
    if((n & 1) == 0)
    {
        return b * (2 * c - b) + a * (2 * (d - c - b) - a);
    }
    return a * a + c * c + b * (2 * (d - c) - b);
}

int main()
{
    int t;
    cin >> t;
                
    while(t--)
    {        
        long long n, ans;
        cin >> n;
                
        ans = Solve(n+3) % MOD;
        
        if(ans < 0) ans += MOD;
        
        cout << ans << "\n";
    }    
}

