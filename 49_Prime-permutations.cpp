#include <bits/stdc++.h>
using namespace std;

vector<int> primes;
set<int> P;
vector<bool> sieve(1000000000);

map<string, set<int>> M;
set<string> digits;


void GetPrimes(int n, int k)
{
    int p = 2;   
    
    while(p < n)
    {
        if(!primes.empty() && primes.back() == p) return;
        primes.push_back(p);
        
        if(p > 1486)
        {
            string primeDigits = to_string(p);
            sort(primeDigits.begin(), primeDigits.end());
        
            M[primeDigits].insert(p);
            
            if(M[primeDigits].size() >= k-1)
            {
                digits.insert(primeDigits);
            }
        }
        for(int i=2; i*p < n; i++)
        {
            sieve[i * p] = true;
        }
        for(int j = p+1; j<n; j++)
        {
            if(sieve[j] == false)
            {
                p = j;                
                break;
            }
            else if(j == n-1)
            {
                return;
            }
        }        
    }               
}



int main() 
{
    int n, k;
    cin >> n >> k;

    GetPrimes(n * 10, k);
    
    set<pair<int, string>> ans;
    P = set<int>(primes.begin(), primes.end());
         
    for(auto it : digits)
    {
        if(*M[it].begin() >= n) continue;
        vector<int> permutations(M[it].begin(), M[it].end());
        
        map<int, set<int>> count;
        set<int> differences;
        
        for(int i=0; i<permutations.size(); i++)
        {            
            for(int j=permutations.size()-1; j>i; j--)
            {
                int diff = permutations[j] - permutations[i];
                count[diff].insert(permutations[i]);
                
                if(count[diff].size() == k-1) differences.insert(diff);
            }
        }
        
        for(auto diff : differences)
        {                
            for(auto first : count[diff])
            {           
                if(first >= n) break;

                int x = 1;
                int num = first;

                string part = to_string(num);

                while(x < k)
                {
                    num += diff;

                    if(P.count(num) == 0 || M[it].count(num) == 0) 
                    {
                        break;
                    }
                    part += to_string(num);
                    x++;
                }
                if(x == k) 
                {
                    ans.insert({first, part});
                }
            }
        }
    }
    
    for(auto it : ans)
    {       
        cout << it.second << endl;          
    }
    return 0;
}
