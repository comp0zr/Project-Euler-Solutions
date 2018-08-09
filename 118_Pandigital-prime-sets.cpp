#include <bits/stdc++.h>
#define SetBit(bits, x) bits |= 1 << x
#define TestBit(bits, x) ((bits & 1 << x) != 0)
#define ClearBit(bits, x) bits &= ~(1 << x)
using namespace std;

unordered_map<unsigned int, unsigned int> p_digits;
unordered_map<unsigned int, set<unsigned int>> M;
vector<set<unsigned int>> nums;
vector<char> sieve;
          
int MAX = 100000000;

void Sieve(unsigned int n)
{
    unsigned int limit = (n / 2) + 1;
    unsigned int p = 1;
    
    sieve.resize(limit, 1);
    sieve[0] = 0;
        
    while(p * p * 2 < limit)
    {
        if(sieve[p])
        {
            unsigned int curr = 3 * p + 1;
            
            for(unsigned int i = (3 * p) + 1; i < limit; i += (2 * p) + 1)
            {                        
                sieve[i] = 0;                
            }
        }
        p++;
    }
}

void GetDigits(unsigned int n)
{
    unsigned int temp = n;    
    bool digits[10] = {0};

    while(temp)
    {
        int d = temp % 10;
        
        if(d == 0 || digits[d]) return;
        
        digits[d] = 1;
        temp /= 10;
    }        
    unsigned int used = 0;
    
    for(unsigned int i=1; i<=9; i++)
    {
        if(digits[i]) SetBit(used, i);        
    }
    M[used].insert(n);
    p_digits[n] = used;
}

bool IsPrime(unsigned int n)
{
    if(n < 2) return 0;
    if(n < 4) return 1;
    if(n % 2 == 0 || n % 3 == 0) return 0;
    
    if(n >= sieve.size() * 2)
    {
        for(unsigned int i = 5; i*i <= n; i += 6)
        {
            if(n % i == 0 || n % (i + 2) == 0) return 0;
        }
        return 1;
    }
    return sieve[n / 2];
}

void GetNums(unsigned int n, unsigned int S, int size)
{      
    if(IsPrime(n)) 
    {
        GetDigits(n);
        nums[size].insert(n);
    }
    if(S == 0) return;
    
    for(unsigned int i = 1; i <= 9; i++)
    {
        if(TestBit(S, i))
        {
            unsigned int S_temp = S;
            unsigned int n_temp = n * 10 + i;
                        
            ClearBit(S_temp, i);
            GetNums(n_temp, S_temp, size + 1);
        }
    }
}

int main() 
{    
    Sieve(MAX);
    
    int t;
    cin >> t;        
    
    while(t--)
    {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        
        unsigned int S = 0;        
                
        for(int i=0; i<s.size(); i++)
        {
            SetBit(S, s[i]-'0');
        }              
        nums.resize(s.size()+1);
        GetNums(0, S, 0);  
                        
        vector<vector<unsigned int>> found(s.size() + 1, vector<unsigned int>(S+1, 0));
        vector<set<pair<set<unsigned int>, unsigned long>>> sums(S+1);
            
        for(int i = 0; i <= s.size(); i++) 
        {
            found[i][S] = 1;            
        }        
        sums[S] = {{{}, 0}};

        
        for(unsigned int used = 0; used < s.size(); used++)
        {            
            for(int bits = S; bits >= 0; bits--)
            {                
                if(found[used][bits])
                {                  
                    for(unsigned int size = 1; size <= s.size() - used; size++)
                    {                        
                        for(auto num : nums[size])
                        {                            
                            unsigned int digits = p_digits[num];
                            unsigned int temp = bits;                            
                            unsigned int combined = bits | digits;
                            
                            if(combined > bits) continue;
                            
                            temp = bits ^ digits;
                            
                            for(auto sum : sums[bits])
                            {
                                set<unsigned int> prev = sum.first;
                                unsigned long s = sum.second;

                                if(!prev.empty() && num <= *prev.rbegin()) continue;

                                prev.insert(num);
                                sums[temp].insert({prev, s + num});
                            }                                
                            found[used + size][temp]++;                            
                        }
                    }
                }
            }
        }   
        vector<long> result;
        
        for(auto it : sums[0])
        {
            result.push_back(it.second);
        }
        sort(result.begin(), result.end());
        
        for(auto it : result)
        {
            cout << it << "\n";
        }        
        cout << "\n";
        nums.clear();
    }   
    return 0;
}
