#include <bits/stdc++.h>
using namespace std;

vector<int> hashVals;
vector<pair<long, long>> M;
vector<bool> vis, S;

bool Solve(vector<int> &A, int i, long sum, int length, long indexSum = 0)
{ 
    vis[indexSum] = 1;
             
    if(length > 0)
    {
        if(length > 1 && sum < M[length-1].second)
        {
            return false;
        }
        if(S[sum])
        {
            return false;
        } 
        S[sum] = 1;
        M[length].first = min(M[length].first, sum);
        M[length].second = max(M[length].second, sum);            
    }
    if(i == A.size()) 
    {
        return true;
    }       
    bool res = true;
    
    for(int j=i+1; j<A.size(); j++)
    {
        if(vis[indexSum + (hashVals[j] * (length + 1))]) continue;
        
        res = min(res, Solve(A, j, sum + A[j], length + 1, indexSum + (hashVals[j] * (length + 1))));
        
        if(!res) return res;
    }
    if(length == 0) 
    {
        res = min(res, Solve(A, i+1, 0, 0, 0));
    }    
    return res;
}

int main() 
{       
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    hashVals = vector<int>(101, 0);    
    
    for(int i=0; i<=100; i++)
    {
        hashVals[i] = (i+1) * (rand() % 11587);
    }
    
    int t;
    cin >> t;        
    
    while(t--)
    {
        int n;
        cin >> n;        
                
        vector<int> A(n);
        
        for(int i=0; i<n; i++)
        {
            cin >> A[i];
        }
        if(n == 1)
        {
            cout << "NO\n";
            continue;
        }        
        sort(A.begin(), A.end());
        M = vector<pair<long, long>>(n+1, {1e11, -1e11});
        S = vector<bool>(1000000100, 0);
        vis = vector<bool>(1000000100, 0);
        
        bool special = Solve(A, -1, 0, 0);
        
        if(special) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
