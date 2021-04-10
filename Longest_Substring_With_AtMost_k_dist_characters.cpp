// https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/q 
// learn this window exapnsion technique
// also similar: https://leetcode.com/problems/minimum-window-substring/

#define N 256
class Solution {
public:
    
    int getChars(int * f) {
        int c =0;
        for(int i=0; i<N; ++i) {
            if(f[i] > 0)
            c++;
        }
        return c;
    }
   
    int lengthOfLongestSubstringKDistinct(string &s, int k) {
        int l=0, r=0;
        int f[N] = {0};
        int ans = 0;

        f[s[0]]++; // notice this
        while(r < s.length()) {
            // squeeze from left
            while(l <=r && getChars(f) > k) {
                f[s[l++]]--;
            }

            ans = max(ans, r-l+1);
            ++r;
            if(r <s.length())
                f[s[r]]++;
            
        }
        return ans;
    }
};
