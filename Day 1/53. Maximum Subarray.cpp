#include<bits/stdc++.h>
using namespace std;

//Optimal soln 
// T ==> O(N)
// S ==> O(1)

// Kadane Algorithm
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, maxi = INT_MIN;
        for(auto it:nums)
        {
            sum += it;
            maxi = max(maxi, sum);
            // cout<<maxi<<" ";
            if(sum < 0)
                sum = 0;
        }
        cout<<endl;
        return maxi;
    }
};


// T(O) = n^3   also time limit exceeded
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN, n = nums.size(); 
        for(int i = 0; i<n; i++)
        {
            for(int j = i; j<n; j++)
            {
                int sum = 0;
                for(int k = i; k<=j; k++)
                {
                    sum += nums[k];
                }
                maxi = max(maxi , sum); 
            }
        }
        return maxi;
    }
};