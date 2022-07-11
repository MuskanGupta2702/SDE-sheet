#include<bits/stdc++.h>
using namespace std;

//Optimal soln 
// T ==> O(N)
// S ==> O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0, mini = INT_MAX;
        for(int i = 0; i < prices.size() ; i++)
        {
            mini = min(mini, prices[i]);
            if(maxProfit < (prices[i] - mini))
            {
                maxProfit = prices[i] - mini;
            }
        }
        return maxProfit;
    }
};