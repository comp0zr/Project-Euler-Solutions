#include <bits/stdc++.h>
using namespace std;

int main() 
{
    long long int n, k;    
    cin >> n >> k;
        
    deque<unsigned long long> nums;
    set<unsigned long long> S, ans;
    
    for(long long int i=1; i<=n+k; i++)
    {                
        unsigned long long term = (i * ((3*i)-1))/2;

        if(nums.size() > k)
        {
            unsigned long long subtract = term - nums[nums.size()-k];

            if(S.count(subtract))
            {
                ans.insert(term);
            }
        }
        nums.push_back(term);
        S.insert(term);        
    }
    for(int i=0; i<nums.size()-k; i++)
    {
        if(S.count(nums[i] + nums[i+k])) 
        {
            ans.insert(nums[i+k]);
        }
    }    
    for(auto it : ans) cout << it << endl;   
    return 0;
}

