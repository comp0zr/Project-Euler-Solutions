#include <bits/stdc++.h>
#define prev Prev
using namespace std;

vector<int> factorial = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
unordered_set<int> bad = {720, 5043, 151, 122, 5, 120, 4, 24, 26, 722, 5044, 169, 363601, 145, 1454, 40585, 871, 178, 278};

set<vector<int>> bad_digits;

int MAX = 1000000;
int N, L;

vector<set<int>> M(61);
vector<int> chainLength(1000010, -1);

map<vector<int>, int> permutation;

vector<int> GetDigits(int num)
{
    vector<int> digits;
    
    while(num)
    {
        digits.push_back(num % 10);
        num /= 10;
    }
    sort(digits.begin(), digits.end());
    return digits;
}

int GetSum(int num)
{
    int sum = 0;
    
    while(num)
    {
        sum += factorial[num % 10];
        num /= 10;
    }
    return sum;
}

void Search()
{
    M[2] = {0};    
  
    for(int i = 1; i <= MAX; i++)
    {                
        int length = 1;
        int num = i;
        
        set<int> found = {num};        
        vector<int> digits = GetDigits(num);
                        
        if(!bad.count(GetSum(i)) && !bad_digits.count(digits) && permutation.count(digits))
        {
            M[chainLength[permutation[digits]]].insert(i);
            continue;
        }
                        
        while(length < 60)
        {        
            int sum = (num == 0) ? 1 : GetSum(num);                                                
                                    
            if(found.count(sum)) 
            {
                num = sum;
                break;
            }
            found.insert(sum);            
            length++;
            num = sum;
        }        
        chainLength[i] = length;
        M[length].insert(i);
        permutation[digits] = i;
    }    
}
int main() 
{    
    for(auto it : bad)
    {
        bad_digits.insert(GetDigits(it));
        bad.insert(GetSum(it));
    }    
    int t;    
    cin >> t;
    
    Search();    
    
    while(t--)
    {
        cin >> N >> L;
        
        if(M[L].empty() || *M[L].begin() > N) 
        {
            cout << -1 << "\n";
            continue;
        }
        
        for(auto it : M[L]) 
        {
            if(it > N) break;
            cout << it << ' ';
        }
        cout << "\n";
    }
    return 0;
}
