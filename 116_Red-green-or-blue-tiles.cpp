#include <bits/stdc++.h>
using namespace std;
typedef long long ULL;
typedef vector<vector<ULL>> Matrix;

const ULL MOD = 1000000007;

vector<Matrix> T = 
{
    {{1, 1}, 
     {1, 0}},
    
    {{1, 1, 0}, 
     {0, 0, 1}, 
     {1, 0, 0}},
    
    {{1, 1, 0, 0}, 
     {0, 0, 1, 0}, 
     {0, 0, 0, 1}, 
     {1, 0, 0, 0}}
};

void MatrixMultiply(Matrix &a, Matrix &b)
{
    Matrix prod(a.size(), vector<ULL>(a.size(), 0));
    
    for(int i = 0; i < a.size(); i++)
    {
        for(int j = 0; j < a.size(); j++)
        {            
            for(int k = 0; k < a.size(); k++)
            {                
                prod[i][j] = (prod[i][j] + (a[i][k] * b[k][j]) % MOD) % MOD;
            }
        }
    }
    for(int i = 0; i < a.size(); i++)
    {
        for(int j = 0; j < a.size(); j++)
        {
            if(prod[i][j] < 0) prod[i][j] += MOD;
            
            a[i][j] = prod[i][j];
        }
    }
    return;
}

void MatrixPower(Matrix &fib, ULL n)
{
    Matrix M = T[fib.size() - 2];
    
    if(n == 1) return;
    
    MatrixPower(fib, n / 2);
    MatrixMultiply(fib, fib);
    
    if(n % 2 != 0)
    {
        MatrixMultiply(fib, M);
    }
}

ULL Fibonacci(ULL n, int type)
{
    Matrix fib = T[type];
    MatrixPower(fib, n - 1);
    
    if(fib[0][0] < 0) fib[0][0] += MOD;
    
    return fib[0][0] - 1;
}

int main()
{
    int q;
    cin >> q;

    while(q--)
    {
        ULL n;
        cin >> n;        
        
        ULL R = Fibonacci(n + 1, 0) % MOD;
        ULL G = Fibonacci(n + 1, 1) % MOD;
        ULL B = Fibonacci(n + 1, 2) % MOD;                
        ULL res = (R + G + B) % MOD;
        
        if(res < 0) res += MOD;
        
        cout << res << "\n";
    }
    return 0;
}
