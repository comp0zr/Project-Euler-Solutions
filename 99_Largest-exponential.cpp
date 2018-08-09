#include <bits/stdc++.h>
using namespace std;

int main() 
{    
    int N;
    cin >> N;
    
    vector<pair<long long, long long>> pairs;    
    
    for(int i=0; i<N; i++)
    {
        long long a, b;
        cin >> a >> b;            

        pairs.push_back({a, b});
    }
       
    int K;
    cin >> K;        
    
    sort(pairs.begin(), pairs.end(), [&](pair<long long, long long> a, pair<long long, long long> b)
     {
        return ((a.second * log(a.first)) < (b.second * log(b.first)));
     });
    
    cout << pairs[K-1].first << " " << pairs[K-1].second;
    return 0;
}
