// Majority Element (>N/3 times)
#include<bits/stdc++.h>
using namespace std;


// In this qn not more than two elements would occur > n/3 times and not less than one

// Hashmap 
// T ==> O(N logN) 
// S ==> O(N)


//Optimal soln ---> Boyer Moore Voting algo
// T ==> O(N) + O(N)
// S ==> O(1)

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0, count2 = 0, num1 = -1, num2 = -1;
        for(auto it: nums)
        {
            if(num1 == it)
                count1++;
            else if(num2 == it)
                count2++;
            else if(count1 == 0)
            {
                num1 = it;
                count1++;
            }
            else if(count2 == 0)
            {
                num2 = it;
                count2++;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        vector<int> ans;
        count1 = count2 = 0; 
        for(auto it: nums)
        {
            if(num1 == it)
                count1++;
            else if(num2 == it)
                count2++;
        }
        if(count1 > nums.size()/3)
            ans.push_back(num1);
        if(count2 > nums.size()/3)
            ans.push_back(num2);
        return ans;
    }
};