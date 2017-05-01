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


int main(){
    int t;
    cin >> t;
       
    while(t--)
    {
        int n;
        cin >> n;               
       
        unsigned long long sum3, sum5, sum15;
        unsigned long long num3 = 3, num5 = 5, num15 = 15, i;
        
        unsigned long long vals[3] = {3, 5, 15};
        
        for(int i=0; i<3; i++)
        {
            long long x = (n-1)/vals[i];
            vals[i] = ((vals[i]*x*(x+1))/2);            
        }
        cout<<(vals[0]+vals[1]-vals[2])<<endl;
    }
    return 0;
}
