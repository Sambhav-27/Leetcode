/**

mark both islands with different numbers.

Then do level order traversal from one island, once you reach the other island that's the answer

visualization: https://massivealgorithms.blogspot.com/2018/11/leetcode-934-shortest-bridge.html

*/

#define N 105

vector<vector<bool>> visited(N, vector<bool>(N, 0));
int n;
int dir[4][2] = {{1,0}, {0,1}, {-1,0}, {0, -1}};

struct pii {
    int x,y,level;
    pii(int x, int y, int level) : x(x), y(y), level(level) {}
    pii() {}
};

class Solution {
public:
    
    bool canMove(int x, int y) {
        if(x>=0 && x<n && y>=0 && y< n && !visited[x][y])
            return true;
        return false;
    }
    
    void dfs(vector<vector<int>>&a, int x, int y, int val) { // also changes every value in island to val
        visited[x][y] = 1;
        a[x][y] = val;
            
        for(int i=0; i<4; ++i) {
            int cx = x + dir[i][0];
            int cy = y + dir[i][1];
            
            if(canMove(cx, cy) && a[cx][cy] == 1)
                dfs(a, cx, cy, val);
        }
    }
    
    int bfs(vector<vector<int>> & a) {
        queue<pii> q;
        visited.assign(N, vector<bool>(N, false));
        
        // level order traversal
        
        // first level is all nodes of second island
        int i,j,c =0;
        for(i=0;i<n;++i) {
            for(j=0; j<n; ++j) {
                if(a[i][j] == 2) {
                    q.push(pii(i, j, 0));
                    visited[i][j] = 1;
                    c++;
                }
            }
        }
        
        //levels of node of same island won't change; cause remember we are keeping a visited array to visit a node
        // only once & we already marked first island nodes as visited
        while(!q.empty()) {
            
            pii p = q.front(); q.pop();

            // reached the other island
            if(a[p.x][p.y] == 1) {
                return p.level -1;
            }

            for(int i=0; i<4; ++i) {
                int cx = p.x + dir[i][0];
                int cy = p.y + dir[i][1];

                if(canMove(cx, cy)) {
                    q.push(pii(cx, cy, p.level+1));
                    visited[cx][cy] = 1;
                }
            }
            
        }
        
        return -1;
    }
    
    int fun(vector<vector<int>> & a) {
        n = a.size();
        visited.assign(N, vector<bool>(N, false));

        int i,j, x =1;
        for(i=0; i<n; ++i) {
            for(j=0; j<n; ++j) {
                if(a[i][j]==1 && !visited[i][j]) {
                    // cout<<"heh "<<i<<","<<j<<":"<<x<<"\n";
                    dfs(a, i, j, x);//will only be called twice as there are only 2 islands
                    x++;
                }
            }
        }
        
     
        return bfs(a);
    }
    
    int shortestBridge(vector<vector<int>>& a) {
        return fun(a);
    }
};
