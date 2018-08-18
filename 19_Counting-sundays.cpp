#include <bits/stdc++.h>
#define LL (long long)
using namespace std;

int Zeller(long long day, long long month, long long year)
{
    if(month < 3) 
    {
        month += 12;
        year--;
    }
    
    long long K = year % 100;
    long long J = LL floor(year / 100);

    return LL(day + LL(floor((13 * (month + 1)) / 5)) + year + LL(floor(year / 4))
            - LL(floor(year / 100)) + LL(floor(year / 400))) % 7; 
}


int main() 
{    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while(t--)
    {
        long long Y1, M1, D1;
        long long Y2, M2, D2;
        
        cin >> Y1 >> M1 >> D1 >> Y2 >> M2 >> D2;                
        
        if((Y1 > Y2) || (Y1 == Y2 && M1 > M2) || (Y1 == Y2 && M1 == M2 && D1 > D2))
        {
            swap(Y1, Y2);
            swap(M1, M2);
            swap(D1, D2);
        }        
        
        if(D1 > 1) D1 = 1, M1++;
        if(M1 == 13) M1 = 1, Y1++;
        
        long long ans = 0;
        
        while(1)
        {
            int day = Zeller(D1, M1, Y1);
            
            if(day < 0) day += 7;
            if(day == 1) ans++;
            if(Y1 >= Y2 && M1 >= M2) break;
            
            if(M1 == 13) 
            {
                Y1++;
                M1 = 1;
            }
            M1++;                        
        }
        cout << ans << "\n";
    }
}
