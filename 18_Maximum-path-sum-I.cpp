#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<int>> pyramid;
long long int maxSum = -1;

void slide(int row, int index, long long sum)
{
    if(sum > maxSum) maxSum = sum;
    if(row == pyramid.size()) return;
    
    slide(row+1, index, sum+pyramid[row][index]);
    slide(row+1, index+1, sum+pyramid[row][index]);
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
        slide(0, 0, 0);
        cout << maxSum << endl;      
        maxSum = -1;
    }
    return 0;
}
