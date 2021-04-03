/*
https://www.lintcode.com/problem/palindrome-permutation-ii/

1. Just check if a valid palindrome can be made or not: All chars should occur even times. At max, one char can occur
odd times.
2. If yes, then we just need to generate all permutations of the first half.
3. After generating a permutation, palindrome can be formed from it. (Take care of odd & even length palindromes)


Generating all permutations https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
generating unique permutations: https://www.geeksforgeeks.org/distinct-permutations-string-set-2/

At every level we can swap ith char with any of the chars after it.

For unique perm: swap only if this character hasn't already been swapped



Time: O(n * n!)
n! comes from total permutations

n comes from actually forming the palindrome from a permutation. (make function)
*/

#define N 26

class Solution {
public:

    bool oddFound;
    char oddChar;
    vector<string> ans;

    string make(string s) {
        string palind = s;
        if(oddFound) {
            palind+= oddChar;
        }
        reverse(s.begin(), s.end());
        palind += s;
        return palind;
    }

    void fun(string t, int j) {
        if(j == t.length()-1) { // notice till n-1
            ans.push_back(make(t)); // O(n) comes from here
            return;
        }

        unordered_set<char> st;
        for(int i=j; i<t.length(); ++i) {
            if(st.find(t[i]) == st.end()) { // this is to have unique permutations
                swap(t[j], t[i]);
                st.insert(t[i]);
                fun(t, j+1);
                swap(t[j], t[i]); 
            }
        }
    }
    
    vector<string> generatePalindromes(string &s) {
        int f[N] = {0};
        for(auto ch: s) {
            f[ch-'a']++;
        }
        
        oddFound = false;

        string chars;

        for(int i=0; i<N; ++i) {
            if(f[i] > 0) {

                if(f[i] %2 == 0) {
                    for(int j=0; j<f[i]/2; ++j) {
                        chars += char(i+'a');
                    }
                }
                else { // there should be at max only 1 char that occurs odd times
                    if(oddFound)
                        return vector<string>(0);
                    
                    for(int j=0; j<f[i]/2; ++j) {
                        chars += char(i+'a');
                    }
                    oddChar = char(i+'a');
                    oddFound= true;

                } 
            }
        }
        fun(chars, 0);

        return ans;
    }
};
