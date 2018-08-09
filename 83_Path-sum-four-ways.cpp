#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, long long> Cell;

int N;

pair<int, int> dir[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<vector<long long>> grid;


long long Dijkstra()
{
    priority_queue<Cell, vector<Cell>, greater<Cell>> Q;                    
    
    vector<long long> cost((N * N) + 1, 1e15);
    vector<pair<int, int>> M(N * N + 1);
    
    cost[0] = 0;
    
    long long index = 0;
    
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {            
            M[index] = {i, j};
            index++;                        
        }
    }    
    Q.push({grid[0][0], 0});
    
    while(!Q.empty())
    {
        long long cell = Q.top().second;
        long long currCost = Q.top().first;         
     
        if(cell == N * N - 1) return currCost;
        
        Q.pop();
        
        int y = M[cell].first;
        int x = M[cell].second;

        for(auto d : dir)
        {
            int next_y = y + d.first;
            int next_x = x + d.second;
            
            if(next_y < 0 || next_x < 0 || next_y >= N || next_x >= N) continue;
            
            long long nextCost = currCost + grid[next_y][next_x];
            long long next_index = (next_y * N) + next_x;
            
            if(nextCost < cost[next_index])
            {
                cost[next_index] = nextCost;
                Q.push({nextCost, next_index});
            }
        }
    }
    return cost[N * N - 1];
}

int main() 
{
    cin >> N;
    grid.resize(N, vector<long long>(N));    
    
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin >> grid[i][j];
        }
    }
    long long ans = Dijkstra();

    cout << ans;
    return 0;
}
