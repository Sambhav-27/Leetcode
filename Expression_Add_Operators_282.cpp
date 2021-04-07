/*
Input: num = "105", target = 5
Output: ["1*0+5","10-5"]

Note: 1+05 is not valid acc to question; cause it has leading zero(s)

At every point we can either expand on right or insert an operator.
Inserting + or - is simple

but for inserting *, we need previous number also.
Ex: 1+2*3     here since * has precedence over +; ans is 7 and not 9

so to calculate a*b, we do curval-preNumber + preNumber*curNumber
And for next iteration, previous will be prevNumber*curNumber


Time complexity : 4^N; Not 3^N

For every number we have 4 choice: +, -, *, NOP

T(n) = 3 * T(n-1) + 3 * T(n-2) + 3 * T(n-3) + ... + 3 *T(1); // imagine this as a tree
T(n-1) = 3 * T(n-2) + 3 * T(n-3) + ... 3 * T(1);

Thus T(n) = 4T(n-1);


Space comlexity: O(n); dpeth of recursion

https://leetcode.com/problems/expression-add-operators/discuss/71923/Some-thougths

Also, see official solution section
https://leetcode.com/problems/expression-add-operators/discuss/191083/Python-Backtracking-Solution-Beating-95-with-Time-Complexity-Proof

*/

class Solution {
public:
    vector<string> ans;
    string s;
    int target;
    
    void fun(int j, long curval, long pre, string curstr) {
        
        if(j == s.length() && curval == target) {
            ans.push_back(curstr);
            return;
        }
        
        if(j == s.length()) {
            return;
        }
        
        
        long num = 0;
        string x;
        for(int i=j; i<s.length(); ++i) {
            if(i != j && s[j] == '0') break; // if there is leading zero; we only want to run for 1 iteration
            
            num *= 10;
            num += s[i]-'0';
            x += s[i];
            
            if(j==0) { // this will be j not i
                fun(i+1, num, num, curstr + x); // if it is first digit, we can only expand it
            }
            else {
                fun(i+1, curval+num, num, curstr + '+' + x); // notice the previous field
                fun(i+1, curval-num, -num, curstr + '-' + x);
                fun(i+1, curval-pre + (pre * num), pre*num, curstr + '*' + x); // notice how a*b is calculated
            }
        }
    }
    
    
    vector<string> addOperators(string num, int tar) {
        s= num;
        target = tar;
        
        fun(0, 0, 0, "");
        return ans;
    }
};
