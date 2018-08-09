#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int t;
    cin >> t;
    
    while(t--)
    {    
        int n;
        cin >> n;

        vector<unsigned long long> DP(n+1, 0);
        DP[0] = 1;
        
        for(int i=1; i<n; i++)
        {
            for(int j=i; j<=n; j++)
            {
                DP[j] += DP[j - i];
                DP[j] %= 1000000007;
            }
        }
        cout << DP[n] % 1000000007 << endl;
    }
    return 0;
}

