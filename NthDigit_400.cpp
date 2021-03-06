/**

1234567891011121314151617181920212223242526272829
Don't try to find a pattern, there is no pattern.

First let's put count of all 'i' digit numbers

1-> 9
2-> 90
3-> 900
..
..
There are 9 numbers with 1 digit, 90 with 2 digit, 900 with 3 digit.

Now, say we want to find the 1125th digit;
Then 9 + 2*90 = 189 digits are covered by numbers up to 2 digits.
Now we want the 1125 - 189 = 936th digit of the 3 digit number series.


now, 936/3 = 312
936 % 3 = 0

which means we want the 0th digit of the 312th 3 digit number;
which is 100 + 311 = 411

0th digit means, last digit of the previous numbers, so take care when remainder is 0;



*/

#define N 18
#define lld long long
class Solution {
public:
    int findNthDigit(int num) {
        
        lld n = num;
        lld numbers[N];
        lld tens = 1;
        for(lld i=1; i<N;++i) {
            numbers[i] = 9 * tens * i;
            tens *= 10;
        }
        
        lld i=1;
        lld prevN;
        while(n > 0) {
            prevN = n;
            n -= numbers[i++];
        }
        
        i -=1; // we want i digit number 

        lld quot = prevN/i;
        lld rem = prevN %i;
        
        lld x = pow(10, i-1) + quot;
        
        if(rem == 0) {
            x -=1;
            rem = i;
        }
        string s = to_string(x);
        return (s[rem-1] - '0');
    }
};
