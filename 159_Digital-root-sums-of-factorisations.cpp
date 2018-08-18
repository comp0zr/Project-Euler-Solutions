#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int MDRS[10000001] = {0};
long long ans[10000001] = {0};

int MAX = 1e7;

int DigitalRootSum(int n)
{
    if(n < 10) return n;
    
    int sum = 0;    
    
    while(n)
    {
        sum += (n % 10);
        n /= 10;
    }
    return DigitalRootSum(sum);
}

int main() 
{
    for(int i = 1; i <= sqrt(MAX); i++)
    {       
        for(int j = i; i * j <= MAX; j++)    
        {
            if(i == 1)
            {
                MDRS[j] = DigitalRootSum(j);                
                continue;
            }            
            MDRS[i * j] = max(MDRS[i*j], MDRS[i] + MDRS[j]);            
        }
    }  
    for(int i = 2; i <= MAX; i++)
    {
        ans[i] = ans[i-1] + MDRS[i];
    }
    
    int q;
    cin >> q;
    
    while(q--)
    {
        int n;
        cin >> n;
        cout << ans[n] << "\n";
    } 
    return 0;
}

