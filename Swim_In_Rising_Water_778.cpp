/*
https://leetcode.com/problems/swim-in-rising-water/

Dijkistra: We just want the shortest solution from source to dst.
Edge wt is calculated at runtime.
If dist till parent > value at child index
then edge wt = 0;
else 
edge wt = value at child index - dist of parent; Cause we will need to wait this time to go to the children.


We can somehow remove the dist array, cause we are just interested in the max dist(time) so far;


Alternative solution:
Use binary search:

Check if there is path from src to dst where every node's value < m;
Minimize m;


Time: ElogV; E = total edges= N*N*4;
V = N*N

https://leetcode.com/problems/swim-in-rising-water/discuss/965631/Java-3-clean-codes%3A-Dijkstra's-algo-PriorityQueue-and-Binary-search
*/


#define INF 1000000
#define N 55

struct Node {
    int x,y,dist;
    Node() {}
    Node(int x, int y, int dist) : x(x), y(y), dist(dist) {}
};

struct comp {
    bool operator()(const Node& a, const Node& b) {
        return a.dist > b.dist; // min heap
    }
};

class Solution {
public:
    
    int dir[4][2] = {1,0, 0,1,-1,0, 0,-1};
    bool visited[N][N] = {0};
    int dist[N][N] = {INF}; // doesn't work
    vector<vector<int>> a;
    int n;
    
    bool safe(int x, int y) {
        return x>=0 && x<n && y>=0 && y<n && !visited[x][y];
    }
    
    int dijkistra()  {
        
        dist[0][0] = a[0][0];
        priority_queue<Node, vector<Node>, comp> q;
        
        q.push(Node(0,0, a[0][0])); // notice distance of source
        
        while(!q.empty()) {
            Node p = q.top(); q.pop();
            
            if(visited[p.x][p.y]) continue;
            
            for(int i=0; i<4; ++i) {
                int u = p.x + dir[i][0];
                int v = p.y + dir[i][1];
                
                if(!safe(u, v)) continue;
                

                // find edge weght
                int curwt = a[u][v] - dist[p.x][p.y]; // notice it is dist of parent; not a[parent]
                if(a[u][v] < dist[p.x][p.y]) {
                    curwt = 0;
                }
                
                
                if(dist[p.x][p.y] + curwt < dist[u][v]) {
                    dist[u][v] = dist[p.x][p.y] + curwt;
                    q.push(Node(u,v, dist[u][v]));
                }
            }
            visited[p.x][p.y] = 1;
        }
        
        return dist[n-1][n-1];
    }
        
    int swimInWater(vector<vector<int>>& grid) {
        a = grid;
        n = a.size();
        
        for(int i=0; i<=n; ++i) {
            for(int j=0; j<=n; ++j) {
                dist[i][j] = INF;
            }
        }
        return dijkistra();
    }
};
