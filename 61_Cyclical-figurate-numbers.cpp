#include <bits/stdc++.h>
using namespace std;

set<int> S;

set<int> Triangle()
{
    set<int> T;
    int n = 1;    
    int num = 1;
    
    while(num < 10000)
    {
        num = (n * (n+1))/2;
        if(num >= 1000 && num < 10000) 
        {          
            T.insert(num);            
        }
        n++;
    }
    return T;
}

set<int> Square()
{
    set<int> S;

    for(int i=2; ; i++)
    {
        int next = i*i;
        
        if(next >= 10000) break;
        
        if(next >= 1000 && next < 10000) 
        {
            S.insert(next);
        }
    }
    return S;
}

set<int> Pentagon()
{
    set<int> P;
    int n = 1;    
    int num = 1;
    
    while(num < 10000)
    {
        num = (n * ((3*n)-1))/2;
        n++;
        
        if(num >= 1000 && num < 10000) 
        {
            P.insert(num);
        }
    }
    return P;
}

set<int> Hexagon()
{
    set<int> H;
    int n = 1;    
    int num = 1;
    
    while(num < 10000)
    {
        num = n * ((2*n)-1);        
        if(num >= 1000 && num < 10000) 
        {
            H.insert(num);
        }
        n++;
    }
    return H;
}

set<int> Heptagon()
{
    set<int> H;
    int n = 1;    
    int num = 1;
    
    while(num < 10000)
    {
        num = n * ((5*n)-3)/2;
        if(num >= 1000 && num < 10000) 
        {        
            H.insert(num);
        }
        n++;
    }
    return H;
}

set<int> Octagon()
{
    set<int> O;
    int n = 1;    
    int num = 1;
    
    while(num < 10000)
    {
        num = n * ((3*n)-2);
        if(num >= 1000 && num < 10000)
        {
            O.insert(num);
        }
        n++;        
    }
    return O;
}

map<string, set<int>> F, B;
vector<set<int>> figurate;
set<int> ans;

int t;

void Solve(int count, set<int> vis, vector<int> nums, int prev)
{
    string back;

    if(nums.size() == t)
    {
        string a = to_string(nums.front());
        string b = to_string(nums.back());
        
        if(a.substr(0, 2) != b.substr(2)) return;
        
        int sum = 0;
        
        set<int> used(nums.begin(), nums.end());
        
        if(used.size() < nums.size()) return;
        
        for(auto it : nums)
        {         
            sum += it;
        }
        cerr << endl;
        ans.insert(sum);
        return;
    }
    if(count == 0)
    {
        for(auto it : S)
        {
            nums.push_back(it);
            
            for(int i=0; i<figurate.size(); i++)
            {
                if(figurate[i].count(it))
                {
                    vis.insert(i);
                    Solve(count+1, vis, nums, it);
                    vis.erase(i);
                }
            }            
            nums.pop_back();
        }
        return;
    }
    else
    {
        back = to_string(prev);
    }
    back = back.substr(2);                    
    
    for(auto front : F[back])
    {
        nums.push_back(front);

        for(int i=0; i<figurate.size(); i++)
        {
            if(figurate[i].count(front) && !vis.count(i))
            {
                vis.insert(i);
                Solve(count+1, vis, nums, front);
                vis.erase(i);
            }
        }                     
        nums.pop_back();     
    }
}

int main() 
{
    cin >> t;
    
    figurate.resize(t);
    vector<int> nums(t);
    
    for(int i=0; i<t; i++)
    {
        cin >> nums[i];    
              
        if(nums[i] == 3) figurate[i] = Triangle();                
        if(nums[i] == 4) figurate[i] = Square();
        if(nums[i] == 5) figurate[i] = Pentagon();
        if(nums[i] == 6) figurate[i] = Hexagon();
        if(nums[i] == 7) figurate[i] = Heptagon();
        if(nums[i] == 8) figurate[i] = Octagon();
    }   
    
    for(int i=0; i<figurate.size(); i++)
    {
        for(auto it : figurate[i])
        {
            S.insert(it);
            
            string s = to_string(it);
            
            F[s.substr(0, 2)].insert(it);
            B[s.substr(2)].insert(it);
        }
    }
    Solve(0, {}, vector<int>(), -1);
    for(auto it : ans)
    {
        cout << it << endl;
    }
    return 0;
}
