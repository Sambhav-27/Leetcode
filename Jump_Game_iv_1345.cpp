/**
https://leetcode.com/problems/jump-game-iv/

https://leetcode.com/problems/jump-game-iv/discuss/502699/JavaC%2B%2B-BFS-Solution-Clean-code-O(N)

Time: bfs: O(E+V); V = total unique values; E = sum of freq of each number = N


Since, we need shortest path, we need to do bfs.
dfs won't give shortest path; If we do dfs without visited array then that's backtracking & it will be time consuming.


Take care of the case like: a = [7,7,7,7,7,7,7,7,7,7,10]

*/


#define N 100005

struct Node {
    int pos, level;
    Node() {}
    Node(int pos, int level): pos(pos), level(level) {}
};

class Solution {
public:
    
    vector<int> a;
    int n;
    unordered_map<int, vector<int>> m; // key = a[i]; value = indices at which this value occurs.
    bool visited[N];

    int dp[N];
    bool valid(int j) {
        return j>=0 && j<n && !visited[j];
    }
    
    int bfs(){
        queue<Node> q;
        q.push(Node(0,0));
        visited[0]=1;
        
        while(!q.empty()) {
            Node p = q.front(); q.pop();
            
            if(p.pos == n-1) {
                return p.level;
            }
            
            for(auto c: m[a[p.pos]]) {
                if(!visited[c]) {
                    visited[c] =1;
                    q.push(Node(c, p.level+1));
                }
            }
            
            if(valid(p.pos+1)) {
                visited[p.pos+1] =1;
                q.push(Node(p.pos+1, p.level+1));
            }
            
            if(valid(p.pos-1)) {
                visited[p.pos-1] = 1;
                q.push(Node(p.pos-1, p.level+1)); // beware don't do -1 in level
            }
            
            m[a[p.pos]].clear(); // if this value has been processed; Remove it from graph, so that it is not processed again in case of duplicates; This is very imp to reduce time compleity.
            // Ex: a = [7,7,7,7,7,7,7,10]
            // If we don't remove 7 then every time we see 7 we will check all other indices of 7.
            
        }
        return -1;
        
    }
    
    int minJumps(vector<int>& arr) {
        a = arr;
        n = a.size();
        for(int i=0; i<n; ++i) {
            m[a[i]].push_back(i);
        }
        
        fill(visited, visited+n+2, false);
        return bfs();
    }
};
