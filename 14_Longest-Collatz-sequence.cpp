#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <map>
using namespace std;


int highest[5000010];
vector<unsigned long> *memo;


void Precomputation()
{
    memo = new vector<unsigned long>[5];   
    fill(memo, memo+5, vector<unsigned long>(10000000, 0));
    memset(highest, -1, 5000010);
    
    unsigned long maxCount = 0, highestIndex = 1;
    
    for(int i=1; i<=5000000; i++)
    {               
        if(memo[0][i] != 0)
        {            
            highest[i] = (int)highestIndex;        
            continue;
        }
        unsigned long index = (i%2==0) ? i/2 : (i*3)+1;
        unsigned long count = 1;   
        vector<unsigned long> temp;            

        while(index != 1)
        {          
            if(index < 50000000)
            {          
                int a = index / 10000000, 
                    b = index % 10000000;
                
                if(memo[a][b] != 0)
                {
                    count += memo[a][b];
                    break;
                }            
            }
            temp.push_back(index);
            count++;

            if(index % 2 == 0) index = index/2;
            else index = (index*3)+1;           
        }            
        memo[0][i] = count;

        if(count >= maxCount)
        {
            maxCount = count;
            highestIndex = i;
        }
        highest[i] = (int)highestIndex;

        for(int j=0; j<temp.size(); j++)
        {                
            count--;
            if(temp[j] < 50000000) 
            {
                memo[temp[j]/10000000][temp[j]%10000000] = count;
            }
        }
    }    
    delete[] memo;    
}


int main() 
{
    Precomputation();
    
    int t;
    cin >> t;
    
    while(t--)
    {
        int n;
        cin >> n;
        
        cout << highest[n] << endl;
    }    
    return 0;
}
