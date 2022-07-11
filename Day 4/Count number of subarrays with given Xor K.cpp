#include <bits/stdc++.h>
using namespace std;

//Optimal soln
// T ==> O(N log N)       N for traversal and log N for map 
// S ==> O(N)

int solve(vector<int> &A, int B) {
    int count = 0, xorV = 0;
    unordered_map<int,int> freq;
    for(auto it: A)
    {
        xorV = xorV ^ it;
        if(xorV == B) count++;
        if(freq.find(xorV ^ B) != freq.end())
        {
            count += freq[xorV ^ B];
        }
        freq[xorV] += 1;
    }
    return count;
}

// TC => O(N^3)  still not correct ans
// SC => O(1)

int main()
{
    vector<int> A = { 4, 2, 2, 6, 4 };
    int B = 6;
    int count = 0, n1 = A.size();
    for(int i = 0; i < n1; i++)
    {
        for(int j = i; j < n1; j++)
        {
            int xorV = 0;
            for(int k = i; k <= j; k++)
            {
                xorV = xorV ^ A[k];
                cout<<"K = "<<k << " XorV = "<<xorV<<endl;
            }
            cout<<endl;
            if(xorV == B) 
            {   count++;
                cout << "Count = " << count<<endl;  
            }  
        }
    }
    // return count;
    cout << "Count = " << count;
    return 0;
}


