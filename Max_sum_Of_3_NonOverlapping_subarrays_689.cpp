/*

dp[i][j] = max sum with i subarray ending at jth number
id[i][j] = start index of ith subarray in org array

at any point jth element can be end of ith subarray or it cannot be.
If it can't be then we copy from above
else
max(left, sumOfSubarrayEndingAt j + max sum with1 less subarray)

This question has only 3 subarrays. Can be extended to M subarrays.

-     1    2    1    2    6    7    5    1
0,0  0,0  0,0  0,0  0,0  0,0  0,0  0,0  0,0  
0,0  0,0  3,0  3,0  3,0  8,3  13,4  13,4  13,4  
0,0  0,0  3,0  3,0  6,2  11,3  16,4  20,5  20,5  
0,0  0,0  3,0  3,0  6,2  11,3  19,4  23,5  23,5  



*/

#define N 100005

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& a, int k) {
        
        
        int sum[N] = {0};
        int n = a.size();
        
        int cur = 0;
        for(int i=0; i<k-1; ++i) {
            sum[i] = -1;
            cur += a[i];
        }
        sum[k-1] = cur + a[k-1];
        
        for(int i=k; i<n; ++i) {
            sum[i] = sum[i-1] + a[i] - a[i-k];
        }
        
        // for(int i=0; i<n; ++i)
        //     cout<<sum[i]<<" ";
        
        vector<int> ans(3);
        
        
        int dp[6][N] = {0};
        int id[6][N] = {0};
        
        for(int i=1; i<=3; ++i) {
            for(int j=1; j<=n; ++j) {
                
                if(j < i*k) { //copy from above
                    dp[i][j] = dp[i-1][j];
                    id[i][j] = id[i-1][j];
                }
                else {
                    
                    int x = sum[j-1] + dp[i-1][j-k];
                    
                    if(dp[i][j-1] >= x) { // left value
                        dp[i][j] = dp[i][j-1];
                        id[i][j] = id[i][j-1];
                    }
                    else {
                        dp[i][j] = x;
                        id[i][j] = j-k; // this subarray end at j in dp array; & started at j-k+1 in dp array. Which is j-k in org array
                    }
                    // dp[i][j] = max(dp[i][j-1], sum[j-1] + dp[i-1][j-k]);
                }
            }
        }
        
        ans[2] = id[3][n];
        ans[1] = id[2][ans[2]];
        ans[0] = id[1][ans[1]];
        
        // for(int i=0; i<=3; ++i) {
        //     for(int j=0; j<=n; ++j)
        //         cout<<dp[i][j]<<","<<id[i][j]<<"  ";
        //     cout<<"\n";
        // }
        return ans;
    }
};
