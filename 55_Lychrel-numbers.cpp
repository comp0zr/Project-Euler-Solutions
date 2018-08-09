#include <bits/stdc++.h>
using namespace std;

map<long long, int> counts;

int main() 
{
    int n;
    cin >> n;
    
    int maxCount = -1e5;
    long long ans;
    
    for(int i=1; i<n; i++)
    {       
        long long num = i;
        
        for(int j=0; j<59; j++)
        {
            long long temp = num, rev = 0;
            
            while(temp)
            {                
                if(temp != num) rev *= 10;

                rev += temp % 10;
                temp /= 10;                
            }            
            if(num == rev)
            {
                counts[num]++;
                
                if(counts[num] > maxCount)
                {
                    maxCount = counts[num];
                    ans = num;
                }
                break;
            }
            num += rev;
        }
    }
    cout << ans << ' ' << maxCount << endl;
    
    return 0;
}

