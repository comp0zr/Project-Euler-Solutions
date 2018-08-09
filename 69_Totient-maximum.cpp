#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int t;
    cin >> t;
    
    vector<long long> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
    vector<long long> queries(t), sorted;
    
    for(int i=0; i<t; i++)
    {
        cin >> queries[i];
    }
    sorted = queries;
    sort(sorted.begin(), sorted.end());
    
    unordered_map<long long, long long> ans;
    vector<long long> nums;
    
    long long num = 1;
    
    do
    {                                        
        num = num * primes[nums.size()];        
        nums.push_back(num);
    }    
    while(nums.size() < 15);
    
    nums.push_back(1e18);
    
    int index = 0;        
    long long last = 1;
    
    for(auto it : nums)
    {        
        while(index < t && it >= sorted[index])
        {
            ans[sorted[index]] = last;
            index++;
        }
        if(index == t) break;
        last = it;
    }
    for(auto n : queries)
    {
        cout << ans[n] << "\n";
    }
    return 0;
}
