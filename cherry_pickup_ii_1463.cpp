/**
Time: O(9 * r * c * c); r = rows; c = columns

Unique state is represented by 3 variables- r,c1,c2;
posn of robot1 = r,c1
posn of robot2 = r,c2


ans = cur + max of child

Also, use memoization.


*/

#define N 75
class Solution {
public:
    
    int n,m;
    vector<vector<int>> a;
    
    int dir[3] = {-1,0,1};
    
    int dp[N][N][N];
    
    bool valid(int c1, int c2) {
        return c1>=0 && c1<m && c2>=0 && c2<m;
    }
    
    int fun(int r, int c1, int c2) {
        if(r == n-1) {
            if(c1 == c2)
                return a[r][c1];
            return a[r][c1] + a[r][c2];
        }
        
        if(dp[r][c1][c2] != -1)
            return dp[r][c1][c2];
        
    
        int cur = a[r][c1];
        if(c1 != c2) // if both robots are at same cell
            cur += a[r][c2];
        
        int child = 0;
        
        for(int i=0; i<3; ++i) {
            int x1 = c1 + dir[i];
            
            for(int j=0; j<3; ++j) {
                int x2 = c2 + dir[j];
                
                if(valid(x1, x2)) {
                    child = max(child, fun(r+1, x1, x2));
                }
            }
        }
        
        dp[r][c1][c2]= cur + child;
        return cur + child;
            
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        a = grid;
        n = a.size();
        
        if(n == 0)
            return 0;
        m = a[0].size();
        
        for(int i=0;i<N;++i) {
            for(int j=0; j<N; ++j) {
                for(int k=0; k<N; ++k)
                    dp[i][j][k] = -1;
            }
        }
        return fun(0,0,m-1);
    }
};
