#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> adj;
vector<vector<int>> weight;

int FindNext(set<int> &unvisited, vector<int> &cheapest, vector<int> &edge)
{
    int mn = 1e9;
    int next = -1;
    
    for(auto node : unvisited)
    {
        if(cheapest[node] < mn)
        {
            mn = cheapest[node];
            next = node;
        }
    }
    return next;
}

int Prim()
{
    set<int> visited, unvisited;
    vector<int> cheapest(N+1, 1e9);
    vector<int> edge(N+1, -1);
    
    for(int i=1; i<=N; i++)
    {
        unvisited.insert(i);
    }    
    cheapest[1] = 0;
    
    int total = 0;
    
    while(!unvisited.empty())
    {        
        int node = FindNext(unvisited, cheapest, edge);
        
        total += cheapest[node];
        unvisited.erase(node);
        visited.insert(node);
        
        if(edge[node] != -1)
        {
            unvisited.erase(edge[node]);
            visited.insert(edge[node]);
        }       
        for(auto it : adj[node])
        {
            if(unvisited.count(it))
            {
                if(weight[node][it] < cheapest[it])
                {
                    cheapest[it] = weight[node][it];
                    edge[it] = node;
                }
            }
        }
    }
    return total;
}

int main()
{
    cin >> N >> M;
    
    weight.resize(N+1, vector<int>(N+1, 0));        
    adj.resize(N+1);    
    
    for(int i=0; i<M; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
        weight[u][v] = w;
        weight[v][u] = w;
    }    
    int ans = Prim();
    
    cout << ans;
    return 0;
}

