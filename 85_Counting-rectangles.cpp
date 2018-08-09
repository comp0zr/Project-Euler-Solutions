#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;

int MAX = 2000;

int main() 
{
    vector<int> area(5000010, -1); 
        
    for(int H = 1; H <= MAX; H++)
    {
        for(int W = (H == 1) ? 2 : H; W <= MAX; W++)
        {
            ULL rectangles = 0;
            
            for(int i=1; i <= H; i++)
            {
                for(int j=1; j <= W; j++)
                {
                    ULL times = ((H - i) + 1) * ((W - j) + 1);                    
                    rectangles += times;
                }
            }
            if(rectangles > 5000000) break;
            
            if(rectangles < area.size())
            {
                if(H * W > area[rectangles])
                {
                    area[rectangles] = H * W;
                }
            }            
        }
    }
    
    int t;
    cin >> t;
    
    while(t--)
    {
        int N;
        cin >> N;
        
        int best = 0;
        bool found = 0;
        
        if(area[N] != -1)
        {
            cout << area[N] << "\n";
            continue;
        }
              
        for(int i = N, j = N; i >= 1 && j <= 5000000; i--, j++)
        {
            if(area[i] != -1)
            {                
                best = max(best, area[i]);                
                found = 1;
            }            
            if(area[j] != -1)
            {
                best = max(best, area[j]);                
                found = 1;
            }
            if(found) break;
        }
        cout << best << "\n";                
    }    
    return 0;
}
