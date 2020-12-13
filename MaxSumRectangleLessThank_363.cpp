/*
https://www.quora.com/Given-an-array-of-integers-A-and-an-integer-k-find-a-subarray-that-contains-the-largest-sum-subject-to-a-constraint-that-the-sum-is-less-than-k

Time: m^2 . nlogn

First solve the problem: find max sum subarray in a 1d array but sum should be less than k.
Then we can extend it by the idea of 2d kadane's problem: see tushar roy. (just checking every possible width of rectangle while ht is fixed)

We cannot solve the 1d array problem by kadane's algo cause once we neglect a larger than k sum, we cannot check the next sum from previous sum.
Ex: [-3, 6, -2] & k =2. Try by hand.

But we can do it in nlogn using prefix sum.
sum(a[i], .. a[j] ] =  prefix(j) - prefix(i)


we just need to find a (j,i) pair such that sum= prefix(j) - prefix(i) is max possible but is less than k.

Consider every index as j and for it find the i using lower_bound function. (lower bound finds iterator to first elemnt that is equal to or greater)

prefix[j] - prefix[i] <= k
or prefix[j] - k <= prefix[i];

we know j & k. so, we find lower_bound(prefix[j] - k). Write an example and check.
also j != i. so push the current sum every checking for current iteration.



*/

#define INF 1e9
#define pb push_back

class Solution {
public:
    
    int maxSum(vector<int> a, int n, int k) {
        set<int> prefix; // cannot use vector cause prefix sum is not monotonically increasing. It can decrease due to negative numbers
        if(n <1) return 0;
        
        int ans = -INF;
        prefix.insert(0); // don't forget this;
        int r = 0;
        for(int i=0; i<n; ++i) {
            
            r += a[i];
            set<int>::iterator it = prefix.lower_bound(r-k); // don't use std::lower_bound; use it only for vectors
            if(it != prefix.end()) {
                ans = max(ans, r- *it);
            }
            
            prefix.insert(r); // insert after
        }
        return ans;
    }
    
    int maxSumSubmatrix(vector<vector<int>>& a, int k) {

        int i,j,n,m=0;
        n = a.size();
        if(n > 0)
            m = a[0].size();
        
        // (just checking every possible width of rectangle while ht is fixed)
        int ans = -INF;
        for(i=0; i<m; ++i) {
            vector<int> temp(n);
            for(j=i; j<m; ++j) {
                for(int t=0; t<n; ++t) {
                    temp[t] += a[t][j];
                }
                ans = max(ans, maxSum(temp, n, k));
            }
        }
        
        return ans;
    }
};
