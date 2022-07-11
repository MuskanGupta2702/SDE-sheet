#include<bits/stdc++.h>
using namespace std;



//Optimal soln 
// T ==> O(N^3)
// S ==> O(1)

// eg. nums[1,0,-1,0,-2,2]   target = 0
// First sort the array - nums[-2,-1,0,0,1,2]
// For duplicate numbers pointers are increased

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if(nums.empty() || nums.size() < 4) return res;
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i<n; i++)
        {
            for(int j = i+1; j <n; j++)
            {
                int target_2 = target - nums[i] - nums[j];
                int left = j+1;
                int back = n-1;
                
                vector<int> quad(4);
                while(left < back)
                {
                    if(target_2 > nums[left] + nums[back]) left++;
                    else if(target_2 < nums[left] + nums[back]) back--;
                    else
                    {
                        quad[0] = nums[i];
                        quad[1] = nums[j];
                        quad[2] = nums[left];
                        quad[3] = nums[back];
                        res.push_back(quad);
                        
                        while(left < back && nums[left] == quad[2]) left++;
                        
                        while(left < back && nums[back] == quad[3]) back--;
                    }
                }
                while (j+1<n && nums[j+1] == nums[j]) j++;
                while (i+1<n && nums[i+1] == nums[i]) i++;
            }
        }
        return res;
    }
};