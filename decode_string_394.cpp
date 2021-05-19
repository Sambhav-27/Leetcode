/*
https://leetcode.com/problems/decode-string/

Good practice

*/
class Solution {
public:
    
    string getstring(string num, string t) {
        int n = stoi(num);
        
        string ans;
        while(n--) {
            ans += t;
        }
        return ans;
    }
    
    string fun(string s, int &i) { // notice pass by reference
        if(i == s.length()) {
            return "";
        }
        
        string ans;
        while(i < s.length()) {
            char ch = s[i];
            
            string num;
            if(isdigit(ch)) {
                num += ch;
                while(isdigit(s[++i])) {
                    num += s[i];
                }
                
                i++; // skip [
                string child = fun(s, i);
                i++; // skip ]
                
                ans += getstring(num, child);
            }
            else if(isalpha(ch)) {
                string t;
                while(isalpha(s[i])) {
                    t += s[i++];
                }
                ans += t;
            }
            else if (ch == ']') {
                return ans;
            }
        }
        return ans;
    }
    
    string decodeString(string s) {
        string ans;
        
        int j=0;
        return fun(s, j);
    }
};
