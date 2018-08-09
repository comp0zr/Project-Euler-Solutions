#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int t;
    cin >> t;
    
    while(t--)
    {
        long long n;
        cin >> n;

        unsigned long long L = 1, H = 1e10, M = 1;
        long long ans = 0;
        
        while(L <= H)
        {
            M = rint((L + H) / 2);
            
            unsigned long long term = ((long double)(M-1)/2) * (M);
                        
            if(term == n)
            {
                ans = M;
                break;
            }
            else if(term < n) L = M + 1;
            else H = M - 1;                       
        }        
        cout << ans-1 << endl;
    }
    return 0;
}
