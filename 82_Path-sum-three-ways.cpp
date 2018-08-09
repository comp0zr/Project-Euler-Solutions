#include <bits/stdc++.h>
using namespace std;

int n;
long long ans;

int main() 
{
    cin >> n;
    
    vector<vector<long long>> M(n, vector<long long>(n));
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> M[i][j];        
        }        
    }    
    vector<long long> dp(n+1, 1e18);
            
    for(int i=0; i < n; i++)
    {
        dp[i] = M[i][n-1];     
    }    
    
    for(int i=n-2; i>=0; i--)
    {
        dp[0] += M[0][i];
        
        for(int j=1; j<n; j++)   
        {
            dp[j] = min(dp[j] + M[j][i], dp[j-1] + M[j][i]);
        }
        for(int j=n-2; j>=0; j--)
        {
            dp[j] = min(dp[j], dp[j+1] + M[j][i]);
        }
    }
    ans = *min_element(dp.begin(), dp.end());
    cout << ans << endl;
    
    return 0;
}

