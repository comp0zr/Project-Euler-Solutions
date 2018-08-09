#include <bits/stdc++.h>
using namespace std;

deque<short> Add(deque<short> a, deque<short> b)
{
    deque<short> res;
        
    if(a.size() < b.size()) swap(a, b);
    short carry = 0;
    
    while(!a.empty() && !b.empty())
    {
        short sum = a.back() + b.back() + carry;
        
        carry = sum / 10;
        res.push_front(sum % 10);
        a.pop_back();
        b.pop_back();
    }
    while(!a.empty())
    {
        short sum = a.back() + carry;
        carry = sum / 10;
        
        res.push_front(sum % 10);
        a.pop_back();
    }
    if(carry)
    {
        res.push_front(carry);
    }
    return res;
}

deque<short> Multiply(deque<short> a, deque<short> b)
{
    deque<short> ans;
    
    if(a.size() < b.size()) swap(a, b);
    
    int index = 0;
    short carry = 0;
    
    while(!b.empty())
    {
        deque<short> next(index, 0);
        short num = b.back();
        b.pop_back();
        
        for(int i=a.size()-1; i>=0; i--)
        {
            short prod = (a[i] * num) + carry;
            
            carry = prod / 10;
            
            next.push_front(prod % 10);
        }
        while(carry)
        {
            next.push_front(carry);
            carry /= 10;
        }
        if(index == 0)
        {
            ans = next;
            index++;
            continue;
        }
        ans = Add(ans, next);
        index++;
    }
    return ans;
}

int main() 
{
    int N;
    cin >> N;
    
    
    for(int i=2; i<=100; i++)
    {
        deque<short> A, B;
        
        string s = to_string(i);
        
        for(auto it : s) A.push_back(it-'0');
        B = A;
        
        for(int j=2; j<=N; j++)
        {
            deque<short> next = Multiply(A, B);
            A = next;
        }
        if(A.size() > N) break;
        if(A.size() == N)
        {
            for(auto it : A)
            {
                cout << it;
            }
            cout << endl;
        }
    }
    return 0;
}

