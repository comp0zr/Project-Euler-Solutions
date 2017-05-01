#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
 
vector<int> primes = {2};
vector<unsigned long> sums;

map<int, unsigned long> temp = {{1, 0}, {2, 2}};


void Primes(int n)
{    
    unsigned long sum = 2;
    int p = 2, last_p = 2;
    vector<bool> sieve(n+10);            
            
    while(1)
    {        
        for(int i=2; p*i < sieve.size(); i++)
        {
            if(sieve[p*i] == false) sieve[p*i] = true;
        }
        
        for(int i=p+1; i < sieve.size(); i++)
        {
            if(sieve[i] == false) 
            {
                p = i;
                sum += p;
                temp[p] = sum;
                primes.push_back(p);
                
                break;
            }
        }
        if(p > n) break; 
    }
    out:
    int prev = 0;
    sums.reserve(n+p);
    
    for(auto it : primes)
    {        
        for(int i = prev; i<it; i++)
        {
            sums.push_back(temp[prev]);
        }
        prev = it;
    }    
    sums.push_back(temp[prev]);
    return;
}


int main() 
{
    int t;
    cin >> t;
    
    Primes(1000000);
    
    while(t--)
    {
        int n;
        cin >> n;

        cout << sums[n] << endl;
    }
    return 0;
}
