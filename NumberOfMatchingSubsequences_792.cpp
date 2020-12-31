/**

https://leetcode.com/problems/number-of-matching-subsequences/discuss/117634/Efficient-and-simple-go-through-words-in-parallel-with-explanation

Time: O(n * m); // n = length of s; m = total words

Don't check if every word is a subsequence of s;
Instead keep a list of words for every letter. Each word in that list is waiting for that letter.
Ex: s = abcde
words: a, bb, acd, ace

a: (a), (a)cd, (a)ce
b: (b)b

Now taverse s;
First we see 'a', that means every word waiting in a's list can be moved to their next list.
Also keep a pointer for every word indicating where we are, () here denotes the pointer

a: empty
b: (b)b
c: a(c)d, a(c)e
finished: a


In every iteration, we are shifting all the words of a list to other lists.


Take care of the case when s has duplicate characters:
Ex: S = "aa"
words = "aa"

*/

#define pb push_back
#define pii pair<string,int>
class Solution {
public:

    int numMatchingSubseq(string s, vector<string>& words) {
        
        // this is the map
        vector<vector<pii>> m(26);
        for(auto word: words) {
           m[word[0]-'a'].pb({word, 0}); // notice pushed without initializeng vector; unlike java
        }
        
        
        int ans =0;
        for(char ch: s) {
            
            vector<pii> waiting = m[ch-'a'];
            
            vector<pii> v(0);
            m[ch-'a'] = v; // clearing this list before processing and not after; cause if next letter is same then words can be added this same list. Ex: string = "aa", Words = ["aa"]
            
            for(auto p: waiting) {
                int nextCharacter = p.second +1; // stores index of char
                
                if(nextCharacter < p.first.length()) {
                    char ch = p.first[nextCharacter];
                    m[ch-'a'].pb({p.first, nextCharacter});
                }
                else { // this word is done; update the answer
                    ans++;
                }
            }
        }
        
        return ans;
    }
};
