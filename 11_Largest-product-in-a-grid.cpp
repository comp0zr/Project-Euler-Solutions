#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main()
{
    vector< vector<int> > grid(20,vector<int>(20));
    for(int grid_i = 0;grid_i < 20;grid_i++)
    {
       for(int grid_j = 0;grid_j < 20;grid_j++) cin >> grid[grid_i][grid_j];       
    }
    
    vector<vector<int>> series; 
    int maxSum = -99999;
    long long int ans;
    
    for(int i=0; i<20; i++)
    {        
        int xSum=0, ySum=0, d1Sum=0, d2Sum=0;
        for(int j=0; j<20; j++)
        {
            if(j <= 16) 
            {
                xSum  = grid[i][j] + grid[i][j+1] + grid[i][j+2] + grid[i][j+3];            
                ySum  = grid[j][i] + grid[j+1][i] + grid[j+2][i] + grid[j+3][i];
            }
            if(i <= 16 && j <= 16) 
            {
                d1Sum = grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2] + grid[i+3][j+3];
                d2Sum = grid[i+3][j] + grid[i+2][j+1] + grid[i+1][j+2] + grid[i][j+3];
            }

            vector<int> comp = {xSum, ySum, d1Sum, d2Sum};
            int index = max_element(comp.begin(), comp.end())-comp.begin();           
            
            if(comp[index] > maxSum)
            {                
                if(index == 0) ans = grid[i][j] * grid[i][j+1] * grid[i][j+2] * grid[i][j+3];
                else if(index==1) ans = grid[j][i] * grid[j+1][i] * grid[j+2][i] * grid[j+3][i];
                else if(index==2) ans = grid[i][j] * grid[i+1][j+1] * grid[i+2][j+2] * grid[i+3][j+3];
                else if(index==3) ans = grid[i+3][j] * grid[i+2][j+1] * grid[i+1][j+2] * grid[i][j+3];

                maxSum = comp[index];
            }                       
        }
    }
    cout<<ans<<endl;
    
    return 0;
}
