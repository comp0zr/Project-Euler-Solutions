#include <bits/stdc++.h>
using namespace std;

long long maxSum = -1e9;

deque<int> Multiply(deque<int> a, int b)
{
    deque<int> res;

    int carry = 0;
    long long sum = 0;
    
    for(int i=a.size()-1; i>=0; i--)
    {
        int prod = (a[i] * b) + carry;
        
        carry = prod / 10;
        res.push_front(prod % 10);
        sum += res.front();
    }
    while(carry)
    {
        res.push_front(carry % 10);
        sum += res.front();
        carry /= 10;
    }
    maxSum = max(maxSum, sum);
    return res;
}

int main() 
{
    int n;
    cin >> n;
    
    for(int i=4; i<n; i++)
    {                
        deque<int> a, power;

        for(auto it : to_string(i))
        {
            a.push_back(it - '0');
        }
        power = a;
        
        for(int j=1; j<n; j++)
        {
            power = Multiply(power, i);            
        }
    }
    cout << maxSum << endl;
    
    return 0;
}

