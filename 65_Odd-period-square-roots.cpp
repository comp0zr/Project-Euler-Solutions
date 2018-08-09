#include <bits/stdc++.h>
using namespace std;

long ContinuedFraction(int n)
{   
    unsigned int m = 0, d = 1, a = floor(sqrt(n)), start = a;    
    long count = 0;
    
    while(a != 2 * start)
    {
        m = (d * a) - m;
        d = (n - (pow(m, 2))) / d;
        a = floor((start + m) / d);
        count++;
    }
    return count;
}

int main() 
{    
    int N;
    cin >> N;
    
    int isSquare[N + 1] = {0};
    
    for(int i=1; i * i <= N; i++)
    {
        isSquare[i * i] = 1;
    }
    
    int ans = 0;
        
    for(int i = 2; i <= N; i++)
    {
        if(isSquare[i]) continue;        
        
        if(ContinuedFraction(i) % 2) ans++;        
    }
    cout << ans;
    return 0;
}

