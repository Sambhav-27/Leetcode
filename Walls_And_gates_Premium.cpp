/**
BFS like rotten oranges.
Take care of following things:
1. Don't do it like we traverse a forest using dfs; Initially push all the starting points
in the queue, so that we can have the shortest distance to the destination.

2. Visited node can be marked in starting like dfs; Or uncomment the commented lines & mark there
& not mark at starting. Both works.


*/


#define INF 2147483647
#define N 1005

struct pii {
    int x,y,level;
    pii();
    pii(int x, int y, int level): x(x), y(y), level(level) {}
};

bool visited[N][N];
int dir[4][2] = {0,1, 1,0, -1,0, 0,-1};
int n,m;

class Solution {
public:

    bool isSafe(int x, int y) {
        if( x<n && x>=0 && y<m && y>=0 && !visited[x][y])
        return 1;
        return 0;
    }

    void bfs(int x, int y, vector<vector<int>> &a) {

        queue<pii> q;

        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                if(a[i][j] == 0) {
                    q.push(pii(i,j,0));
                    // visited[i][j] = 1; // way2
                }
            }
        }

        while(!q.empty()) {
            pii p = q.front(); q.pop();
            visited[p.x][p.y] = 1; // way 1

            for(int i=0; i<4; ++i) {
                int u = p.x + dir[i][0];
                int v = p.y + dir[i][1];

                if(isSafe(u, v) && a[u][v] != -1 ) {
     
                    if(a[u][v] == INF)
                        a[u][v] = p.level+1;

                    // visited[u][v]= 1; // way2
                    q.push(pii(u,v, p.level+1));
                }
            }
        }
    }

    /**
     * @param rooms: m x n 2D grid
     * @return: nothing
     */
    void wallsAndGates(vector<vector<int>> &a) {
        n = a.size();
        if(n ==0)
            return;
        m = a[0].size();

        
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                visited[i][j] = false;
            }
        }

        bfs(0,0,a);
    }
};
