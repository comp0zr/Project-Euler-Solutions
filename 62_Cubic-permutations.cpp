#include <bits/stdc++.h>
using namespace std;


int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    unsigned long long n, k;
    cin >> n >> k;
    
    int MAX = 1000000;
    map<vector<int>, vector<pair<long long, long long>>> M;
    
    for(long long i=1; i<=n; i++)
    {
        long long cube = (i * i * i);
        long long temp = cube;
        vector<int> digits(10, 0);
        
        while(temp)
        {
            digits[temp % 10]++;
            temp /= 10;
        }        
        M[digits].push_back({i, cube});
    }
    set<long long> ans;
    
    for(auto it : M)
    {
        vector<int> digits = it.first;
        
        if(M[digits].size() == k)
        {            
            for(auto x : M[digits])
            {
                if(x.first < n)
                {
                    ans.insert(x.second);
                    break;
                }
            }
        }
    }
    for(auto it : ans)
    {
        cout << it << endl;
    }
    return 0;
}

