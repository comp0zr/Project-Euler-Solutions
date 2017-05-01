#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


vector<int> memo;

int Primes(int n)
{
    vector<int> primes = {2};
    vector<bool> sieve(n*n);
    
    int p = 2;        

    while(primes.size() < n*n)
    {                      
        for(int i=2; i*p<n*n; i++)
        {
            if(sieve[p*i] == false)
            {
                sieve[p*i] = true;
            }
        }   
        
        int temp = p;
        
        for(int i=p; i<n*n; i++)
        {            
            if(i>p && sieve[i] == false)
            {
               primes.push_back(i);
               p = i;

               break;
            }            
        }
        if(p == temp) break;
    }
    out:
    //for(auto it : primes) cerr << it << endl;
    
    memo = primes;       
    return primes[n-1];    
}



int main() 
{
    int t;
    cin >> t;
    
    while(t--)
    {
        int n;
        cin >> n;
        
        if(memo.size() >= n)
        {
            cout << memo[n-1] << endl;
        }        
        else 
        {
            cout << Primes(n) << endl;
        }
    }
    return 0;
}
