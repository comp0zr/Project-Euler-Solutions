#include<bits/stdc++.h>
using namespace std;

set<string> ans;

int N, S;
int limit;

void Solve(vector<vector<int>> ring, vector<bool> used, int i)
{
    if(i == N-1)
    {
        int a = (S - ring[i][1]) - ring[i][2];
        
        if(a < 1 || a >= limit || used[a]) return;
        
        ring[i][0] = a;
        string res = "";
        
        for(int j=0; j<N; j++)
        {
            if(ring[j][0] < ring[0][0]) return;
            
            for(auto k : ring[j]) res += to_string(k);
        }
        ans.insert(res);
        return;
    }  
    
    for(int j = (i > 0) ? ring[0][0] + 1 : 1; j < limit; j++)
    {
        int a = (S - ring[i][1]) - j;
                
        if(a < 1) break;
        if(a >= limit || a == j) continue;
        if(used[j] || used[a]) continue;
        
        vector<vector<int>> next = ring;
        vector<bool> used_temp = used;
        
        used_temp[j] = 1;
        used_temp[a] = 1;
        next[i][0] = j;
        next[i][2] = a;
        
        if(i < N-1) next[i+1][1] = a;
        
        Solve(next, used_temp, i+1);
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> S;
    limit = N*2+1;
    
    for(int i=1; i < limit; i++)
    {
        vector<vector<int>> ring(N, vector<int>(3, -1));
        vector<bool> used(limit, 0);
        
        ring[0][1] = i;
        ring[N-1][2] = i;
        used[i] = 1;
        
        Solve(ring, used, 0);
    }
    
    string result = "";
    
    for(auto it : ans)
    {
        result += it + "\n";
    }
    cout << result;
    return 0;
}
