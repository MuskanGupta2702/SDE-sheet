// 2-Sum-Problem

#include<bits/stdc++.h>
using namespace std;

// T ==> O(N^2)
// S ==> S(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;
        for(int i = 0; i<n-1 ; i++)
        {
            for(int j = i+1; j<n; j++)
            {
                if(nums[i] + nums[j] == target)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        return ans;
    }
};


//Optimal soln 
// T ==> O(N), worst case if collisions are there O(N^2)
// S ==> O(N)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int,int> mpp;
        for (int i = 0; i<n; i++)
        {
            if(mpp.find(target - nums[i]) != mpp.end())
            {
                ans.push_back(i);
                ans.push_back(mpp[target - nums[i]]);
                return ans;
            }
            mpp[nums[i]] = i;       
        }
        return ans;
    }
};