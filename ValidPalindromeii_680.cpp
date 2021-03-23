/*
    check normal palindrome, if at any any places two characters are not same. Then we check for plaindrom exluding one of these two characters.
    Ex-  abefeda
    
    here, b & d doesn't match then we check if rest of string is palindrome
    i.e. without b = efed; without d = befe
    
    
    Notice, time = O(2N) not O(N^2)

*/
class Solution {
public:
    
    bool isPalind(string s, int b, int e) {
        while(b <=e) {
            if(s[b++] != s[e--]) {
                return false;
            }
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        
        int i,j,n =s.length();
        
        for(i=0; i<n/2; ++i) {
            if(s[i] != s[n-1-i]) {
                
                return (isPalind(s, i+1, n-1-i) || isPalind(s, i, n-2-i));
            }
        }
        return true;
        
    }
};
