/**

https://code.dennyzhang.com/confusing-number-ii
https://www.youtube.com/watch?v=j0at21HSq5Y

LeetCode 1088: Confusing Numbers ii

Given a positive integer N, return the number of confusing numbers between 1 and N inclusive.

A number is confusing if:
- each digit is valid
- its mirror forms a different number.

Valid digits: 0,1,6,8,9;
Here: 6 and 9 alone are confusing cause their reverse is 9 and 6
0,1,8 are valid but are not confusing on their own cause their reverse is the same.


Time: O(5^k); k= total digits in n;

Just simple brute force based backtracking. Try all possible combinations at each digit.

Can't use digit dp, cause in digit dp their is another condition on the digits. Like sum of digits should be less than x; Then it reduces the complexity & we store the results.

However, we can still reduce its complexity by a small margin using digit dp approach.
Instead of trying all possible digits at every place, we only try digits that make the number smaller than n.
Ex: if n = 2300
If we fix first digit as 2 then for second digit, we should only consider 0,1; rest all numbers will give bigger numbers.

The fun2 function uses this approach.
*/


vector<int> valid = {0,1,6,8,9};
map<char, char> m;
class Solution {
public:
    

    int fun2(string s, int i, bool equal, int len, int n, vector<int>& a) { //a = array representation of n
        
        if(i == len) {
            if (isConfusing(s, n)) {
                return 1;
            }
            return 0;
        }
        
        int ans =0;
        if(!equal) {
            for(int j=0; j<5; ++j) {
                ans += fun2(s+char(valid[j] + '0'), i+1, false, len, n, a); // notice if we do not do this addition in char inline, then we need to pop_back from string afterwards.
            }
        }
        else {
            for(int j=0; j<5; ++j) {
                int ithDigit = a[i];
                if(valid[j] > ithDigit)
                    break;
                
                ans += fun2(s+char(valid[j] + '0'), i+1, valid[j] == ithDigit, len, n, a);
                
            }
        }
        return ans;
        
    }
    
    int fun(string s, int i, int len, int n) {
        
        if(i == len) {
            if (isConfusing(s, n)) {
                return 1;
            }
            return 0;
        }
        
        int ans =0;
        for(int j=0; j<5; ++j) {
            
            char ch  = char(valid[j] + '0');
            ans += fun(s+ch, i+1, len, n);
        }
        return ans;
        
    }
    
    int getConfusedNumbers(int n) {
        int len = to_string(n).length();
        string x = "";
        m['0'] = '0';
        m['1'] = '1';
        m['6'] = '9';
        m['9'] = '6';
        m['8'] = '8';
        
        // vector<int> a(0);
        // string org = to_string(n);
        // for(auto ch: org) {
        //     a.push_back(ch-'0');
        // }
        // return fun2(x, 0, false, len, n, a);
        
        return fun(x, 0, len, n);
    }
    
    bool isConfusing(string orgString, int n) {
        
        string s = removeLeadingZeros(orgString);
        if(s == "")
            return false;
        int org = stoi(s);
        if(org > n)
            return false;
        
        // mirror of number is obtained by replacing each digit with its mirror and the reading from right to left.
        // Ex: for n = 16; mirror = 91
        
        string mirror = "";
        for(int i=0; i<s.length();++i) {
            char ch = s[i];
            
            if(!isvalid(ch))
                return false;
            
            mirror += m[ch];
        }
    
        reverse(mirror.begin(), mirror.end());
        int reverse = stoi(mirror);
        return reverse != org; // reverse does not need to be less than n
    }
    
    string removeLeadingZeros(string orgString) {
        int i=0;
        string s = "";
        while(i < orgString.length() && orgString[i] == '0') {
            i++;
        }
        while(i<orgString.length()) {
            s += orgString[i];
            i++;
        }
        return s;
    }
    
    bool isvalid(char ch) {
        return ch =='0' || ch=='1' || ch=='6' || ch== '8' || ch=='9';
    }
    
    int main(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        
        cout<<endl<<getConfusedNumbers(100);
        
    }
};
