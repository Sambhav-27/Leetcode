/**
https://leetcode.com/problems/tiling-a-rectangle-with-the-fewest-squares/

Construct a 2d array of n*n size.
Now try to fill this array. Try first with the largest block; If it covers some blocks then check for next blocks.
What is the next block?
We can just check every box of size 1x1. If some block was previously filled, we can just return from there.

// just like sudoku solver.

Time is i think: O(n*n * n^3)


We can also just return the answer instead of having cnt variable but with that we won't be able to implement the optimization

curans = 1 + min(ans of child)

https://leetcode.com/problems/tiling-a-rectangle-with-the-fewest-squares/discuss/414979/Java-back-tracking-solution
*/

#define N 15
#define INF 1e7

class Solution {
public:
    
    int a[N][N] = {0};
    int n, m;
    int ans = INF;
    void fun(int r, int c, int cnt) {
        
        // Optimization: If we have already filled cnt boxes & we had this answer before, then exploring further will just degrade the answer
        if(cnt >= ans)
            return;
        
        // last row
        if(r == n) {
            ans = cnt; // store the answer
            return;
        }
        
        // this column ended; Move to start of next row
        if(c == m) {
            return fun(r+1, 0, cnt); // notice void return
        }
        
        // this cell was already filled in previous run
        if(a[r][c]) {
            return fun(r, c+1, cnt);
        }
        
        // try all blocks of size k
        for(int k=min(n-r, m-c); k>=1; --k) {
            
            if(available(r, c, k)) {
                cover(r, c, k);
                
                fun(r, c+1, cnt+1);
                uncover(r, c, k);
            }
        }
    }
    
    bool available(int r, int c, int k) {
        for(int i=0; i<k; ++i) {
            for(int j=0; j<k; ++j) {
                if(a[r+i][c+j])
                    return false;
            }
        }
        return true;
    }
    
    void cover(int r, int c, int k){
         for(int i=0; i<k; ++i) {
            for(int j=0; j<k; ++j) {
                a[r+i][c+j] = 1;
            }
        }
    }
    
    void uncover(int r, int c, int k){
         for(int i=0; i<k; ++i) {
            for(int j=0; j<k; ++j) {
                a[r+i][c+j] = 0;
            }
        }
    }
    
    int tilingRectangle(int n1, int m1) {
        n=n1;
        m=m1;
        
        fun(0, 0, 0);
        return ans;
        
    }
};
