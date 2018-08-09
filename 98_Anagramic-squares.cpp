#include <bits/stdc++.h>
using namespace std;

long hashVal[10];

long Hash(string &s)
{
    long res = 0;
    int count[10] = {0};
    
    for(int i=0; i<s.size(); i++)
    {
        int c = s[i]-'0';
        count[c]++;
        res += (count[c] * hashVal[c]);
    }
    return res;
}

int main() 
{    
    for(int i=0; i<10; i++)
    {
        hashVal[i] = (i+1) * (rand() % 11587);
    }
    
    int N;
    cin >> N;

    vector<int> M(100000010);
    
    string square, digits;  
    int maxCount = 0;            
    
    long long i = sqrt(pow(10, N-1));
    long long end = floor(sqrt(pow(10, N)));
    long long s, ans;
    
    for(; i<=end; i++)
    {           
        s = i*i;
        
        square = to_string(s);        
        digits = square;
        sort(digits.begin(), digits.end());
               
        long index = Hash(digits);
                
        M[index]++;

        if(M[index] > maxCount)
        {           
            maxCount = M[index];
            ans = s;
        }      
    }
    cout << ans << endl;
    return 0;
}

