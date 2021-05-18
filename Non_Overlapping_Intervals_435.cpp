/**
https://leetcode.com/problems/non-overlapping-intervals/

return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

just like in npt.
Sort acc to end time & then compare elements.

*/

bool comp(vector<int> a, vector<int> b) {
        return a[1] < b[1];
}
    
class Solution {
public:
    
   
    bool overlap(vector<int> a, vector<int> b) {
        return a[1] > b[0];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& a) {
        sort(a.begin(), a.end(), comp);
        
        int ans = 0;
        vector<int> pre = a[0];
        
        for(int i=1; i<a.size(); ++i) {
            vector<int> cur = a[i];
            
            if(!overlap(pre, cur)) {
                pre = cur;
            }
            else ans++;
        }
        return ans;
    }
};
