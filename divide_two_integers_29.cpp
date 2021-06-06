/*
https://leetcode.com/problems/divide-two-integers/submissions/

Tough.

Time: logn*logn
https://leetcode.com/problems/divide-two-integers/discuss/13407/C%2B%2B-bit-manipulations
*/

class Solution {
public:
    int divide(int a, int b) { // a/b
        
       int sign = 1;
        int quotient = 0;
        
       if((a>0 && b<0) || (a<0 && b>0 ))
           sign = -1;
        
        if(a == INT_MIN){
            if(b == -1) 
                return INT_MAX;
            if(b == INT_MIN) 
                return 1;
            if(b == 1) 
                return INT_MIN;
            
            a += abs(b); // reduce a by b
            quotient++;
        }
        
        if(b == INT_MIN) return 0;
        
        a = abs(a);
        b = abs(b); // abs(-2147483648) = -2147483648
        
        while(a >= b) {
            int tmp = b, count = 1;
            while(a - tmp >= tmp){ //(a >= tmp<<1 or >= 2*tmp) may cause overflows
                tmp <<= 1;
                count <<= 1;
            }
            a -= tmp;
            quotient += count;
        }
        
        if(sign == -1)
            return -quotient;
        return quotient;
    }
};
