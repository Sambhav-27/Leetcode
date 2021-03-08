/**

1. We can make a string of size 2*n and then try all possible combinations & take the valid one.
But that's too much time complexity. And also we need to write code to check validity.

2. This approach doesn't work: If 'a' is a valid sequence, then we can extend it to genrate other sequences like:
a()  ()a  (a)

But it won't generate sequence like: (())(())
cause this requires a rule like => a.b


3. just start from a blank string and follow these two rules:
a. We can append '(' if all '(' haven;t been consumed. i.e. if count of '(' is less than n
b. we can append ')' if count of '(' is more than ')' till now.

This will generate all valid sequences.

*/

#define pb push_back
class Solution {
public:
    
    vector<string> ans;
    int n;

    void fun(string cur, int l, int r)  {
        if(cur.length() == 2*n) {
            ans.pb(cur);
            return;
        }
        
        if(l < n) {
            cur += "(";
            fun(cur, l+1, r);
            cur.pop_back();
        }
        if(l > r) {
            cur += ")";
            fun(cur, l, r+1);
            cur.pop_back();
        }
        
    }
    
    vector<string> generateParenthesis(int tot) {
        n=tot;
        ans.clear();
    
        fun("", 0, 0);
        return ans;
    }
};
