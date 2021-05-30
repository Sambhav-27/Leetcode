/*
Time: O(n^3);  O(n^2) from recursion + memoization; O(n) comes from searching in the hash table;

Also see: https://leetcode.com/problems/word-break/
*/

class Solution {
public:

    string s;
    unordered_set<string> st;

    vector<int> dp;

    bool fun(int j) {
        if(j == s.length()) {
            return 1;
        }

        if(dp[j] != -1) {
            return dp[j];
        }
        string cur;
        for(int i=j; i<s.length(); ++i) {
            cur += s[i];
            if(st.find(cur) != st.end()) {  // this can be O(n); n = string length
                if(fun(i+1)) {
                    dp[j] = 1;
                    return 1;
                }
            }
        }
        dp[j] = 0;
        return 0;

    }

    bool wordBreak(string str, vector<string>& wordDict) {
        s = str;
        for(auto x: wordDict) {
            st.insert(x);
        }

        for(int i=0; i<s.length(); ++i)
            dp.push_back(-1);

        return fun(0);
    }
};
