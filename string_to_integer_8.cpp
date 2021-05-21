/**
https://leetcode.com/problems/string-to-integer-atoi/
Implement stoi
Take care of sign & leading whitespaces.
&& overflow

*/

class Solution {
public:
    
    bool overflow(int num, int digit) {
        int upper = INT_MAX;
        upper -= digit;
        upper /= 10;
        
        return num > upper;
        
        // if we are allowed to use long, then below code also works
        // long temp = ans;
        // temp *= 10;
        // temp += digit;
        // return temp > upper
    }
    int myAtoi(string s) {
        
        int ans = 0;
        int sign = 1;
            
        int i=0;
        while(s[i] == ' ') // ignore leading whitespaces
            i++;
        
        if(s[i] == '-') { // check sign
            sign = -1;
            i++;
        }
        else if(s[i] == '+')
            i++;
        
        for(; i<s.length(); ++i) {
            char ch = s[i];
            
            if(isdigit(ch)) {
                if(overflow(ans, ch-'0')) {
                    if(sign == -1) {
                        return INT_MIN; // -2^31
                    }
                    return INT_MAX; // 2^31 -1
                }
                ans *= 10;
                ans += ch- '0';
            }
            
            else return sign * ans;
        }
        
        return sign * ans;
    }
};
