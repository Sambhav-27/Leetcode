// O(n) withoutextra space & wihout divison operator
// just like cumulative sum; from left & right both
// also bring out that product can overflow

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& a) {
        
        vector<int> ans(a.size());
        int cur =1;
        for(int i=0; i<a.size(); ++i) {
            ans[i] = cur;
            cur*= a[i];
        }
        
        cur =1;
        for(int i=a.size()-1; i>=0; --i) {
            ans[i] *= cur; // don't forget here it is *= not just =; 
            cur*= a[i];
        }
        
        return ans;
    }
};
