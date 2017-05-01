#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool IsPrime(int n)
{
    for(int i=2; i<=sqrt(n); )
    {
        if(n % i == 0) return false;
        
        i += (i==2) ? 1 : 2;
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    
    while(t--)
    {
        long long int n, ans=1;
        cin>>n;
       
        for(long long int i=2; i<=n; )
        {
            if(IsPrime(i))
            {
                long long int prod = pow(i, 1);
                
                for(long long int j=2; pow(i, j) <= n; j++)
                {
                    prod = pow(i, j);                    
                }
                ans *= prod;
            }
            i += (i==2) ? 1 : 2;
        }
        cout << ans << endl;        
    }
    return 0;
}
