#include <bits/stdc++.h>
using namespace std;

int MAX = 5000000;
vector<int> squares;
vector<int> counts;

void GenerateTriples(int a, int b, int c)
{
    long triangle = a + b + c;
    
    if(triangle > MAX) return;
    
    for(int k=2; triangle <= MAX; k++)
    {
        counts[triangle]++;
        
        triangle = (a * k) + (b * k) + (c * k);                
    }
    
    for(int i=0; i<3; i++)
    {
        int next_a, next_b, next_c;
        
        switch(i)
        {
            case 0:
            {
                next_a = -a + (2 * b) + (2 * c);
                next_b = -(2 * a) + b + (2 * c);
                next_c = -(2 * a) + (2 * b) + (3 * c);
                GenerateTriples(next_a, next_b, next_c);
                break;
            }
            case 1:
            {
                next_a = a + (2 * b) + (2 * c);
                next_b = (2 * a) + b + (2 * c);
                next_c = (2 * a) + (2 * b) + (3 * c);
                GenerateTriples(next_a, next_b, next_c);
                break;
            }
            case 2:
            {
                next_a = a - (2 * b) + (2 * c);
                next_b = (2 * a) - b + (2 * c);
                next_c = (2 * a) - (2 * b) + (3 * c);
                GenerateTriples(next_a, next_b, next_c);
                break;
            }                
        }
    }
}


int main() 
{
    counts = vector<int>(MAX + 1, 0);
    GenerateTriples(3, 4, 5);
  
    vector<int> ans(MAX + 1, 0);
    
    int sum = 0;
    
    for(int i=1; i <= MAX; i++)
    {
        if(counts[i] == 1) sum++;
            
        ans[i] = sum;        
    }
    
    int t;
    cin >> t;
    
    while(t--)
    {
        int n;
        cin >> n;
        
        cout << ans[n] << endl;
    }
    return 0;
}

