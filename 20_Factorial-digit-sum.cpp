#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;


int Factorial(int n, deque<int> num)
{
    if(n == 1)
    {        
        int sum = 0;
        
        for(auto it : num)
        {
            sum += it;
        }        
        return sum;
    }
    
    int carry = 0;
    
    for(int i=num.size()-1; i >= 0; i--)
    {
        int prod = (num[i] * n) + carry;
        
        carry = prod / 10;
        num[i] = prod % 10;
    }
    while(carry)
    {
        num.push_front(carry % 10);
        carry /= 10;
    }
    return Factorial(n-1, num);
}


int main() 
{
    int t;
    cin >> t;
    
    while(t--)
    {
        int n;
        cin >> n;
        
        if(n == 0)
        {
            cout << 1 << endl;
            continue;
        }
        
        cout << Factorial(n, {1}) << endl;
    }        
    return 0;
}
