/*

https://leetcode.com/problems/split-array-largest-sum/
Read the question carefully,it's at most m subarrays, not exact m subarrays.

" you can split the array into m non-empty continuous subarrays."


Similar to aggressive cows.

https://leetcode.com/discuss/interview-question/350800/Google-or-Onsite-or-Chocolate-Sweetness/350242


*/



#define INF 1e9

class Solution {
public:
    
  
    // one partition can have max sum =k;
    bool tryFit(vector<int> &a, int cap, int k) {
        int i,cur=0, parts=1;
        
        for(i=0; i<a.size(); ++i) {
            cur += a[i];
            
            if(cur > cap) {
                parts++;
                cur = a[i];
            }
        }
        
        if(parts > k)
            return false;
        
        return true;
    }
    
    int splitArray(vector<int>& a, int k) {
        
        
        int i,j,beg,end;
        beg = 0;
        end = 0;
        
        for(i=0; i<a.size(); ++i) {
            beg = max(beg, a[i]);
            end += a[i];
        }
        
        int ans = INF;
        while(beg <= end) {
            int m = (beg + end) /2;
            
            
            bool check = tryFit(a, m, k);
            
            
            if(!check) {  // more than k splits, increase cap
                beg = m +1;
            }
            else {
                end = m-1;
                ans = min(ans, m);
            }
            
            
            
  
        }
        
        return ans;
    }
};
