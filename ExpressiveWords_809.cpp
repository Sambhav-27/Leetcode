/*
Implementation.

Given 2 strings, check if 2nd string can be transformed to 1st one.

We can pick any character in 2nd string and repeat it 3 or more times.

simply: check for every character; If same character occurs less than 3 times consecutively then it has to be an exact match of count else try to increase count.

*/

class Solution {
public:
    
    // j will point to an index in string, increment j till we are seeing the same character & then return it;
    // Ex: heeelo; if j=1; it will return 3
    int getLastIndex(string s, int j) {
        char ch = s[j];
        for(int i=j+1; j<s.length(); ++i) {
            if(s[i] != ch)
                return i-1;
        }
        return j;
    }
    
    bool match(string s, string t) {
        int i=0,j=0;
        
        while(i<s.length() && j<t.length()) {
            if(s[i]!=t[j]) return false;
            
            int scount = getLastIndex(s, i) - i +1;
            int tcount = getLastIndex(t, j) - j +1;
            
            if(scount < 3) {
                if(scount != tcount) return false;
            }
            
            if(scount < tcount) return false; // we can only increase count in t & can't decrease
            
            i+= scount;
            j+= tcount;
            
            
        }
        return i==s.length() && j==t.length();
    }
    
    int expressiveWords(string S, vector<string>& words) {
        
        int ans =0;
        for(auto word: words) {
            if(match(S, word))
                ans++;
        }
        
        return ans;
    }
};
