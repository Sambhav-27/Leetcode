
/**

    There is no need to form the graph. You can just do bfs.
    Also it will be very difficult to try to form the graph. Process: countring from 1 to 10000 & adding edges for every node;
    but it will be difficult when i is not a 4 digit number;we need to always represent numbers in 4 digist. ex= 0021
    
    
    Also: don't forget to find shortest distance using bfs; Do not do bfs & increment for every node;
    For every node store the level. i.e. level order traversal

*/

#define pii pair<string, int>


class Solution {
public:
    
    int bfs(unordered_set<string> deadends, string dst) {
        
        queue<pii> q;
        unordered_map<string, bool> visited;
        
        q.push({"0000", 0});
        visited["0000"] = 1;
        
        if(deadends.find("0000") !=deadends.end()) 
            return -1; // don't forget this case.
        
        int i,ans = 0;
        
        while(!q.empty()) {
            pii p = q.front(); q.pop();
            
            string cur = p.first;
            if(cur == dst) return p.second;
            
            for(i=0; i<4; ++i) {
                int x = (cur[i]- '0' + 1 ) % 10;
                string next = cur;
                next[i] = char(x + '0');
                
                if(deadends.find(next) == deadends.end() // not in set
                    && !visited[next]) { // notice works even if key is not in map; no NPE.
                    q.push({next, p.second+1});
                    visited[next] =1;
                }
                
                x = (cur[i] -'0' + 9) % 10; // subtracting 1 = add 9 with mod 10
                string prev = cur;
                prev[i] = char(x + '0');
                
                
                if(deadends.find(prev) == deadends.end()
                  && !visited[prev]) {
                    q.push({prev, p.second+1});
                    visited[prev]=1;
                }
            }
        }
        
        return -1;
    }
    
    int openLock(vector<string>& v, string target) {
        
        int i,j,k;
        unordered_set<string> deadends;
        for(i=0; i<v.size(); ++i) {
            deadends.insert(v[i]);
        }
        
        return bfs(deadends, target); 
    }
}; 
