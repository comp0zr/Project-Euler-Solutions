#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

map<pair<int, int>, int> memo;
vector<vector<int>> pyramid;
long long int maxSum = -1;

int slide(int row, int index)
{     
    if(row == pyramid.size())
    {
        return 0;
    }
    if(memo.count({row, index}) == 0)
    {
        memo[{row, index}] = pyramid[row][index] + max(slide(row+1, index), slide(row+1, index+1));
    }
    return memo[{row, index}];
}

int main() 
{
    int t, n;
    cin>>t;
    
    while(t--)
    {
        cin>>n;    
        pyramid.resize(n);
        
        for(int i=0; i<n; i++) 
        {
            pyramid[i].resize(i+1);
            for(int j=0; j<i+1; j++) cin>>pyramid[i][j];
        }
        cout << slide(0, 0) << endl;
        memo.clear();
    }
    return 0;
}
