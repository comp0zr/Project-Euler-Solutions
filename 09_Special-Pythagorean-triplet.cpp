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
        int n;
        cin >> n;
        
        int c = (n/2)-1; 
        int largest = -1;
               
        while(c > 2)
        {            
            int b = c-1, a = n-c-b;                                
            int c_squared = c*c;
            
            while(b >= a)
            {                                   
                int prod = a*b*c;
                
                if(prod > largest)
                {                 
                    int sum = (a*a) + (b*b);                    
                    if(sum == c_squared) largest = prod;                       
                }
                b--;
                a = n-c-b; 
            }
            c--;
        }
        cout << largest << endl;        
    }    
    return 0;
}
