#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() 
{
    int n;
    cin>>n; cin.ignore();
    vector<vector<int>> nums(n, vector<int>(50));
    
    for(int i=0; i<n; i++)
    {        
        string num; 
        getline(cin, num);
        
        for(int j=0; j<50; j++) nums[i][j] = num[j]-'0';
    }
    vector<int> ans(55);
    fill(ans.begin(), ans.begin() + 5, 0); 
    
    int carry = 0;
    int index = 49;

    while(index >= 0)
    {
        int sum = carry;

        for(int j=0; j<n; j++)
        {
            sum += nums[j][index];
        }
        if(sum >= 10)
        {
            carry = sum/10;
            ans[index+5] = sum%10;
        }
        else 
        {
            carry = 0;
            ans[index+5] = sum;
        }
        index--;
    }

    while(carry)
    {
        if(carry >= 10) ans[index+5] = carry%10;
        else ans[index+5] += carry;
        carry /= 10;
        index--;
    }
    int first = find_if_not(ans.begin(), ans.end(), [](int i) { return i==0; }) - ans.begin();
    if(first > 50) first = 0;
   
    string answer = "";
    
    for(int i=first; i<first+10; i++)
    {
        answer += ans[i]+'0';
    }
    cout << answer << endl;    
    return 0;
}
