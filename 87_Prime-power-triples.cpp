#include <bits/stdc++.h>
using namespace std;

vector<bool> sieve;
vector<int> primes;
set<int> square, cube, fourth;

void Sieve(int n)
{
    sieve.resize(n+1, 1);
    sieve[0] = sieve[1] = 0;    
    int p = 2;
    
    while(p <= n)
    {
        primes.push_back(p);                 
        
        for(int i=p*2; i<=n; i += p)
        {
            sieve[i] = 0;
        }
        while(++p <= n && !sieve[p]);
    }
}

int main() 
{
    Sieve(10000000);
    int MAX = 10000000;
    
    for(auto it : primes)
    {
        long s, c, f;
        
        s = it * it;
        c = s * it;
        f = c * it;
        
        if(f <= MAX) fourth.insert(f);
        if(c <= MAX) cube.insert(c);        
        if(s <= MAX) square.insert(s);        
        else break;
    }
    
    vector<bool> nums(MAX + 10, 0);
    
    set<int> next;
    
    for(auto s : square)
    {
        for(auto c : cube)
        {
            if(s + c <= MAX)
            {
                next.insert(s + c);
            }
            else break;
        }
    }
    for(auto sum : next)
    {
        for(auto f : fourth)
        {
            if(sum + f < nums.size())
            {
                nums[sum + f] = 1;
            }
        }
    }
    vector<int> ans(MAX + 10, 0);
    
    for(int i=28; i<=MAX; i++)
    {
        ans[i] = ans[i-1] + nums[i];        
    }
    
    int t;
    cin >> t;
    
    while(t--)
    {
        int n;
        cin >> n;
        
        cout << ans[n] << "\n";
    }
    
    return 0;
}

