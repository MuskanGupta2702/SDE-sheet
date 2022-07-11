//Time limit exceeded


// class Solution {
// public:
//     double myPow(double x, int n) {
//         double power = 1;
//         if(n == 0) return power;
        
//         for(int i = 1; i<= abs(n); i++)
//         {
//             power = power*x;
//         }
//         if(n>0)
//         return power;
//         return 1/power;
        
//     }
// };

// T ==> O(log n)
// Logic : 

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long nn = n;
        if(nn<0) nn = -1 * nn;
        while(nn)
        {
            if(nn % 2 == 0)
            {
                x = x * x;
                nn /= 2;
            }
            else if(nn % 2 == 1)
            {
                ans  = ans * x;
                nn -= 1;
            }
        }
        if(n < 0) return double(1.0)/double(ans);
        return ans;
    }
};