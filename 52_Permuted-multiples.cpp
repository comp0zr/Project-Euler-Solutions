#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{
    int n, k;
    cin >> n >> k;
    
    for(int i = 12874; i <= n; i++)
    {
        int num = i;
        vector<int> seq = {num};
        string compare = to_string(i);
        sort(compare.begin(), compare.end());
        
        for(int j=2; j<=k; j++)
        {                    
            num += i;          
                                
            string s = to_string(num);
            sort(s.begin(), s.end());

            if(s != compare) break;
            
            seq.push_back(num);            
            
            if(j == k)
            {
                for(auto it : seq) 
                {
                    cout << it << ' ';
                }
                cout << endl;
                break;
            }
        }
    }    
    return 0;
}
