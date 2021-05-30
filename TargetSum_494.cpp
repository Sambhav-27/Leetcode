/*

Difficult to do it in bottom up dp, as there can be negative sum.
But easy with top down approach.
Also, using a map for dp array.

a[i] & target both can be negative

*/
#define N 1005

class Solution {
public:
    
    vector<int> a;
    // int dp[N][30];
    unordered_map<int, int> dp[30]; // can't use normal dp array, cause sum can be negative
    
    int fun(int j, int s) {
        if(s > N) // given that arrays sum is less than 1000 but s can be up to 10^9
            return 0;
        
        if(j == a.size()) {
            if(s == 0) {
                return 1;
            }
            return 0;
        }
       
        
        if(dp[j].find(s) != dp[j].end())
            return dp[j][s];
        
        return dp[j][s] = fun(j+1, s+a[j]) + fun(j+1, s-a[j]);
    }
    
    int findTargetSumWays(vector<int>& nums, int sum) {
        a = nums;
        return fun(0, sum);
    }
};
