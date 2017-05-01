#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


string Multiply(string s)
{
    int carry = 0;
    
    for(int i=s.length()-1; i>=0; i--)
    {
        int d = s[i]-'0';
        int prod = (d*2) + carry;
         
        s[i] = (prod % 10) + '0';
        carry = prod / 10;                
    }
    while(carry)
    {       
        string c = to_string(carry % 10);        
        s = c + s;
        carry /= 10;
    }
    return s;
}


int main() 
{
    int t;
    cin >> t;
    
    while(t--)
    {
        int n;
        cin >> n;
        
        string ans = "2";
        
        for(int i=1; i<n; i++)
        {
            ans = Multiply(ans);
        }
        unsigned int sum = 0;
        
        for(auto it : ans)
        {
            sum += it-'0';
        }   
        cout << sum << endl;
    }
    return 0;
}
