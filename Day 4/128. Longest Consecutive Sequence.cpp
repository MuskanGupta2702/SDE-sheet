// 128. Longest Consecutive Sequence

#include<bits/stdc++.h>
using namespace std;


// Naive approach / brute force
// Sort the array then find the longest sequence TC => O(NlogN) + O(N)        SC => O(N) for merge sort
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() <=0 ) return 0;
        if(nums.size() ==1 ) return 1;
        sort(nums.begin(), nums.end());
        int a = nums[0], count = 1, maxi = INT_MIN;
        for(int i = 1; i<nums.size() ; i++)
        {
            if(nums[i] == a+1)
            {
                count++;
                // cout<<"nums[i] = "<<nums[i]<<", Count = "<<count<<endl;
            }
            else{
                count = 1;
            }
            maxi = max(maxi , count);
            a = nums[i];
            while(i+1 < nums.size() && nums[i+1] == nums[i]) i++; //To ignore duplicate
        }
        return maxi;
    }
};

//Optimal soln 
// T ==> O(3N) => O(N) to insert in set, for loop, while loop
// S ==> O(N) --> set

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> temp;
        for(auto it: nums)
        {
            temp.insert(it);
        }
        int longStreak = 0; 
        for(int num : nums)
        {
            if(!temp.count(num-1))
            {
                int currentStreak = 1, curNum = num;
                while(temp.count(curNum+1))
                {
                    curNum += 1;
                    currentStreak +=1;
                }
                longStreak = max(longStreak, currentStreak);
            }
        }
        return longStreak;
    }
};