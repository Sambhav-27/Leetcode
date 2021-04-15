/**
Just a bfs from start word to end word.

Don't form the graph from dict words. Like checking every word for every word.

Instead find neigbours during run time.

cur = cur word
try to replac every letter of cur with a to z and check if it forms a valid word.


To get the actual path, we need an array of Nodes.

unordered_map<string, Node> parents;

We can't just have a parent pointer in Node cause parent should point to Node type.
So, it will be like a linked list. Much simpler is to just have an array/map.
*/

struct Node {
    string word;
    int level;
    Node() {}
    Node(string word, int level) {
        this->word = word;
        this->level = level;
    }
};


class Solution {
public:
    
    unordered_set<string> words;
    unordered_map<string, bool> visited;
    
    int bfs(string begin, string end) {
        
        queue<Node> q;
        q.push(Node(begin, 1));
        visited[begin] = true; // works for string also
        
        while(!q.empty()) {
            Node p = q.front(); q.pop();
            
            if(p.word == end)
                return p.level;
            
            for(int i=0; i<p.word.length(); ++i) { // generating neighbours
                for(int j=0; j<26; ++j) {
                    
                    string next = p.word;
                    next[i] = char(j + 'a');
                    if(next == p.word || words.find(next) == words.end())
                        continue;
                    
                    if(!visited[next]) {
                        q.push(Node(next, p.level + 1));
                        visited[next] = true;
                    }
                    
                }
            }
        }
        
        return 0;
    }
    
    
    int ladderLength(string begin, string end, vector<string>& wordList) {
        
        for(auto x: wordList){
            words.insert(x);
        }
        
        return bfs(begin, end);
    }
}; 
