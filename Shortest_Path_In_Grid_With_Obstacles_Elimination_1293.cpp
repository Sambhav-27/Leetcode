/*
Won't find the shortest path using dfs. Not a dp problem.

Just do a level wise bfs to destination. Each state will have 4 paras:
x,y,obstaclesSeenSoFar,level

push only those children, if including those obstcles count is <= k

*/

#define N 50

struct State {
    int x,y,obst,level;
    State() {}
    
    State(int x, int y, int obst, int level) :x(x), y(y), obst(obst), level(level) {}
};
class Solution {
public:
    int n,m;
    vector<vector<int>> a;
    bool visited[N][N][N*N]; //3rd dimension is obstacles
    
    bool valid(int x, int y, int k) {
        return x>=0 && x<n && y>=0 && y<m;
    }
    
    int dir[4][2] = {0,1, 0,-1, 1,0, -1,0};

    
    int bfs(int k) {
        queue<State> q;
        q.push(State(0,0,0,0));
        visited[0][0][0] =1;
        
        while(!q.empty()) {
            State parent = q.front(); q.pop();
            
            if(parent.x == n-1 && parent.y == m-1) {
                return parent.level;
            }
            // visited[parent.x][parent.y][parent.obst] = 1; // if I mark here & not do it while pushing then it leads to TLE
            
            for(int t=0; t<4; ++t) {
                int u = parent.x + dir[t][0];
                int v = parent.y + dir[t][1];
                
                if(!valid(u,v, 0))
                    continue;
                
                int curObst = parent.obst + a[u][v]; // don't do this in valid func; u,v need to be in range 

                if(parent.obst+a[u][v] <= k && !visited[u][v][curObst]) {
                    q.push(State(u, v, curObst, parent.level+1)); // notice the state
                    visited[u][v][curObst] =1;
                }
            }
        }
        return -1;
    }
    int shortestPath(vector<vector<int>>& grid, int k) {
        a = grid;
        n = a.size();
        if(n ==0)
            return 0;
        m = a[0].size();
        
        for(int i=0;i<N;++i) {
            for(int j=0;j<N;++j)
                for(int t=0;t<N*N;++t)
                    visited[i][j][t] = 0;
        }
        return bfs(k);
    }
};
