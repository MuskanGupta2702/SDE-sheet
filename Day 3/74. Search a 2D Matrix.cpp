#include<bits/stdc++.h>
using namespace std;

// Condition: row wise sorted
// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.


// Brute force method
// T => O(n^2)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i = 0 ; i < matrix.size(); i++)
        {
            for(int j = 0 ; j < matrix[0].size(); j++)
            {
                if(target == matrix[i][j])
                    return true;
            }
        }
        return false;
    }
};


// T => O(log (n*m)) =====> binary search  
// mid / totalCol = row
// mid % totalCol = column

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int lo = 0, hi = (n*m) - 1;
        int mid = (lo + hi)/2;
        while(lo <= hi)
        {
            if(matrix[mid/m][mid % m] == target)
                return true;
            else if(matrix[mid/m][mid % m] > target)
            {
                hi = mid - 1;
                mid = (lo + hi)/2;
            }
            else
            {
                lo = mid + 1;
                mid = (lo + hi)/2;
            }
            
        }
        return false;
    }
};

// Condition: both row & column wise sorted

// Logic : all elements to left are small and down is greater
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0, j = matrix[0].size() - 1, n = matrix.size();
        while(i < n && j>=0)
        {
            if(matrix[i][j] == target)
                return true;
            if(matrix[i][j] > target)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return false;
    }
};