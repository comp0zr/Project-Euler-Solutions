#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

map<string, int> nameVals;
map<string, int> namePos;

int main() 
{
    int n;
    cin >> n;

    vector<string> names(n);
    
    for(int i=0; i<n; i++)
    {
        string name;
        cin >> name;

        names[i] = name;
            
        for(auto c : name)
        {
            int worth = (int)c - 64;
            nameVals[name] += worth;
        }                
    }
    sort(names.begin(), names.end());
   
    for(int i=0; i<n; i++)
    {
        namePos[names[i]] = i+1;
    }
    
    int q;
    cin >> q;
    
    while(q--)
    {
        string query;
        cin >> query;
                
        cout << nameVals[query] * namePos[query] << endl;
    }
    return 0;
}
