/**
https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/

Every node will return the sum of apples in its subtree.
Good question.

*/


#define N 100005

vector<bool> visited(N, false);
class Solution {
public:
    
    vector<int> gr[N];
    vector<bool> apple;
    // vector<bool> visited(N, false); // can't sepcify parameters here;
    
    int dfs(int v) {
        visited[v] = 1;
        
        int sum = 0;
        for(auto child: gr[v]) {
            if(!visited[child]) {
                int x = dfs(child);
                sum += x;
                if(apple[child] || x > 0) { // if children return non zero or immediate child has an apple
                    sum += 2;
                }
            }
        }
        return sum;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        apple = hasApple;
        
        fill(visited.begin(), visited.end(), false);
        for(auto edge: edges) {
            gr[edge[0]].push_back(edge[1]);
            gr[edge[1]].push_back(edge[0]);
        }
        return dfs(0);
    }
};
