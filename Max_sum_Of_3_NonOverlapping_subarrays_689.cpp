
/*


Notice that question is to pick 3 non overlapping subarrays such that total sum is maximum; not top 3 subarrays with maximum sum.
E.g., 2 2 3 4 1 5 2

max sum across 3 arrays = [2 2] [3 4] [5 2]

Cannot be solved using greedy because you can sacrifice sum of current array to maximize next subarray






top down dp where


f(j, k) means sum of k non overlapping subarrays starting at index j;
so you can either start a new window at j or don't start it

f(j+m, k-1) ; element picked at j; k-1 arrays need to be picked from rest of elements
f(j+1, k) ; not picked; pick k subarrays starting at next element


f(j, k) = max(don't pick, pick);

Time = (n*k)



*/

#define N 20004
#define INF 1000000

class Solution {
public:

    vector<int> a;
    vector<int> prefix;
    int m;

    int dp[N][4];

    int fun(int j, int k) {
        if(k == 0 ) {
            return 0;
        }

        if(j + (m-1) >= a.size()) { // m elements starting from j
            return -INF; // this question guarantees feasibility so this is not used
        }

        if(dp[j][k] != -1) {
            return dp[j][k];
        }

        int take = fun(j+m, k-1);
        int skip = fun(j+1, k);

        int takesum = prefix[j+m] - prefix[j] + take;

        return dp[j][k] = max(takesum, skip); 
    }

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int subarraySize) {
        
        a = nums;
        m = subarraySize;
        int k = 3;

        prefix.resize(a.size()+1);
        prefix[0] = 0;

        for(int i=0; i<a.size(); ++i) {
            prefix[i+1] = prefix[i] + a[i];
        }

        for(int i=0; i<=a.size(); ++i) {
            for(int j=0; j<=k; ++j) {
                dp[i][j] = -1;
            }
        }


        int sum = fun(0, k);

        vector<int> ans;

        // best sum is at dp(0, k), not dp(n-1, k) because we define dp as range starting at i, not ending at i


        

        // write the matrix on paper then it is easy to write following loop
        // traverse the dp array from ans which is at (0, k);
        // row = j; col = k
        int j = 0;
        while (k > 0) {
            int take = prefix[j+m] - prefix[j] + fun(j+m, k-1); // fun just returns the memoized dp array covering bases cases which are not in dp array
            int skip = fun(j+1, k);

            if(take >= skip) { // equal to because we want lexicographically smallest indices
                ans.push_back(j);
                k--;
                j+= m;
            }
            else {
                j++;
            }
        }

        

        
        
        return ans;
    }
};



////////////////////////



















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
