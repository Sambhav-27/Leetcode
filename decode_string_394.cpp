// from claude

class Solution {
public:
    string decodeString(string s) {
        stack<int> numStack;
        stack<string> strStack;
        string currentString = "";
        int currentNum = 0;

        for (char c : s) {
            if (isdigit(c)) {
                currentNum = currentNum * 10 + (c - '0');
            } else if (c == '[') {
                numStack.push(currentNum);
                strStack.push(currentString);
                currentNum = 0;
                currentString = "";
            } else if (c == ']') {
                int repeatCount = numStack.top();
                numStack.pop();
                string previousString = strStack.top();
                strStack.pop();

                string repeated = "";
                for (int i = 0; i < repeatCount; ++i) {
                    repeated += currentString;
                }
                currentString = previousString + repeated;
            } else {
                currentString += c;
            }
        }

        return currentString;
    }
};


---------






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
