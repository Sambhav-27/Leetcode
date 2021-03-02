/**

Time: looks to be n^5; Outer while loop is n^2; and within that we have n^3

One itertaion looks like:
We start from bottom right;
For every cell, we check if there are 3 or more candies on the left, if yes, then we mark
0 for all these candies in the board b;
we mark on board b cause we will later check candies upwards, and we want the original values.
Ex; 
3 3 3
1 3 1
1 3 1

Here, we want to mark 0 for all the 3's

Simialrly, we check upwards;

After marking the candies, we crush them in every column.
For every column, we crush by aggregating them;
Ex:
0
5
0
0
0

Here, we crush by falling 3 steps in the last row;
Note that;crushing by 1 step in every row will produce wrong output in the above exmaple.


We do the above steps until we have candies to crush, thus we have the outer while loop.
Looks like the outer while loop can run (n^2)/3 time in worst case; Must be less than that.


Test cases:

[[1,3,5,5,2],[3,4,3,3,1],[3,2,4,5,2],[2,4,4,5,5],[1,4,4,1,1]]
[[4,5,6,7],[3,2,6,7],[4,2,4,5],[5,2,2,2]]
[[3,3,3,1,2],[1,2,3,3,3]]
[[6,3,3,1,2],[1,2,3,3,3]]
[[3,3,3,1,2],[1,2,3,3,3]]

*/

class Solution {
public:

    // fall all values in column by n; put 0 for new slots
    void fall(vector<vector<int>> &a, int x, int y, int n) {

        int falls = x - n;

        for(int i=0; i<=falls; ++i) {
            a[x-i][y] = a[x-i-n][y];
        }

        for(int i=0; i<n; ++i) {
            a[i][y] = 0;
        }
    }

    vector<vector<int>> candyCrush(vector<vector<int>> &a) {
        
        int n = a.size();
        if(n == 0) {
            return a;
        }
        int m = a[0].size();
        vector<vector<int>> b = a;
        int i,j,k;

        bool needsCrush = 1;
        while(1) {
            if(needsCrush == false)
                break;

            needsCrush = 0;
            for(i=n-1; i>=0; --i) {
                for(j=m-1; j>=0; --j) {
                    
                    if(a[i][j] == 0) {
                        continue;
                    }

                    // count on left
                    int left = 1;
                    for(k=j-1; k>=0; --k) {
                        if(a[i][k] == a[i][j]) {
                            left++;
                        }
                        else break;
                    }
                    // count on up
                    int up = 1;
                    for(k=i-1; k>=0; --k) {
                        if(a[k][j] == a[i][j]) {
                            up++;
                        }
                        else break;
                    }

                    if(left >=3) {
                        needsCrush = 1;
                        for(k=0; k<left; ++k) {
                            b[i][j-k] = 0;
                        }
                    }

                    if(up >= 3) {
                        needsCrush = 1;
                        for(k=0; k<up; ++k) {
                            b[i-k][j] = 0;
                        }
                    }
                }
            }

            // Now we crush all marked candies
            // we crush by aggregating all values in that column
            for(i=n-1; i>=0; --i) {
                for(j=m-1; j>=0; --j) {
                    int up =1;
                    for(k=i-1; k>=0; --k) {
                        if(b[k][j] == b[i][j]) {
                            up++;
                        }
                        else break;
                    }
                    if(b[i][j] == 0) {
                        fall(b, i, j, up);
                    }
                }
            }
            a = b; // b becomes the original board for next iteration
        }

        return b;
    }
};
