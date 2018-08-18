#include <bits/stdc++.h>
using namespace std;

long long MOD = 1000000007;

map<pair<int, int>, long long> memo;

long long Solve(int size, int N, vector<int> indices, vector<int> counts, long long c = 0)
{
    if(indices.size() == N)
    {        
        return (counts[0] > 0 && counts[1] > 0 && counts[10] > 0);        
    }    
    if(memo.count({size, c}))
    {
        return memo[{size, c}];
    }        
    if(counts[0] > 0 && counts[1] > 0 && counts[10] > 0)
    {
        long long add = 1;                
        
        for(int i=size; i<N; i++)
        {
            add = (add * 16) % MOD;
            add++;
        }
        return add;        
    }
    long long res = 0;    
    vector<int> next = {-1, 0, 1, 10};
    
    for(auto i : next)
    {
        if(size == 0 && i == 0) continue;
        
        indices.push_back(i);
        long long add = 1;
        
        if(i != -1) 
        {
            counts[i]++;                                    
            add = Solve(size + 1, N, indices, counts, (counts[i] == 1) ? c + 1 : c);
            counts[i]--;
        }
        else
        {                     
            add = Solve(size + 1, N, indices, counts, c) % MOD;
            add = (13 * add) % MOD;            
        }        
        res = (res + add) % MOD;        
        indices.pop_back();        
    }    
    memo[{size, c}] = res;
    return res;
}

int main() 
{
    int n;
    cin >> n;
    
    long long ans = Solve(0, n, {}, vector<int>(16, 0));
         
    cout << ans << endl;
    return 0; 
}
