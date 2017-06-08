#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int primes[] = {2, 3, 5, 7, 11, 13, 17};

int main() 
{
    int n;
    cin >> n;
    
    unsigned long long ans = 0;
    
    string s = string("0123456789").substr(0, n+1);

    do
    {
        int index = 0;
        
        for(int i=1; i+2 < s.size(); i++)
        {
            string part = s.substr(i, 3);
            
            if(stoi(part) % primes[index] != 0) break;            
            else if(i+2 == s.size()-1) ans += stoull(s);
            
            index++;
        }        
    }
    while(next_permutation(s.begin(), s.end()));

    cout << ans << endl;
    return 0;
}
