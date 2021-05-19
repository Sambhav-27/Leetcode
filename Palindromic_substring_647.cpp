/*

https://leetcode.com/problems/palindromic-substrings/

Treat every point as middle of palindrome & expand 
N(n*n)
*/

class Solution {
public:
    
    int expand(string s, int l, int r) {
        int len = 0;
        while(l>=0 && r<s.length() && s[l--] == s[r++]) {
            len++;
        }
        return len;
    }
    
    int countSubstrings(string s) {
        int ans =0;
        for(int i=0; i<s.length(); ++i) {
            ans += expand(s, i, i); // odd length
            
            ans += expand(s, i, i+1); // even length
        }
        return ans;
    }
};
