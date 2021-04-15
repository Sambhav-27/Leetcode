/*
pre requiste: https://leetcode.com/problems/word-ladder/

Good video; https://www.youtube.com/watch?v=mIZJIuMpI2M

1. Use bfs to find the shortest dist to destination.
2. Now use dfs backtracking to find all the paths till that destination.
    Note that we do not need visited array, cause if we only visit unvisited nodes, only 1 path will be produced. We want all the paths.
    
    In dfs, once we reach depth = depth returned by bfs;
    We return; Before returning add this path to ans if cur word = end word.
    

Now above approach will timeout, if we generate neigbours in dfs just like we do in bfs.

Optimisation:
While doing bfs, we can generate the adjaceny list and use it to do dfs.

Now, while generating an adjaceny list, we do not add neighbours whose level is <=  current level.

Causing if we add them, they will never produce the shortest path to the destination word.
We want dfs to go level by level. (watch the video)

So, only add neighbours if new word is not visited cause that means its level is more.
or if its level is >= level[cur]
    
    


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
    unordered_map<string, vector<string>> gr;

    vector<vector<string>> ans;
    int depth;
    string endWord;
    
    void dfs(string v, vector<string> cur, int ht) {
        
        if(ht == depth) {
            if(v == endWord) {
                ans.push_back(cur);
            }
            return;
        }
        
        for(auto child: gr[v]) {

            // if(!visited[next]) {  // don't need visited; cause keeping it will produce only 1 path
                cur.push_back(child);
                dfs(child, cur, ht+1);
                cur.pop_back();
            // }

            
        }
    }
    
    int bfs(string begin, string end) {
        
        queue<Node> q;
        q.push(Node(begin, 1));
        visited[begin] = true; // works for string also
        
        unordered_map<string, int> level;
        level[begin] =1;
        
        while(!q.empty()) {
            Node p = q.front(); q.pop();
            
            if(p.word == end)
                return p.level;
            
            for(int i=0; i<p.word.length(); ++i) {
                for(int j=0; j<26; ++j) {
                    
                    string next = p.word;
                    next[i] = char(j + 'a');
                    if(next == p.word || words.find(next) == words.end())
                        continue;
                    
                    // form the graph
                    if(!visited[next] || level[next] > level[p.word])
                    gr[p.word].push_back(next);
                    
                    if(!visited[next]) {
                        level[next] = p.level +1;
                        q.push(Node(next, p.level + 1));
                        visited[next] = true;
                        
                    }
                    
                }
            }
        }
        
        return 0;
    }
    
    
    vector<vector<string>> findLadders(string begin, string end, vector<string>& wordList) {
        
        for(auto x: wordList){
            words.insert(x);
        }
        
        depth = bfs(begin, end);
        
        if(depth == 0)
            return ans;
        
        
        // for(auto it: gr) {
        //     cout<<it.first<<"--> ";
        //     for(auto x: it.second) {
        //         cout<<x<<", ";
        //     }
        //     cout<<"\n";
        // }
        visited.clear();
        endWord = end;
        vector<string> cur;
        cur.push_back(begin);
        dfs(begin, cur, 1);
        
        return ans;
        
    }
};
