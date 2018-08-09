#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
typedef unsigned long long ULL;

const unsigned __int128 MOD = 1000000000000ULL;

unsigned __int128 Power(unsigned __int128 n, unsigned int e)
{
    unsigned __int128 res = 1;
    
    while(e > 0)
    {
        if(e & 1) res = (res * n) % MOD;
        
        n = (n * n) % MOD;
        e >>= 1;
    }
    return res;
}


ULL sum = 0;
bool DB = 0;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    
    while(t--)
    {   
        ULL a, b, c, d;
        cin >> a >> b >> c >> d;
        
        ULL val = (Power(b, c) * a + d) % MOD;        
        sum += val;
        sum %= MOD;
    }
    
    string ans = to_string(sum);
    
    if(ans.size() < 12) ans = string(12 - ans.size(), '0') + ans;

    cout << ans;
    
    return 0;
}

