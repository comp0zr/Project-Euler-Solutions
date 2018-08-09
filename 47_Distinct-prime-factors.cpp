#include <bits/stdc++.h>
using namespace std;

vector<set<int>> M;

void Sieve(int n)
{
    vector<bool> sieve(2000010, false);
    int p = 2;
    sieve[2] = true;
    
    while(p <= n)
    {        
        for(int i=2; p*i <= n; i++)     
        {
            sieve[p*i] = true;
            M[p*i].insert(p);
        }
        while(p < sieve.size() && sieve[p]) p++;
        sieve[p] = true;        
    }
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    M.resize(2000001);
    Sieve(2000000);
    
    int n, k;
    cin >> n >> k;
        
    deque<int> ans;
        
    for(int i=14; i<n+k; i++)
    {        
        if(M[i].size() == k) 
        {
            ans.push_back(i);
            
            if(ans.size() == k)
            {
                cout << ans[0] << endl;
                ans.pop_front();
            }
        }
        else ans.clear();             
    }
    return 0;
}
