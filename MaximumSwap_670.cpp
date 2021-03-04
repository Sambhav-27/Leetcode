/*

We start from left and check if for cur digit there is a bigger number on right, if there is we swap with it.
We need to find the largest number on right of cur digit & then swap.
So, time complexity will be n^2 cause we will need to check for all digits.


If there are two bigger numbers on the right, then we swap with the rightmos element.
Ex: 3959
Here, we swap '3' with the 4th digit which is '9'.


So, we just store the rightmost place of every number(0-9).

Now for every digit of input, we just find the rightmost place of 9 and swap with it.
If we can't find 9 then we check for 8, then 7.. unit this number is greater than the digit.


*/

class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        
        vector<int> pos(10, -1);
        for(int i=0; i<s.length(); ++i) {
            pos[s[i]-'0'] = i;
        }
        
        bool flag = false;
        for(int i=0; i<s.length(); ++i) {
            for(int j=9; j>=0 && (j > int(s[i]-'0')); --j) {
                
                if(pos[j] > i) {
                    swap(s[i], s[pos[j]]);
                    flag = 1;
                    break;
                }
            }
            if(flag) break;
        }
        
        return stoi(s);
    }
};
