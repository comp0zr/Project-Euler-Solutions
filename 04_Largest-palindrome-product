#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


vector<int> GeneratePalindromes()
{
    set<int> palSet;
    int num = 101101, next;
    
    while(num <= 999999)
    {      
        for(int i=101; i<=999; i++)
        {
            if(num % i == 0 && to_string(num/i).length()==3) palSet.insert(num);
        }     
        string L = to_string(num).substr(0, 3), R;
        next = stoi(L) + 1;
        L = to_string(next);
        R = L;
        reverse(R.begin(), R.end());              
        num = stoi(L+R); 
    }
    vector<int> ret;
    copy(palSet.begin(), palSet.end(), back_inserter(ret));
    return ret;
}


int main()
{
    int t;
    cin >> t;
    
    vector<int> validPalindromes = GeneratePalindromes();
        
    while(t--)
    {        
        int n;
        cin>>n;
        
        auto it = find_if(validPalindromes.begin(), validPalindromes.end(), [=](int i) { return (i>=n); });
        cout<<*(--it)<<endl;
    }
    return 0;
}
