#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() 
{
    int t;
    cin >> t;
    
    while(t--)
    {
        unsigned long long int n;
        cin >> n;
        
        unsigned long long int sum1 = 0, sum2 = 0;
        
        for(int i=1; i<=n; i++)
        {
            sum1 += i;
            sum2 += i*i;
        }
        
        unsigned long long ans = abs((sum1*sum1) - sum2);
        cout << ans << endl;
    }
       
    return 0;
}
