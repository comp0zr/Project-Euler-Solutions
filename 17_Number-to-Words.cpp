#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

string denominations[5] = {"Thousand", "Million", "Billion", "Trillion", "Quadrillion" };
string tens[8] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
string teens[10] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
string ones[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};

int main() 
{
    int t;
    cin >> t;

    while(t--)
    {
        unsigned long long int n;
        cin>>n;
        
        if(n < 10) 
        {
            cout << ones[n] << endl;
            continue;
        }
        else if(n < 20)
        {
            cout << teens[n-10] << endl;   
            continue;
        }
        
        vector<int> parts;
        string num = to_string(n), p = "";
        int count = 1;
                
        for(int j=num.length()-1; j>=0; j--)
        { 
            p.insert(0, 1, num[j]);
            
            if(count==3 || j==0)
            {
                parts.push_back(stoi(p));
                p.clear();
                count=0;
            }
            count++;
        }
        reverse(parts.begin(), parts.end());        
        vector<string> ans(parts.size());
        
        for(int i=0; i<parts.size(); i++)
        {
            if(parts[i] == 0) continue;
            
            int num = parts[i];
            string p = to_string(parts[i]);            
            string part = "";
            
            cerr << num << endl;
            
            if(num >= 100) 
            {
                part += ones[p[0]-'0'] + " Hundred";
                num -= (100*(num/100));
                p = to_string(num);                
            }
            if(num >= 10)
            {
                if(!part.empty()) part += ' ';
                
                if(num >= 20)
                {
                    part += tens[p[0] - '0' -2];
                    num -= (10*(num/10));
                    p = to_string(num);
                }
                else
                {
                    part += teens[num%10];
                    num -= num;
                }                
            }
            if(num > 0)
            {
                if(!part.empty()) part += ' ';
                part += ones[num];                   
            }
            
            if(i < parts.size()-1 && parts[i] != 0) part += ' ' + denominations[parts.size()-i-2];      
            ans[i] = part;
        }
        
        stringstream ss;
        for(int i=0; i<ans.size(); i++)
        {
            if(ans[i].empty()) continue;
            else ss << ans[i];
            
            if(i<ans.size()-1) ss << ' ';
        }
        ss << '\n';
        cout << ss.str();
    }
    return 0;
}
