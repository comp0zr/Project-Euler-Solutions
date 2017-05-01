#include <bits/stdc++.h>
using namespace std;

int main() 
{    
    vector<int> lowest(1050, 0);
    
    lowest[0] = 1;
    lowest[1] = 3;
    
    int triangle = 0, last = 2;
       
    for(int i=1; triangle <= 236215980; i++)
    {
        triangle += i;                
        
        int end = triangle/2;
        int divisors = 2;
                
        for(int j=2; j<end; j++)
        {
            if(triangle % j == 0)
            {                
                end = triangle/j;
                
                if(j == end)
                {
                    divisors++;
                    break;
                }
                divisors += 2;
            }
        }
        
        bool add = 0;
        int j = last;
        
        for( ; j <= divisors-1; )
        {
            if(!add)
            {
                if(lowest[j] == 0)
                {
                    add = true;     
                    continue;
                }                    
            }
            else
            {
                if(lowest[j] != 0) break;                
                
                lowest[j] = triangle;
            }        
            j++;
        }
        last = j;
    }
    
    int t;
    cin >> t;
    
    while(t--)
    {
        int n;
        cin >> n;
        
        if(n > 767) cout << 842161320 << endl;
        else cout << lowest[n] << endl;        
    }
    return 0;
}
