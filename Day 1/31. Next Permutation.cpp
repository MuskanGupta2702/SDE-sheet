#include<bits/stdc++.h>
using namespace std;

//Optimal soln 
// T ==> O(3N) = O(N)    
// S ==> O(1)

// find a[i] which is less than a[i+1] then replace it with a num which is just greater than a[i]
// then reverse array from i th position till the end this gives next permutation

// e.g 123 --> 132


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), k ,l;
        for(k = n-2; k>=0; k--)
        {
            if(nums[k] < nums[k+1]) break;
        }
        if(k < 0) reverse(nums.begin(), nums.end());
        else{
            for(l = n-1; l>k; l--)
            {
                if(nums[l] > nums[k])
                    break;
            }
            swap(nums[l], nums[k]);
            reverse(nums.begin() + k + 1, nums.end());
        }
    }
};