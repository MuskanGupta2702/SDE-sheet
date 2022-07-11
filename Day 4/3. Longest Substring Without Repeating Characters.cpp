#include<bits/stdc++.h>
using namespace std;


// Best approach
// TC => O(N)
// SC => O(N)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length(), len = 0, l = 0, r = 0;
        vector<int> mpp(256, -1); // suppose char 'a' need to be stored so at position 97 --> -1 is updated with r i.e index at which a is found in string
        while(r < n)
        {
            if(mpp[s[r]] != -1) l = max(mpp[s[r]] + 1, l);
            mpp[s[r]] = r;
            len = max(len, r-l+1);
            r++;
        }
        return len;
    }
};