/**
https://leetcode.com/problems/longest-string-chain/discuss/294890/C%2B%2BJavaPython-DP-Solution

Sort by string sizes.
For every string maintain max length possible ending at current string.
Then check for all strings of smaller length than it.
dp[i] = max(dp[i], 1+dp[j])


*/


bool comp(string a, string b) {
    return a.length() < b.length();
}

class Solution {
public:
    
    // checks if b can be formed from a by adding 1 char at any place.
    bool possible(string a, string b) {
        // b should be greater than a
        
        int n = a.length();
        int m = b.length();
        
        if(n+1 != m)
            return false;
        
        int i=0, j=0;
        
        while(i<n && j<m) {
            if(a[i] == b[j]) {
                i++; j++;
            }
            else {
                j++;
            }
        }
        
        return i==n && (j == m || j+1 == m); // 2nd condition is required when last character is extra. Ex: a = xy; b = xyz
        
    }
    
    int longestStrChain(vector<string>& v) {
        
        sort(v.begin(), v.end(), comp);
        int n = v.size();
        vector<int> dp(n, 1);
        
        for(int i=0; i<n; ++i) {
            int len = v[i].length();
            
            int j =0;
            while(v[j].length() < v[i].length()) {
                
                if(possible(v[j], v[i])) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
                
                j++;
            }
        }
        
        
        return *max_element(dp.begin(), dp.end());
    }
};
