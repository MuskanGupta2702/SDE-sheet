// Merge two sorted Arrays without extra space

#include<bits/stdc++.h>
using namespace std;


// 1st added the array then sorted
//T ==> O(N) + O(N logN)
// S ==> O(1)

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i = m, j = 0; i < m+n ; i++, j++)
        {
            nums1[i] = nums2[j];
        }
        sort(nums1.begin(), nums1.end());
    }
};

//Optimal soln 
// T ==> O(N) like merge sort  ---> start from back
// S ==> O(1)

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j = n-1, k = m+n-1;
        while(i >=0 && j>=0)
        {
            if(nums1[i] < nums2[j])
                nums1[k--] = nums2[j--];
            else
                nums1[k--] = nums1[i--];
        }
        while(j>=0)
            nums1[k--] = nums2[j--];
    }
};