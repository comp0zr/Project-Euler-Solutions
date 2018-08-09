#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;

int MAX = 60000;

int main() 
{
    int t;
    cin >> t;

    vector<long long> pent;
    unordered_set<long long> nums;
    
    for(int i = 1; i < 10000; i++)
    {
        int p = i * (3*i-1) / 2;
        
        if(!nums.count(p)) 
        {
            pent.push_back(p);
            nums.insert(p);
        }                
        p = -i * (3*(-i)-1)/2;
        
        if(!nums.count(p))
        {
            pent.push_back(p);
            nums.insert(p);
        }        
    }
    sort(pent.begin(), pent.end());

    long long DP[60010] = {0};
    DP[0] = 1;
    
    for(int i = 1; i <= MAX; i++)
    {              
        bool add = 0;
        long long num = 0;
        long long p = 0;

        for(int j = 0; p <= i; j++)
        {                
            if(add) DP[i] = (DP[i] + num) % MOD;
            else DP[i] = (DP[i]) - num;

            if(DP[i] < 0) DP[i] += MOD;

            p = pent[j];
            num = DP[i - p] % MOD;

            if(j % 2 == 0) add = !add;
        }
        DP[i] = DP[i] % MOD;        
    }
    while(t--)
    {
        int n;
        cin >> n;
        
        cout << DP[n] % 1000000007 << endl;
    }
    return 0;
}

