#include <bits/stdc++.h>
using namespace std;

bool IsPrime(long long n)
{
    if(n <= 1) return false;
    if(n <= 3) return true;    
    if(n % 2 == 0 || n % 3 == 0) return false;
    
    for(long long i=5; i*i <= n; i += 6)
    {
        if(n % i == 0 || n % (i+2) == 0)
        {
            return false;
        }
    }
    return true;
}



int main() 
{
    vector<vector<long long>> primes(12);
    string pandigital = "123456789";
    
    while(!pandigital.empty())
    {
        do
        {
            long long num = stoll(pandigital);
            
            if(IsPrime(num))
            {
                primes[pandigital.size()].push_back(num);
            }
        }
        while(next_permutation(pandigital.begin(), pandigital.end()));

        pandigital.pop_back();
    }
    int t;
    cin >> t;    
    
    while(t--)
    {
        long long n;
        cin >> n;
        
        if(n >= 7652413) 
        {
            cout << 7652413 << endl;
            continue;
        }
        else if(n < 1423)
        {
            cout << -1 << endl;
            continue;
        }
        
        string s = to_string(n);
        long long ans;
        
        for(int i=4; i<=10; i++)
        {
            for(auto it : primes[i])    
            {
                if(it > n) 
                {
                    goto out;
                }
                ans = it;
            }
        }
        out:
        cout << ans << endl;
    }
}
