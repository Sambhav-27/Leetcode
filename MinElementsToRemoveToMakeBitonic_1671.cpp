/**

min elements to remove = n - max length bitonic array
*/

#define N 1e4

class Solution {
public:
    int minimumMountainRemovals(vector<int>& a) {
        
        vector<int> lr(N, 1);
        vector<int> rl(N, 1);
        
        int i,j,ans,n=a.size();
        for(i=1; i<n; ++i) {
            for(j=0; j<i; ++j) {
                if(a[i] > a[j]) {
                    lr[i] = max(lr[i], 1+lr[j]);
                }
            }
        }
        
        for(i=n-2; i>=0; --i) {
            for(j=n-1; j>i; --j) {
                if(a[i] > a[j]) {
                    rl[i] = max(rl[i], 1+rl[j]);
                }
            }
        }
        
        // bitonic array is just sum of both lr, rl at every point.
        // specific to this question: increasing/decreasing array is not bitonic; so don't consider end elements.
        ans = 1;
        for(i=1; i<n-1; ++i)
            ans = max(ans, lr[i]+rl[i]-1);
        
        
        return a.size()-ans;
    }
};
