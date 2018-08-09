#include <bits/stdc++.h>
using namespace std;

int main() 
{        
    int t;
    cin >> t;            
        
    vector<unordered_set<char>> after(127), before(127);
    vector<string> b_str(127), a_str(127);
    set<char> characters;
    
    for(int i=0; i<t; i++)
    {
        string s;
        cin >> s;
        
        for(int j=0; j<3; j++)
        {            
            characters.insert(s[j]);
            
            for(int k=0; k<3; k++)
            {
                if(j == k) continue;
                
                if(k < j) 
                {
                    before[s[j]].insert(s[k]);
                    after[s[k]].insert(s[j]);
                }
                if(k > j) 
                {
                    after[s[j]].insert(s[k]);
                    before[s[k]].insert(s[j]);
                }
            }
        }
    }

    for(auto c : characters)    
    {                
        for(auto b : before[c])
        {
            for(auto a : after[c])
            {
                before[a].insert(b);
                after[b].insert(a);
                
                for(auto x : after[a])
                {
                    before[x].insert(c);
                    before[x].insert(b);
                    after[c].insert(x);
                    after[b].insert(x);
                }           
            }
        }
        if(before[c].count(c) || after[c].count(c)) 
        {
            cout << "SMTH WRONG";
            return 0;
        }
    }        
    
    vector<vector<int>> possible(127);
    vector<vector<char>> index(characters.size());
    
    for(auto c : characters)
    {        
        for(int i = before[c].size(); i < characters.size() - after[c].size(); i++)
        {
            index[i].push_back(c);
        }
        for(auto it : before[c])
        {
            b_str[c].push_back(it);
        }
        for(auto it : after[c])
        {
            a_str[c].push_back(it);
        }
    }    
    bool used[127] = {0};
    string ans;
    
    for(int i=0; i<characters.size(); i++)
    {
        sort(index[i].begin(), index[i].end());
        
        for(auto it : index[i])
        {
            if(b_str[it].find_first_not_of(ans) != string::npos)
            {
                continue;
            }
            if(!used[it])
            {
                used[it] = 1;
                ans += it;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}
