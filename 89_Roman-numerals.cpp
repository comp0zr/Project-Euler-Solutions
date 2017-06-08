#include <bits/stdc++.h>
using namespace std;

map<char, int> roman =
{
    { 'I', 1    },
    { 'V', 5    },
    { 'X', 10   },
    { 'L', 50   },
    { 'C', 100  },
    { 'D', 500  },
    { 'M', 1000 }    
};

map<string, string> combinations =
{
    { "IIII",  "IV" },
    { "VIV",   "IX" },
    { "XXXX",  "XL" },
    { "LXL",   "XC" },        
    { "CCCC",  "CD" },
    { "DCD",   "CM" }
};

int main() 
{
    int t = 1000;
    cin >> t;
        
    while(t--)
    {
        string number;
        cin >> number;
        
        int total = 0;
        
        for(auto d : number)
        {
            total += roman[d];
        }
        
        string digits = "MDCLXVI";
        string ans = "";
        
        while(total != 0)
        {
            for(auto d : digits)
            {
                if(roman[d] <= total)
                {
                    total -= roman[d];
                    ans += d;
                    break;
                }
            }
        }        
        
        bool invalid = true;
        
        while(invalid)
        {
            invalid = false;
            
            for(auto sub : combinations)
            {
                if(ans.find(sub.first) != string::npos)
                {
                    string a = sub.first,
                           b = sub.second;
                    
                    ans.replace(ans.find(a), a.length(), b);
                    invalid = true;
                }
            }
        }
        cout << ans << endl;               
    }
    return 0;
}
