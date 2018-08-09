#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long MOD = 715827881;

int main() 
{
    int N;
    cin >> N;
    
    vector<long long> next, sum;
        
    next = {1, 1};
    sum  = {0, 1, 2};
    
    for(int i=1; i<N-1; i++)
    {        
        if(i % 2 == 1)
        {
            next.push_back((next.back() * 2) % MOD);            
            sum.push_back(sum.back() + next.back());            
        }
        else
        {
            next.push_back((sum.back() - sum[i - (i / 2)]) % MOD);
            sum.push_back(sum.back() + next.back());
        }
    }
    reverse(next.begin(), next.end());    
    
    long long prev = 0;
    
    for(int i=0; i<N; i++)
    {
        next[i] = (next[i] + prev) % MOD;
        prev = next[i];
        
        cout << next[i] << " ";
    }
}

/*
even = (2 * mid)
odd:
    sum of i/2 previous midterms
*/
