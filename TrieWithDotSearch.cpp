/*

Remember that end=1 can also happend in middle of true; when one string is prefix of another.
Ex- a,aa
if there is dot(.), we apply dfs from that node. worst case it will check all chars of trie

Note trie is a different data structure * node is different;
So these two will have different classes.

*/
struct Node {
    unordered_map<char, Node*> m;
    bool end;
    
    Node() {
        end = false;
        m.clear();
    }
};

class Trie {
    Node* root; //= new Node();
    
    public:
    Trie() {
        root = new Node();
    }
    void insert(string s) {
        Node * cur = root;
        for(char ch: s) {
            if(cur->m[ch]) {
                cur = cur->m[ch];
            }
            else {
                Node * t = new Node();
                cur->m[ch] = t;
                cur= cur->m[ch];
            }
        }
        cur->end = true;
    }
    
    bool find(Node* root, int j, string s) {
        if(!root) return false;

        if(j == s.length()) return root->end;

        if(s[j] == '.') {
            for(auto it = root->m.begin(); it!=root->m.end(); ++it) {
                if(find(root->m[it->first], j+1, s)) {
                    return true;
                }
            }
            return false;
        }
        else {
            char ch = s[j];
            if(!root->m[ch]) return false;
            return find(root->m[ch], j+1, s);
        }
    }
    
    bool findString(string s) {
        return find(root, 0, s);
    }
};


//     bool find2(Node* root, string s) {
//         for(char ch: s) {
//             if(!root->m[ch]) return false;

//             root = root->m[ch];
//         }
//         return root->end; // if it's just prefix match then return true
//         // return true;
//     }



class WordDictionary {
public:
    
    Trie* trie;
    /** Initialize your data structure here. */
    WordDictionary() {
        trie = new Trie();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        trie->insert(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return trie->findString(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
