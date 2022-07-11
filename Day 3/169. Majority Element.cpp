#include<bits/stdc++.h>
using namespace std;

// T ==> O(n^2) time limit exceeded
// S ==> O(n)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj = 0;
        for(int i = 0; i< nums.size(); i++)
        {
            int count = 0;
            for(int j = 0; j<nums.size(); j++)
            {
                if(nums[i] == nums[j])
                    count++;
                cout<<"count = "<<count<<endl;
                maj = max(maj, count);
                cout<<"maj = "<<maj<<endl;
                if(maj > nums.size()/2)
                    return nums[i];
            }  
        }
        return 0;  
    }
};

// using sort
// T==> O(N logN) + O(N))

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0;
        int j = 0;
        //  cout<<nums.size()/2<<endl;
        for(int i = 0; i< nums.size(); i++)
        {
            if(nums[j] == nums[i])
            {
                ++count;
                // cout<<"count = "<<count<<" ele = "<<nums[i]<<endl;
                if(count > nums.size()/2)
                {
                    // cout<<"true";
                    return nums[i];
                }
            }
            else
            {
                count = 1;
                j = i;
            }               
        }
        return 0;       
    }
};

// Better Approach using maps
// T ==> O(N) 
// S ==> O(N)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> maj;
        for(int i = 0; i< nums.size(); i++)
        {
            maj[nums[i]]++;
            if(maj[nums[i]] > nums.size()/2)
                return nums[i];
        }
        return 0;
    }
};


//Optimal soln  --> Moore voting algo
// T ==> O(N)
// S ==> O(1)

// Initially count = 0, element = 0 linearly traverse

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, ele = 0;
        for(auto it: nums)
        {
            if(count == 0)
                ele = it;
            if(ele == it)
                count++;
            else
                count--;
        }
        return ele;
    }
};