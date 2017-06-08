#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define ULL unsigned long long

int n;
vector<vector<ULL>> matrix;
ULL memo[1010][1010]={0};

ULL MinPath(int i, int j)
{
    if(i==n-1 && j==n-1)
    {
        return 0;
    }
 
    if(memo[i][j] != 0) return memo[i][j];
    
    ULL result_x = 1e15;
    ULL result_y = result_x;
    
    if(i < n-1) result_y = matrix[i][j] + MinPath(i+1, j);
    if(j < n-1) result_x = matrix[i][j] + MinPath(i, j+1);
    memo[i][j] = min(result_y, result_x);
    
    return memo[i][j];
}



int main() 
{
    cin >> n;
    matrix.resize(n);
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            int num;
            cin >> num;
            matrix[i].push_back(num);
        }
    }
    ULL ans = MinPath(0, 0);
    cout << ans + matrix[n-1][n-1] << endl;
    return 0;
}
