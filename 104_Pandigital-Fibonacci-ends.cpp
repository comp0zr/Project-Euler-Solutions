#include <bits/stdc++.h>
using namespace std;

int a, b;
int k, size;

void GetSum(int a[], int b[], int c[], int c2[], bool left)
{
    int carry = 0;
    int i, j;
        
    for(i = 19, j = 19; i >= 0; i--, j--)
    {        
        if(a[i] == -1 && b[i] == -1) break;
        
        int sum = carry;
        
        if(a[i] != -1) sum += a[i];
        if(b[j] != -1) sum += b[j];
        
        carry = sum / 10;
        
        if(c[i] == -1) size++;
            
        c[i] = sum % 10;
    }
    if(carry)
    {
        if(i < 0)
        {
            size++;
            
            if(left)
            {                                  
                for(int index = 19; index > 0; index--)
                {
                    c[index] = c[index-1];
                    b[index] = b[index-1];                
                }                                
                c[0] = carry;
                b[0] = 0;
            }
        }      
        else if(c[i] == -1) 
        {
            c[i] = 1;
            size++;                
        }
        else c[i] += 1;
    }
}

int main() 
{
    cin >> a >> b >> k;
    
    int a_l[20], a_r[20], 
        b_l[20], b_r[20], 
        c_l[20], c_r[20];
    
    for(int i=0; i<20; i++)
    {
        a_l[i] = a_r[i] = 
        b_l[i] = b_r[i] = 
        c_l[i] = c_r[i] = -1;
    }
    
    a_l[19] = a_r[19] = a;
    b_l[19] = b_r[19] = b;
    c_l[19] = c_r[19] = 0;
        
    for(int i=3; i<=2000000; i++)
    {                        
        GetSum(a_l, b_l, c_l, c_r, 1);
        GetSum(a_r, b_r, c_r, c_l, 0);
        
        if(size >= k)
        {
            bool l_digits[10] = {0}, r_digits[10] = {0};
            int L = 0, R = 19;
                                   
            while(c_l[L] == -1) L++;
            
            for(int count = 1; count <= k; L++, R--, count++)
            {                
                if(l_digits[c_l[L]]) break;
                if(r_digits[c_r[R]]) break;
                
                l_digits[c_l[L]] = 1;
                r_digits[c_r[R]] = 1;
            }
            for(int d=1; d<=k; d++)
            {
                if(!l_digits[d] || !r_digits[d]) break;
                
                if(d == k)
                {
                    cout << i;
                    return 0;
                }
            }
        }
        copy(b_l, b_l + 20, a_l);
        copy(b_r, b_r + 20, a_r);
        copy(c_l, c_l + 20, b_l);
        copy(c_r, c_r + 20, b_r);               
    }
    cout << "no solution";
    return 0;
}

