#include<bits/stdc++.h>
using namespace std;

//Optimal soln 
// T ==> O(N logN) n for traversal and log N for hashmap
// S ==> O(N)

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        unordered_map<int,int> mpp;
        int sum = 0, maxi = 0;
        for(int i = 0; i < n; i++)
        {
            sum += A[i];
            if(sum == 0)
            {
                maxi = i + 1;
            }
            else{
                if(mpp.find(sum) != mpp.end())
                {
                    maxi = max(maxi, i - mpp[sum]);
                }
                else{
                    mpp[sum] = i;
                }
            }
        }
        return maxi;
    }
};

