/*
A valid can number can be:
1. if it doesn't have 'e' then whole number should be a decimal or an integer
2. If it has 'e' then part before e should be a decimal or integer. Part after 'e' should only be integer.


Integer:
optional sign + 0 or more digits

Decimal:
optional sign + digit follwed by . || digit followed by . followed by digit || . followed by digit


In other words:

Integer:
if only 1 char: then that should be a digit
> 1 char: first char can be digit/sign; rest all should be digit

Decimal:
if only 1 char: then that should be a sigit
> 1 char: first can be sign/digit/dot; rest all should have at most 1 dot; and should be digits; there should be at least 1 digit including first char. Ex: +. is invalid


Valid cases:
1.
1.0
.0
-.9
2e10
+6e-1


Invalid cases:
4e+
4e
.
9e2.5
+e



*/
class Solution {
public:
    
    bool isdigit(char ch) {
        return ch>= '0' && ch <= '9';
    }
    
    bool isInteger(string s, int b, int e) {
        
        if(e < b)
            return false;
        
        // if only one char then that should be a digit
        if(b == e && !isdigit(s[b]))
            return false;
        
        // first char can be digit or a sign
        if(s[b] != '+' && s[b] != '-' && !isdigit(s[b])) // notice && not ||
            return false;
            
         // rest all should be digits   
        for(int i=b+1; i<=e; ++i) {
            char ch = s[i];
            if(!isdigit(ch))
                return false;
        }
        return true;
    }
    
    bool isDecimal(string s, int b, int e) {
        if(e < b)
            return false;
        
        // if only one char then that should be a digit
        if(b == e && !isdigit(s[b]))
            return false;
        
        // first char can be a digit or sign or dot
        if(s[b] != '+' && s[b] != '-' && !isdigit(s[b]) && s[b] != '.') 
            return false;
        
        int dot = -1;
        if(s[b] == '.') {
            dot = b;
        }
        
        // there should be at least 1 digit
        // and at most 1 dot
        bool hasDigit = isdigit(s[b]); // check first digit also
        for(int i=b+1; i<=e; ++i) {
            char ch = s[i];
            
            // only digits & dot are allowed
            if(ch != '.' && !isdigit(ch)) {
                return false;
            }
            if(ch == '.') {
                if(dot != -1) // only one dot
                    return false;
                dot = i;
            }
            else if(isdigit(ch)) {
                hasDigit = true;
            }
        }
        
        return hasDigit;
    }
    
    bool isNumber(string s) {
        
        int e = -1;
        int n= s.length();
        
        for(int i=0; i<s.length(); ++i) {
            char ch = s[i];
            
             if(ch == 'e' || ch == 'E') {
                if(e != -1) {
                    return false;
                }
                e =i; break;
            }
        }
        
        if(e != -1) {
            bool firstHalf = isDecimal(s, 0, e-1) || isInteger(s, 0, e-1);
            bool secondHalf = isInteger(s, e+1, n-1);
            return firstHalf && secondHalf;
        }
        else {
            return isDecimal(s, 0, n-1) || isInteger(s, 0, n-1);
        }
        
    }
};
