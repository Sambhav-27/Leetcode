/**

First of all note that going forward and then coming back is similar to going forward twice.

Now, we cannot fist choose best path to dest and then update the grid & then again choose a best path and sum the results.
This won't produce optimal results.
Ex-

1 1 1 1 0 0 
0 0 0 1 0 0
0 0 0 1 0 1
1 0 0 1 0 0
0 0 0 1 0 0
0 0 0 1 1 1

By this approach we can only choose 12 cherries in the above grid; total = 13
in the optimal way we can choose all 13.
Choosing the best path at first would give the path going through middle column & then in 2nd turn we can only choose one of the two left cherries.

But in the optimal way, if we take a right turn in the middle cell & not choose the best path in first turn, we can collect all cherries.


Now the solution is such that two guys start from src at the same time & try to reach destn;
If at any point they are at the same cell, then we count that cell's value only once, and not twice;

So, dp state = r1,c1, r2, c2;
r1,c1 is the posn of 1st guy & r2,c2 is the posn of 2nd guy.

Time: O(n^4);

but we notice that r1 + c1 == r2 + c2;
so, we reduce 1 parameter in dp state, and calculate it using the above formula.
Now, time: O(n^3);

cur ans = sum of postns of both guys + max we can achieve by moving both guys simultaneoulsy;
There can be 4 combns of these- both moving down, both right, right  & down, down & right
Good short video.

https://www.youtube.com/watch?v=q3-6jaNvj6c

https://leetcode.com/problems/cherry-pickup/discuss/329945/Very-easy-to-follow-%3A-step-by-step-recursive-backtracking-with-memoization-N4.
*/

#define N 55
#define INF 1e7

vector<vector<int>> a;
int n;

int dp[N][N][N];

class Solution {
public:
    

    
    int fun(int r1, int c1, int r2) {
        int c2 = r1+c1-r2; // r1 + c1 == r2 + c2

        // if we go out of bound; then don't check further states
        if(r1 >= n || c1 >= n || r2 >= n || c2 >= n || a[r1][c1] == -1 || a[r2][c2] == -1) {
            return -INF;
        }
        
        if(dp[r1][c1][r2] != -1) {
            return dp[r1][c1][r2];
        }
        
        // base case; if we reach final pos then return that cell's value;
        // this cell will not have a bush.
        // This condition ensures that we check for a valid path & not just sum the cherries withour reaching destn
        if(r1 == n-1 && c1 == n-1) {
            return a[r1][c1];
        }
        
        int ans =0;
        ans += a[r1][c1];
        
        if(r1 != r2) { // if 2nd guy is not at the same cell,then we add the value at his cell also
            ans += a[r2][c2];
        }
        
        int sub1 = fun(r1+1, c1, r2+1); // both right
        int sub2 = fun(r1+1, c1, r2); // right, down
        int sub3 = fun(r1, c1+1, r2); // both down
        int sub4 = fun(r1, c1+1, r2+1); // down, right
        
        int maxSub= max(sub1, max(sub2, max(sub3, sub4)));
        if(maxSub != -INF) {
            ans += maxSub;
        }
        else { // if all the sub solutions returned -INF that means, we cannot proceed further from this cell;
                    // sub soluton return -1 on encountering a bush or going out of bound; Then we mark this cell also as -INF
            ans = -INF;
        }
        
        dp[r1][c1][r2] =  ans;
        return ans;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int i,j,k;
        for(i=0;i<N;++i) {
            for(j=0;j<N;++j) {
                for(k=0;k<N;++k){
                    dp[i][j][k] = -1;
                }
            }
        }
        
        a = grid;
        n = a.size();
        return max(0, fun(0,0,0)); // notic this; if negative value is returned then we can't reach deest, so we return 0;
    }
};
