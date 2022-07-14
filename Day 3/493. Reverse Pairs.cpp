#include<bits/stdc++.h>
using namespace std;

// Given an integer array nums, return the number of reverse pairs in the array.
// A reverse pair is a pair (i, j) where 0 <= i < j < nums.length and nums[i] > 2 * nums[j].

// T ==> O(N^2) Runtime error as int is not enough to store 2*nums[j] 
// even if we do double(nums[i])/2.0 > nums[j] then too it gives time limit exceeded
// SC ==> O(1)

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int count = 0, n = nums.size();
        for(int i = 0; i< n-1; i++)
        {
            for(int j = i+1; j<n; j++)
            {
                if(nums[i] > 2*nums[j])
                {
                    count++;
                    cout<<nums[i]<<" , "<<nums[j]<<endl; // pairs
                }
                
            }
        }
        return count;
    }
};

//Optimal soln : merge sort
// TC ==> O(N log N) + O(N) + O(N)
// S ==> O(N)

class Solution {
    
int merge_array(vector<int> nums, int left , int mid, int right)
{
    int cnv = 0, j = mid+1;
    for(int i = left; i<=mid; i++)
    {
        while(j<=right && nums[i] > (2LL * nums[j])){
            j++;
        }
        cnv += (j - (mid+1));
    }
    vector<int> temp;
    int i = left;
    j = mid+1;
    while(i <= mid && j <=right)
    {
        if(nums[i] < nums[j])
        {
            temp.push_back(nums[i++]);
        }
        
        else
        {
            temp.push_back(nums[j++]);
        }
    }
    while(i<=mid){
        temp.push_back(nums[i++]);
    }
    
    while(j<=right){
        temp.push_back(nums[j++]);
    }
    
    for(i = left; i<=right; i++)
    {
        nums[i] = temp[i-left];
    }
    cout<<cnv<<endl;
    return cnv;
}


int merge_sort(vector<int> nums, int left, int right)
{
    if(left >=right) return 0;
    
    int mid = (left + right)/2;
    int inv = merge_sort(nums, left, mid);
    inv += merge_sort(nums, mid+1, right);
    inv += merge_array(nums, left, mid, right);
    
    return inv;
}


public:
    int reversePairs(vector<int>& nums) {
        return merge_sort(nums, 0, nums.size()-1);
    }
};