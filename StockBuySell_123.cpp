/*

Same as Tushar roy with k=2;
I did it by myself;

dp[i][j] = i transactions and j days;
First come up with an O(kn*n) solution and then optimize it to O(kn);

at j, either you can sell or do nothing.
if nothing, then dp[i][j] = dp[i][j-1];

if sell, then we must have bought it somewhere in the past;
so find maximum profit by considering all previous days;

so, if we  bought on wth day then
dp[i][j] = dp[i-1][w-1] + (price[j] - price[w]); // the first term means, max profit with 1 less transaction only from days less than w;

and now we take the max by considering all possible values of 'w';
So, time = O(kn*n);

We are doing repetitive work when condidering w for all days. We can maintain a running max from previous transactions.
PrevMax = max(PrevMax, dp[i-1][j-1] - price[j]);


*/

#define N 100005

class Solution {
public:
    int maxProfit(vector<int>& a) {
        
        int dp[3][N] = {0};
        int k=2, n=a.size();
        
        // make the array 1 indexed by shifting every element to right by 1
        a.resize(n+1);
        for(int i=n-1; i>=0; --i)
            a[i+1] = a[i];
        a[0]= 0;
        
        
        for(int i=1; i<=k; ++i) {
            int prevMax = -a[1]; // careful with this
            for(int j=1; j<=n; ++j) {
                
                dp[i][j] = max(dp[i][j-1], prevMax + a[j]);
                
                prevMax = max(prevMax, dp[i-1][j-1] - a[j]);
            }
        }
        
       
        return dp[k][n];
    }
};
