#include<bits/stdc++.h>
using namespace std;

// One approach - sort the array using any search algo - T O(N logN)


// Second approach - count no. of 0's, 1's, 2's then insert that many 0,1,2's ==> counting sort
//  T ==> O(2(N))
// S ==> O(1)



//Optimal soln 
// T ==> O(N)
// S ==> O(1)


// DNF (Dutch national flag) algorithm - It says all numbers left of low is 0 , right of high is 2
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lo = 0, mid = 0, high = nums.size() - 1;
        while(mid <= high)
        {
            switch (nums[mid])
            {
                case 0:
                    swap(nums[lo++], nums[mid++]);
                    break;
                case 1:
                    mid++;
                    break;
                case 2:
                    swap(nums[high--], nums[mid]);
                    break;
            } 
        }
        
    }
};