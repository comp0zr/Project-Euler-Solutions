#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{
    vector<int> abundant;
    vector<int> divisorSums(100010, 1);
    bool abundantSums[28130];
    
    for(int i=2; i<=sqrt(28123); i++)
    {
        for(int j=i; i*j <= 28123; j++)
        {            
            int prod = i*j;
            divisorSums[prod] += (i == j) ? i : i + j;
            
            if(divisorSums[prod] > prod) 
            {                
                abundant.push_back(prod);
                divisorSums[prod] = -999999;
            }
        }
    }
    sort(abundant.begin(), abundant.end());
    
    for(int i=0; i<abundant.size(); i++)
    {
        if(abundant[i] >= 14062) break;
        
        for(int j=i; j<abundant.size(); j++)
        {
            int sum = abundant[i] + abundant[j];
            
            if(sum > 28123) break;      
            abundantSums[sum] = true;
        }
    }
    
    int t;
    cin >> t;
    
    while(t--)
    {
        int n;
        cin >> n;
        
        if(n > 28123 || abundantSums[n] == true) cout << "YES" << endl;
        else cout << "NO" << endl;
    }  
    return 0;
}
