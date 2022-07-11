// Find the duplicate in an array of N+1 integers.

#include<bits/stdc++.h>
using namespace std;

// sort it and then see if  a[i] == a[i+1]
//  T ==> O(n) + O(N logN)
// S ==> O(1)

// hashing is one method 
// T ==> O(n)
// S ==> O(n)



//Optimal soln  //most optimized using linked list cycle method and tortoise method
// Initially put slow & fast pointers at 0th index and move slow by 1 and fast by 2
// stop the loop when they meet then again initialize fast at 0th index by slow where it is and move slow & fast 1 only.
// the point at which slow & fast meet second time is the duplicate num.  
// T ==> O(N)
// S ==> O(1)

class Solution {
public:
    
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[0];
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
        fast = nums[0];
        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

// 136. Single Number

// To find unique number in an array of all duplicate
// XOR
// As xor is commutative i.e  A^B^C = C^A^B
// 1^1 = 0^0 = 0
//  A^A^B = A^B^A = B^A^A { Matching is cancelled }

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int unique = 0 ;
        for(int i = 0; i< nums.size(); i++)
        {
            unique ^= nums[i];
        }
        return unique;
    }
};

// 977. Squares of a Sorted Array
// Two pointers method

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        vector<int> res(nums.size());
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            if(abs(nums[l]) < abs(nums[r]))
            {
                res[i] = nums[r] * nums[r--];
            }
            else
            {
                res[i] = nums[l] * nums[l++];
            }
        }
        return res;
    }
};

// 

int merge_array(long long arr[], long long temp[],int left, int mid, int right)
{
	int i = left, j = mid, k = 0, inv_count = 0;
    while((i <= mid-1) && (j <=  right))
    {
        if(arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
        {
            temp[k++] = arr[j];
            inv_count = inv_count + (mid-i);
        }
        while(i <= mid-1)
            temp[k++] = arr[i++];
        while(j <= right)
            temp[k++] = arr[j++];
        
        for(i = left; i<=right; i++)
        {
            arr[i] = temp[i];
        }
        return inv_count;
            
    }
}

int merge_sort(long long arr[], long long temp[],int left, int right)
{
    int mid, inv_count = 0;
    if(right > left)
    {
        mid = (left + right)/2;
        inv_count += merge_sort(arr,temp,left, mid);
        inv_count += merge_sort(arr,temp, mid+1, right);
        
        inv_count += merge_array(arr,temp,left, mid + 1, right);
    }
    return inv_count;
}


long long getInversions(long long *arr, int n){
    // Write your code here.
    long long temp[n];
    long long ans = merge_sort(arr, temp, 0, n-1);
    return ans;
}