#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <deque>
#include <stack>
using namespace std;

int n, m;
vector<long long> *memo;
map<pair<int, int>, long long> answers;
long long ans = -1;


long int Path(int i, int j)
{
    if(i == n && j == m)
    {
        return 0;
    }    
 
    if(memo[i][j] != -1)
    {
        return memo[i][j] % 1000000007;
    }

    long long result = -1;

    if(i < n) 
    {
        result += (1 + Path(i + 1, j)) % 1000000007;
    }
    if(j < m) 
    {
        result += (1 + Path(i, j + 1)) % 1000000007;
    }
    memo[i][j] = result % 1000000007;    
    return result % 1000000007; 
}



int main() 
{
    int t;
    cin >> t;
    
    while(t--)
    {
        cin >> n >> m;
        
        if(answers.count({n, m}) != 0)
        {
            cout << answers[{n, m}] << endl;
            continue;
        }
        
        memo = new vector<long long>[n+10];
        vector<long long> v(m+10, -1);
        fill(memo, memo + n + 10, v);
        
        ans = Path(0, 0);
        cout << (ans+1) % 1000000007 << endl;
        
        answers[{n, m}] = (ans+1) % 1000000007;
        delete[] memo;               
    }
    return 0;
}
