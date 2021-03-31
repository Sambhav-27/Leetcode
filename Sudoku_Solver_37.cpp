
#define N 9
class Solution {
public:
    int a[N][N];
    
    bool checkBox(int i, int j) {
        int bi = i/3 * 3; // notice this
        int bj = j/3 * 3;
        
        int f[N+1] = {0};
        for(int k=0; k<3; ++k) {
            for(int t=0; t<3; ++t) {
                f[a[bi+k][bj+t]]++;
            }
        }
         for(int k=1; k<=N; ++k) {
            if(f[k] > 1)
                return 0;
        }
        return 1;
    }
    
    bool check(int i, int j) {
        int f[N+1] = {0};
        for(int k=0; k<N; ++k) {
            int x = a[i][k];
            f[x]++;
        }
        for(int k=1; k<=N; ++k) {
            if(f[k] > 1) // numbers can occur 0 times, if cell is unfilled
                return 0;
        }
        
        fill(f, f+N+1, 0);
        for(int k=0; k<N; ++k) {
            f[a[k][j]]++;
        }
        for(int k=1; k<=N; ++k) {
            if(f[k] > 1)
                return 0;
        }
        
        return checkBox(i, j);
    }
    
    bool solve(int i, int j) {
        
        if(i==N) // if this column ends, start with next columns
            return solve(0, j+1);
        
        if(j==N) // notice N is 9, so it will mean the 10 column, i.e. 0th cell of 10th column
            return true;
        
        // if it is already filled, fill the rest of cells
        if(a[i][j] != 0) {
            return solve(i+1, j);
        }
        
        for(int k=1; k<=N; ++k) {
            a[i][j] = k;
            
            if(check(i, j) && solve(i+1, j)) {
                return true;
            }
            
            a[i][j] = 0;
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        int i,j;
        for(i=0;i<N; ++i){
            for(j=0;j<N;++j){
                if(board[i][j] == '.')
                    a[i][j] = 0;
                else
                    a[i][j] = board[i][j] - '0';
            }
        }
        
        solve(0, 0);
        
        for(i=0;i<N; ++i){
            for(j=0;j<N;++j){
                board[i][j] = a[i][j] + '0';
            }
            
        }
    }
};
