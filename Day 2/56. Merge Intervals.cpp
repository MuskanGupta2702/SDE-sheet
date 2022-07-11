// Merge Overlapping Subintervals

#include<bits/stdc++.h>
using namespace std;

//Optimal soln 
        // sorting    linear 
// T ==> O(N logN) + O(N) --> 1. sort the array   2. store 1st vector in temp and compare temp[1] with it[0] if its less than equal to then do following 
// S ==> O(N) --> coz need to return the merged intervals

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged_vector;
        if(intervals.size() == 0)
        {
            return merged_vector;
        }
        sort(intervals.begin(), intervals.end());
        vector<int> temp = intervals[0]; 
        
        for(auto it: intervals)
        {
            if(it[0] <= temp[1])
            {
                temp[1] = max(it[1], temp[1]);
            }
            else{
                merged_vector.push_back(temp);
                temp = it;
            }
        }
        merged_vector.push_back(temp);
        return merged_vector;
    }
};