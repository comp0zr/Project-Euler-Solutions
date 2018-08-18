#include <bits/stdc++.h>
#define CheckBit(bits, b) ((bits & (unsigned int)(1 << b)) != 0)
#define SetBit(bits, b) bits |= (unsigned int)(1 << b)

using namespace std;

typedef vector<string> Triomino;

const long long MOD = 1000000007;
const int neg = 3;

int N, M;

Triomino triomino[6] = 
{
    {   "##",
        "#."    },
    
    {   "##",
        ".#"    },
    
    {   "#.",
        "##"    },
    
    {   ".#",
        "##"    },
    
    {   "###"   },
    
    {   "#",
        "#",
        "#"     }    
};

unordered_map<unsigned long long, unsigned long long> memo;

vector<unsigned int> T(6);

int H[6] = { 2, 2, 2, 2, 1, 3 };
int W[6] = { 2, 2, 2, 2, 3, 1 };

unsigned int target = 0;


unsigned long long Solve(vector<unsigned int> grid, unsigned int row)
{    
    if(row == N) 
    {        
        return 1;
    }     
    if(grid[0] == target)
    {                   
        grid[0] = grid[1];
        grid[1] = grid[2];
        grid[2] = 0;        
        
        return Solve(grid, row + 1);
    }        
    unsigned int index = N - row;
    
    for(int i=0; i<3; i++)
    {
        index <<= M;
        index |= grid[i];
    }        
    
    if(memo.count(index)) return memo[index];
    
    int c = 0;
    
    while(CheckBit(grid[0], c)) c++;
    
    if(c >= M) return 0;
    
    unsigned long long res = 0;
            
    for(unsigned int j=0; j<6; j++)
    {                     
        if(row + H[j] > N) continue;
        if((j == neg && (c-1) + W[j] > M) || (j != neg && c + W[j] > M)) continue;

        vector<unsigned int> temp = grid;                        

        for(unsigned int y = 0; y < H[j]; y++)
        {                                                               
            for(unsigned int x = 0; x < W[j]; x++)
            {                    
                if(CheckBit(T[j], (y * 3) + x))
                {                                                
                    if((j == neg && !CheckBit(grid[y], (c-1) + x) || (j != neg && !CheckBit(grid[y], c + x))))
                    {
                        if(j == neg) SetBit(temp[y], (c-1) + x);
                        else SetBit(temp[y], c + x);
                    }
                    else goto next_t;
                }                        
            }
        }            
        res = res + Solve(temp, row);
        
        next_t:
        continue;
    }    
    memo[index] = res % MOD;
    return res % MOD;
}

int main() 
{    
    cin >> M >> N;
    
    if(N < M) swap(N, M);
    
    
    for(int index = 0; index < 6; index++)
    {                
        for(int i=0; i<triomino[index].size(); i++)
        {                
            for(int j=0; j<triomino[index][i].size(); j++)
            {
                if(triomino[index][i][j] != '.')
                {
                    T[index] |= (1 << (i * 3) + j);
                }
            }
        }        
    }        
    for(int i=0; i<M; i++)
    {
        target |= (1 << i);
    }    
    unsigned long long ans = Solve(vector<unsigned int>(3, 0), 0);
    
    cout << ans % MOD;
    return 0;
}

