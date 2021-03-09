/*

1. Check every word for every word; O(n*n*k)
n = total words; k = word size


2. Trie approach;
https://leetcode.com/problems/palindrome-pairs/discuss/176205/Beats-80-Trie-Java-with-Explanations
http://www.allenlipeng47.com/blog/index.php/2016/03/15/palindrome-pairs/

Two strings A, B can form a palindrome if:
1. A matches B reverse suffix of B; And rest of the part of B is a palindrome
Ex: A = ab   B = o0oba

2. Reverse B matches prefix of A; And rest of part of A is a palindrome
Ex: A = abooo   B = ba


Now, how to solve with trie:
1. Insert reverse of all words in the trie.
While inserting at every node maintain this info: which word ends at this node, pointers to next char, list of input word indices whose rest of the part is a palindrome.
To maintain this 3rd info, => While inserting at every node check if rest of the part is a palindrome;
If yes, then just store the index of word in the node;


2. How to search & add in ans
At every node either the input word can end or some other word in the trie can add;
If some other word ends, then checkif rest of the part of current word is a palind, if yes then add this pair;

If this word ends then
a. check if some other word has also ended, if yes, then add both
b. then add the list of indices present at this node to ans; This list means, that rest of the part of these words are palindrome.


Also take care of empty string separately;

Time: O(n*k*k)



3. Hash map based; Time: o(n*k*k)
For every word check if every prefix of it is present in the input;
And also check every suffix.
https://fizzbuzzed.com/top-interview-questions-5/

*/

struct Node {
    unordered_map<char, Node*> m;
    int wordEndIndex; // index of word that ends here; default = -1
    vector<int> v; // belowPalindromesIndices; stores indices of all strings who are palindrome after this node
    
    Node() {
        this->m.clear();
        this->wordEndIndex = -1;
        this->v.clear();
    }
};

bool isPalindrome(string str, int s, int e) {
    if(s > e)
        return false;
    
    while(s <= e) {
        if(str[s] != str[e]) {
            return false;
        }
        s++; e--;
    }
    return true;
}

vector<vector<int>> ans;
void add(int a, int b) {
    vector<int> v = {a, b};
    ans.push_back(v);
}

class Trie {
    
    Node * trieRoot;
     
    public:
    Trie() {
        trieRoot = new Node();
    }
    
    void insert(string s, int index) {
        Node* root = trieRoot;
        
        for(int i=0; i<s.length(); ++i) {
            char ch = s[i];
            
            if(!root->m[ch]) {
                root->m[ch] = new Node();
            }
            root = root->m[ch];
            
            // while creating, if rest of the part of this string is a palindrome
            // then we store index of this string in the current node
            if(isPalindrome(s, i+1, s.length()-1)) {
                root->v.push_back(index);
            }
        }
        
        root->wordEndIndex = index;
    }
    
    void search(string s, int index) {
        Node * root = trieRoot;
        for(int i=0; i<s.length(); ++i) {
            char ch = s[i];
            
            if(!root->m[ch]) {
                return;
            }
            root = root->m[ch];
            
            // if some other word ends here, then we check if rest of the part of input string is a palindrom
            // if rest of the part is palind, then we add this pair
            if(root->wordEndIndex != -1) {
                if(isPalindrome(s, i+1, s.length()-1)) {
                    add(index, root->wordEndIndex);
                }
            }
        }
        
        // word to search has ended here & if some other word already ends here then we add this pair 
        // remember we inserted in reverse order in trie, so some other word can also end here
        if(root->wordEndIndex != -1 && index != root->wordEndIndex) {
            add(index, root->wordEndIndex);
        }
        
        // word to search has ended here, already present suffix in trie matched till now,
        // now we add all the string whose rest of the parts are itself palindrome
        for(int i=0; i<root->v.size();++i) {
            add(index, root->v[i]);
        }
    }
};

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        Trie trie;
        ans.clear();
        
        int blankIndex = -1;
        for(int i=0; i<words.size(); ++i) {
            string s = words[i];
            if(s == "")
                blankIndex = i;
            
            reverse(s.begin(), s.end()); // don't forget inserting reverse string
            trie.insert(s, i);
        }
        
        for(int i=0; i<words.size(); ++i) {
            string s = words[i];
            trie.search(s, i);
        }
        
        // just to take care if these is an empty string & one word itself is a palindrome
        if(blankIndex != -1) {
            for(int i=0; i<words.size(); ++i) {
                string s = words[i];
                if(isPalindrome(s, 0, s.length()-1)) {
                    add(i, blankIndex);
                    add(blankIndex, i);
                }
            }
        }
        
        return ans;
    }
};
