#include<bits/stdc++.h>
using namespace std;

//Optimal soln 
// T ==> O(N^2))
// S ==> O(N^2)

// To know value at a given row and col ---> nCr ---> rCc   i.e  at r=0, c=0 ---> 0C0 

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal(numRows);
        for(int i=0; i<numRows ; i++)
        {
            pascal[i].resize(i+1);
            pascal[i][0] = pascal[i][i] = 1;
            for(int j = 1; j < i; j++)
            {
                pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
            }
        }
        return pascal;
    }
};