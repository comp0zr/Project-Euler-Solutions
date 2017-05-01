#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() 
{
    int t;
    cin >> t;
    
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        
        string num;
        cin >> num;
        
        int largest = 0;
        
        for(int i=0; i<=n-k; i++)
        {
            int prod = 1;
            
            for(int j=0; j<k; j++)
            {
                if(num[i+j] == '0')
                {
                    prod = 0;        
                    break;
                }
                prod *= num[i+j] - '0';
            }
            if(prod > largest) 
            {
                largest = prod;
            }
        }     
        cout << largest << endl;
    }
    return 0;
}
