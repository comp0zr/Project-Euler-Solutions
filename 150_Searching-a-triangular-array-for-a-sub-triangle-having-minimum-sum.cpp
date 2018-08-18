#include <bits/stdc++.h>
using namespace std;

int N, K;

int main()
{
    cin >> N >> K;
    
    vector<vector<long long>> triangle(N+1);
    vector<vector<long long>> row_sums(N+1, {0});
    long long ans = 1e15;
    
    priority_queue<long long, vector<long long>, std::less<long long>> q;
    
    for(int i=1; i<=N; i++)
    {
        vector<long long> row(i+1);                
        
        for(int j=1; j<=i; j++)
        {
            cin >> row[j];                        
            row_sums[i].push_back(row_sums[i].back() + row[j]);
        }
        triangle[i] = row;
    }    
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=i; j++)
        {                        
            long long sum = 0;
            
            for(int size=0; i + size <= N && j + size <= i + size; size++)
            {                                
                sum += (row_sums[i + size][j + size] 
                     -  row_sums[i + size][j - 1]);
                                                
                if(q.size() < K || sum <= q.top())
                {
                    q.push(sum);                
                }
                if(q.size() > K) q.pop();                                
            }
        }
    }
    vector<long long> result;
    
    while(!q.empty())
    {
        result.push_back(q.top());
        q.pop();
    }
    sort(result.begin(), result.end());
    
    for(auto it : result) cout << it << endl;    
    return 0;
}
