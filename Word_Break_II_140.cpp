// backtracking
// do it carefully, seems complicated.
// time: n^n; At each step, tree can have n options in worst case
// we can even store the total sentences for every index but these words can be too many; So better to avoid it.
// time is I think 2^n * n; n from searching in dict. 2^n from recursion. After every point we have 2 options whethet to add a break here or not.
// Also, worst case would happen when dict has all the substrings of the string. Total substring = 2^n

class Solution {
public:
    
    string s;
    unordered_set<string> st;
    vector<string> ans;
    
    void fun(int j, vector<string> curSent) {
        if(j == s.length()) {
            string sent;
            for(auto x: curSent) { // form sentence string from words
                sent += x; sent+= " ";
            }
            sent.pop_back(); // remove last space
            ans.push_back(sent);
            return;
        }
        
        string cur;
        for(int i=j; i<s.length(); ++i) {
            cur += s[i];
            if(st.find(cur) != st.end()) { // O(n) from it
                curSent.push_back(cur);
                fun(i+1, curSent);
                curSent.pop_back();
            }
        }

    }
    
    
    vector<string> wordBreak(string str, vector<string>& wordDict) {
        s = str;
        for(auto x: wordDict) {
            st.insert(x);
        }
        
        vector<string> v(0);
        fun(0, v);
        return ans;
    }
};
