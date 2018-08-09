#include <bits/stdc++.h>
using namespace std;

bool IsValid(short M[][9], bool C[][10], bool S[][10], vector<short> &row, short i)
{
    short index = (i/3) * 3;    
    short k = 0;

    for(short j=0; j<9; j++)
    {
        if(M[i][j] == 0)
        {
            if(!C[j][row[k]] || !S[index + (j/3)][row[k]])
            {                    
                return false;
            }
            k++;
        }
    }
    return true;
}

void Solve(short M[][9], bool R[][10], bool C[][10], bool S[][10], short count[][9], short i)
{            
    if(i == 9)
    {         
        for(int i=0; i<9; i++)
        {
            for(int j=1; j<=9; j++)
            {
                if(C[i][j]) return;
                if(S[((i/3)*3)+(i/3)][j]) return;
            }     
        }        
        for(int i=0; i<9; i++)
        {
            for(auto digit : M[i]) cout << digit;            
            cout << "\n";
        }
        exit(0);        
        return;
    }
    
    if(count[0][i] == 0)
    {
        Solve(M, R, C, S, count, i+1);
        return;
    }
    vector<short> row;     
    
    for(short j=1; j<10; j++)
    {
        if(R[i][j]) row.push_back(j);        
    }
      
    int index = (i/3) * 3;    
    
    do
    {
        if(!IsValid(M, C, S, row, i))
        {
            continue;
        }
        
        short c = 0;                
        short temp[9][9], count_temp[3][9];
        bool C_temp[9][10], S_temp[9][10];
        
        copy(&M[0][0], &M[0][0] + 9 * 9, &temp[0][0]);
        copy(&C[0][0], &C[0][0] + 9 * 10, &C_temp[0][0]);
        copy(&S[0][0], &S[0][0] + 9 * 10, &S_temp[0][0]);
        copy(&count[0][0], &count[0][0] + 3 * 9, &count_temp[0][0]);
        
        for(short j=0; j<9; j++)
        {
            if(temp[i][j] == 0)
            {
                temp[i][j] = row[c];
                C_temp[j][row[c]] = 0;
                S_temp[index + (j/3)][row[c]] = 0;                
                count_temp[1][j]--;
                count_temp[2][index + (j/3)]--;
                
                c++;
            }
        }        
        Solve(temp, R, C_temp, S_temp, count_temp, i+1);
    }
    while(next_permutation(begin(row), end(row)));
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    short M[9][9], c[3][9];
    bool row[9][10], col[9][10], square[9][10];
        
    for(int i=0; i<9; i++)
    {
        for(int j=1; j<=9; j++)
        {
            row[i][j] = 1;
            col[i][j] = 1;
            square[i][j] = 1;
            
            if(i < 3) c[i][j-1] = 10; 
        }
    }
    
    short index = 0;       
    bool DB = false;
    
    for(short i=0; i<9; i++)
    {
        string s;
        cin >> s;                
        
        index = (i/3) * 3;        
        
        for(short j=0; j<9; j++)
        {
            M[i][j] = s[j]-'0';            
                        
            row[i][M[i][j]] = 0;
            col[j][M[i][j]] = 0;
            square[index+(j/3)][M[i][j]] = 0;            
            
            c[1][j]--;            
            c[0][i]--;
            c[2][index+(j/3)]--;
        }        
    }        
    Solve(M, row, col, square, c, 0);
    return 0;
}
