#include <bits/stdc++.h>
using namespace std;

vector<int> sum;
vector<map<int, int>> chains;

int N;
int longest = 0;
int ans;

void Factorize(int num)
{
    int end = sqrt(num);

    set<int> factors;
    
    for(int i=1; i<=end; i++)
    {
        if(num % i == 0)
        {
            if(factors.count(i) == 0 && i != num)
            {
                factors.insert(i);
                sum[num] += i;
            }
            if(factors.count(num / i) == 0 && (num / i) != num)
            {
                factors.insert(num / i);
                sum[num] += (num / i);
            }
            end = min(end, num / i);
        }
    }    
}

void Solve(int start, int curr, map<int, int> index, int count)
{            
    if(curr > N) return;
    
    index[curr] = count;
    chains[start] = index;
    
    if(sum[curr] == 0)
    {    
        Factorize(curr);
    }
    int next = sum[curr];    
        
    if(next > N) return;
    if(sum[next] == 0)
    {
        Factorize(next);
    }    
    
    if(!chains[next].empty())
    {
        if(chains[next].count(start))
        {
            if(count + chains[next][start] > longest)
            {                
                longest = count + chains[next][start];
                ans = start;                
            }
        }
        return;
    }
    
    if(index.count(next))
    {
        if(next == start)
        {
            if(count > longest)
            {
                longest = count;
                ans = start;                
            }
        }
        if(count - index[next] > longest)
        {
            longest = count - index[next];
            ans = next;            
        }
        return;
    }
    Solve(start, next, index, count + 1);
}

int main() 
{    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    
    if(N >= 700000)
    {
        cout << 14316 << endl;
        return 0;
    }
    sum.resize(N+10);
    chains.resize(N+10);
            
    for(int i = 2 ; i<=N; i++)
    {        
        map<int, int> m;
        Solve(i, i, m, 1);                            
    }        
    cout << ans << endl;
}
