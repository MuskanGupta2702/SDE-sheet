// Grid Unique Paths
// Many times asked in google

#include<bits/stdc++.h>
using namespace std;

// Recursive approach --> T - exponential --> Time limit exceeded
// S is also exponential
int countPath(int i,int j, int m, int n)
{
    if(i == m-1 && j== n-1) return 1;
    if(i >= m || j >= n) return 0;
    else return countPath(i+1,j,m,n) + countPath(i,j+1,m,n);
}

class Solution {
public:
    int uniquePaths(int m, int n) {
        return countPath(0,0,m,n);
    }
};


//Optimal soln 

// Converting recursive code to dynamic programming solution
// Repeating past without computing it
// Sub Overlapping problems

// T ==> O(NxM)
// S ==> ~ O(NxM)

int countPath(int i, int j, int m, int n, vector<vector<int>> &dp)
{
    if(i == m-1 && j == n-1) return 1;
    if(i >= m || j >= n) return 0;
    
    if(dp[i][j] != -1) return dp[i][j];
    else return dp[i][j] = countPath(i+1,j,m,n,dp) + countPath(i,j+1,m,n,dp);
}


class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n,-1));
        return countPath(0,0,m,n, dp);
    }
};

// Using permutation
// No. of times down = row-1
// No. of times right = col-1

long int fact(int i, int j)
{
    long int fact1 = 1;
    for(int k = j; k<=i; k++)
    {
        fact1 = fact1 * k;
    }
    return fact1;
}

int fact(int n)
{
    int fact1 = 1;
    for(int k = 1; k<= n; k++)
    {
        fact1 *= k; 
    }
    return fact1;
}

class Solution {
public:
    int uniquePaths(int m, int n) {
        int d = m-1, r = n-1;
        int total = d+r;
        int ans = 0;
        // ans = total ! / d! * r!;
        if(d<=r)
        {
            ans  = fact(total,r+1)/ fact(d);
        }
        else
        {
            ans  = fact(total,d+1)/ fact(r);
        }
        return ans; 
    }
};

// MOst optimised
// Same as above just here nCr is calcuated in an optimised way of for loop
// e.g ==> 10C3 = 8*9*10 / 3*2*1 
// T ==> O(m-1) or O(n-1)
// S ==> O(1)

class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = m+n-2;
        int r = m-1;
        double res = 1;
        for(int i = 1; i <= r; i++)
        {
            res = res * (N-r+i)/i; // to calculate nCr 
        }
        return int(res);
    }
};
 