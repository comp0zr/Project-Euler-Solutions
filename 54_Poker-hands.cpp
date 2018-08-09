#include <bits/stdc++.h>
using namespace std;

map<char, int> M = {{'T', 10}, {'J', 11}, {'Q', 12}, {'K', 13}, {'A', 14}};

typedef pair<int, char> Card;
    
vector<int> GetRank(vector<Card> &cards)
{
    sort(cards.begin(), cards.end(), [](Card a, Card b) { return a.first < b.first; });
    
    vector<int> nums;
    set<char> suits;
    
    bool consecutive = true;
    map<int, int> count;    
    vector<int> pair;
    int three = 0, four = 0;    
    
    for(auto &it : cards) 
    {
        if(!nums.empty() && it.first != nums.back() + 1)
        {
            if(consecutive)
            {
                if(nums.size() == 4 && it.first == 14 && nums[0] == 2)
                {
                    nums.insert(nums.begin(), 1);
                    it.first = 1;                    
                }                 
                else consecutive = false;
            }
        }
        count[it.first]++;
        nums.push_back(it.first);
        suits.insert(it.second);        
    }
    for(auto it : count)
    {
        int num = it.first, c = it.second;
        
        if(c == 2) pair.push_back(num);
        if(c == 3) three = num;
        if(c == 4) four = num;
    }
    
    if(consecutive)
    {        
        if(suits.size() == 1) 
        {
            if(nums[0] == 10) return {1};
            else return {2};
        }
        return {6};        
    }
    if(four) return {3, four};    
    if(three)
    {
        if(pair.size() == 1)
        {
            return {4, three, pair[0]};
        }
        else if(suits.size() > 1) 
        {
            return {7, three};
        }
    }
    if(suits.size() == 1) return {5};
    if(pair.size() == 2) return {8, max(pair[0], pair[1]), min(pair[0], pair[1])};    
    if(pair.size() == 1) return {9, pair[0]};
    return {10, nums[4]};    
}


int main() 
{
    int t;
    cin >> t;
    
    while(t--)
    {
        vector<Card> P1, P2; 
        
        for(int i=0; i<10; i++)
        {
            string card;
            cin >> card;
            
            if(i < 5) P1.push_back({(isdigit(card[0])) ? card[0]-'0' : M[card[0]], card[1]});
            else P2.push_back({(isdigit(card[0])) ? card[0]-'0' : M[card[0]], card[1]});
        }
        
        vector<int> hand1 = GetRank(P1);
        vector<int> hand2 = GetRank(P2);
        int rank1 = hand1[0];
        int rank2 = hand2[0];

        if(rank1 != rank2)
        {
            (rank1 < rank2) ? cout << "Player 1" << endl : cout << "Player 2" << endl;
        }
        else
        {            
            for(int i=1; i<hand1.size(); i++) 
            {
                if(hand1[i] != hand2[i])
                {
                    (hand1[i] > hand2[i]) ? cout << "Player 1" << endl : cout << "Player 2" << endl;
                    goto next;
                }             
            }
            for(int i=4; i>=0; i--)
            {
                if(P1[i].first != P2[i].first)
                {
                    (P1[i].first > P2[i].first) ? cout << "Player 1" << endl : cout << "Player 2" << endl;
                    break;
                }
            }
            next:
            continue;
        }
    }
    return 0;
}

