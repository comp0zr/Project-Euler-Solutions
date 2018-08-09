#include <bits/stdc++.h>
using namespace std;

string valid = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789();:,.\'?-! ";

void Increment(string &key)
{
    for(int i=2; i>=0; i--)
    {
        if(key[i] < 'z')
        {
            key[i]++;
            break;
        }
        else key[i] = 'a';
    }
}

int main() 
{
    string key = "abc";
    
    int n;
    cin >> n;
    
    vector<int> nums(n);
    
    int XOR, index = 0;
    
    string s = "";
    
    for(int i=0; i<n; i++)
    {
        cin >> nums[i];
    }
        
    key = "aaa";
    
    for(int i=0; i<n; )
    {
        XOR = (int)key[index];
        
        for(auto j : valid)
        {
            int x = (int)j ^ XOR;
            
            if(x == nums[i]) 
            {
                i++;
                index = (index == 2) ? 0 : index + 1;
                break;
                
            }
            else if(j == ' ')
            {
                i = 0;
                index = 0;
                Increment(key);
            }
        }
    }
    cout << key << endl; 
    return 0;
}
