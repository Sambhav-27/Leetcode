#define N 10004
#define M 102

#define INF 1e7

int dp[M][N] = {0};

void fun() {
    vector<int> b;
    int i=0; // notice we push 0 also
    while(i < M) {
        b.push_back(i*i);
        ++i;
    }

    // b has all the perfect squares;
    // i th direction is square;
    // j is from 1 to n

    for(int i=1; i<N; ++i)
        dp[0][i] = INF;

    for(int i=1; i<M; ++i) {
        for(int j=1; j<N; ++j) {
            if(j < b[i]) 
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = min(dp[i-1][j], 1+dp[i][j-b[i]]); // either choose this number or don't
        }
    }
}

class Solution {
    
public:
    
    
        
    
    int numSquares(int n) {
        
        
        // dp data can be precomputed; so even for multiple test cases we can just return from the same global dp array;
        if(dp[10][10] == 0) { // just checking random cell to see if dp array is filled.
            fun();
        }
        
        
        return dp[M-1][n];
    }
};
