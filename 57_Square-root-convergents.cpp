#include <bits/stdc++.h>
using namespace std;

deque<short> Add(deque<short> a, deque<short> b)
{
    deque<short> res;    
    
    if(a.size() < b.size()) swap(a, b);
    
    short carry = 0;
    
    while(!a.empty())
    {
        short sum = a.back() + ((!b.empty()) ? b.back() : 0) + carry;
        
        carry = sum / 10;
        res.push_front(sum % 10);
        a.pop_back();

        if(!b.empty()) b.pop_back();
    }
    while(carry) 
    {
        res.push_front(carry);
        carry /= 10;
    }
    return res;
}

bool DB = false;

int main() 
{
    int n;
    cin >> n;
        
    deque<short> N = {1}, D = {2};
    
    for(int i=1; i<=n; i++)
    {        
        if(Add(N, D).size() > D.size())
        {
            cout << i << endl;
        }
        
        deque<short> next_n = Add(D, D);        
        deque<short> next_d = D;
                
        next_n = Add(next_n, N);
        
        N = next_n;
        D = next_d;        
        swap(N, D);
    }        
    return 0;
}
