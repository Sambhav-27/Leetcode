/*

+ve numbers: works normally
-ve numbers:
2's complement;
1. Convert abs(num) to hex
2. subtract each digit from 15
3. add 1

How to do it in code:
1. convert abs(num) -1 to hex
2. subtract each digit from 15. We subtract each digit while we are generating it


Make sure to reverse the string at the end in both the cases.
https://math.stackexchange.com/questions/408761/hexadecimal-value-of-a-negative-number



Hex to Decimal
ffff ffff

subtract from 15 & add 1
0000 0001

How do we know if a hex number represents negative decimal?
Convert to binary & see the left most bit. If it 1 then it is a negative number.
That means leftmost value should be >8;

1 can be added after converting to decimal.

-13324 = "ffff cbf4"

Negative:
0000 340a

3*16^3 + 4*16^2 + 0 *16^1 + 11*16^0

= 12,288 + 1024 + 11
= 13323
+ 1

= 13324

*/


class Solution {
public:
    
    // char hex[16]= {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
    string hex = "0123456789abcdef";
    
    // works for +ve numbers only
    string fun(int n) {
        string ans;
        while(n) {
            ans += hex[n%16];
            n/=16;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    string toHex(int num) {
        if(num == 0)
            return "0";
        
        if(num >=0 )
        return fun(num);
        
        else {
            
            int n = abs(num) -1;
            string ans;
            while(n) {
                ans += hex[15-n%16]; // notice this
                n/=16;
            }
            
            // just to make the output of 8 bit
            for(int i=ans.length(); i<8;++i)
                ans+="f";
            
            reverse(ans.begin(), ans.end());
            return ans;
        }
    }
};
