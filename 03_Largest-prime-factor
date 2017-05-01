#include <bits/stdc++.h>
using namespace std;

long long FindPrime(long long x)
{    
    for(int i=3; i<=sqrt(x); i+=2)
    {
        if(x % i == 0)
        {            
            x /= i;
            i = 1;
            continue;
        }
    }
    return max(x, (long long)2);
}


int main() 
{
    int t;
    cin >> t;
    
    while(t--)
    {
        long long int n;
        cin >> n;

        while(n >= 1)
        {
            if(n == 1)
            {
                cout << 2 << endl;
                break;
            }
            if(n % 2 == 0)
            {
                n /= 2;
                continue;
            }
            cout << FindPrime(n) << endl;
            break;
        }
    }
    return 0;
}
