/**
No need of visited array here, the lip array is taking care of that.

lip[i][j] = longest path possible sarting at (i,j);

we do dfs from every possible (i,j) & return already saved ans, if it is present
time: O(nm)
Just like dfs over a forest, just that here visited(lip) array is not boolean, it stores our answer


*/

#define N 1005
int lip[N][N];
int n,m;
int dir[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
class Solution {
public:
    
    bool inside(int x, int y) {
        if(x>=0 && x<n && y>=0 && y<m )
            return true;
        return false;
    }
    
    int dfs(int x, int y, vector<vector<int>>& a) {
        
        if(lip[x][y] != -1)
            return lip[x][y];
        
        int ans =1; // if all 4 neighbours are small then default value is 0.
        for(int i=0; i<4; ++i) {
            int u = x+ dir[i][0];
            int v = y+ dir[i][1];
            
            if(inside(u, v) && a[x][y] < a[u][v]) { // don't forget this second condition
                ans = max(ans, 1+ dfs(u,v,a));
            }
        }
        lip[x][y] = ans;
        return ans;
    }
    
    int longestIncreasingPath(vector<vector<int>>& a) {
        n = a.size();
        m=0;
        if(n >0)
            m = a[0].size();
        
        for(int i=0; i<n; ++i) {
            fill(lip[i], lip[i]+m, -1);
        }
        

        int ans =0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j) {
                    ans = max(ans, dfs(i,j,a));
            }
        }
        
        return ans;
    }
};
