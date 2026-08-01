/**

To get the element at position [i][j] in the result, we need to "match up" the i-th row of mat1 with the j-th column of mat2. We multiply corresponding elements and sum them up - this is essentially computing a dot product.

if (c1 != r2)
	then multiplication not possible.

    vector<vector<int>> C(r1, vector<int>(c2, 0));  // result matrix: r1 x c2
    
    for (int i = 0; i < r1; i++) {          // each row of A
        for (int j = 0; j < c2; j++) {      // each column of B
            int sum = 0;
            for (int k = 0; k < c1; k++) {  // shared dimension (c1 == r2)
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }



Now sparse multiplication-
A (3x3):          B (3x2):
1  2  3            1  2
4  0  6            0  4
7  8  0            5  0


In both the approaches the outer 2 loops remain the same, we just optimize on the inner loop.
Approach1-

A= vector<vector<Pair>> -
for every row, we store only the non zero columns in a vector
a[0] = [(pos:0, val:1), (pos:1, val:2), (pos:2, val:3)]   // row 0: "1 2 3"
a[1] = [(pos:0, val:4), (pos:2, val:6)]                   // row 1: "4 0 6" (skip the 0)
a[2] = [(pos:0, val:7), (pos:1, val:8)]                   // row 2: "7 8 0" (skip the 0)


B =  vector<unordered_map<Pair>>
for every column, we store only the non zero rows but in a hashmap.
b[0] = { 0: 1, 2: 5 }     // column 0 non-zeros: row0=1, row2=5 (row1=0 skipped)
b[1] = { 0: 2, 1: 4 }     // column 1 non-zeros: row0=2, row1=4 (row2=0 skipped)



Now we just multiple A and B. For every element of A, we look if the hashmap has that element and then multiply.
Notice that in the final multiplication, the innermost loop is A[i,j] * B[j, k] (because we transposed columns into rows for B)


Approach2-
A remains the same.
B uses vector just like A instead of map.
B = vector<vector<Pair>>
b[0] = [(pos:0, val:1), (pos:2, val:5)]     // column 0 non-zeros, sorted by row
b[1] = [(pos:0, val:2), (pos:1, val:4)]     // column 1 non-zeros, sorted by row

So while multiplyin A and B, we use a stratgey like merging 2 sorted vectors. This avoid expensive hashmap look ups.




**/









/*
https://www.lintcode.com/problem/sparse-matrix-multiplication/
https://leetcode.com/problems/sparse-matrix-multiplication/

Two ways:
1. Represent the matrix as vector<vector<Node>> where we store pos & val for every point.
Ex: 
A = 1 2 3
    4 0 6
    7 8 0

matrix A will be row wise
a = [0,1   1,2   2,3]
    [0,4   2,6]
    [0,7   1,8]

B = 1  2
    0  4
    5  0

B will be column wise posn

b = [0,1] [0,2]
    [2,5] [1,4]
this is 2 column vectors where first vector is first column & 2nd vector is 2nd column. Indices are also column wise





2. First matrix will be store pair<pos, val> but for second matrix we can use a map
map key = posn in column; val = element value.


*/

struct Node {
    int pos, val;
    Node() {}
    Node(int pos, int val) : pos(pos), val(val) {}
};

class Solution {
public:
    
    vector<vector<int>> mul(vector<vector<int>> &A, vector<vector<int>> &B) {
        int n1 = A.size();
        int m1 = A[0].size();
        int n2 = B.size();
        int m2 = B[0].size();

        vector<vector<Node>> a(n1);
        vector<unordered_map<int, int>>b(m2);


        for(int i=0; i<n1; ++i) {
            for(int j=0; j<m1; ++j) {
                if(A[i][j] != 0) {
                    a[i].push_back(Node(j, A[i][j]));
                }
            }
        }

        for(int i=0; i<m2; ++i) {
            for(int j=0; j<n2; ++j) {
                if(B[j][i] != 0)
                    b[i][j] = B[j][i]; // putting in the map
            }
        }

        // for(int i=0; i<m2; ++i){
        //     for(auto x: b[i]) // x will be an iterator
        //         cout<< x.second <<" ";
        //     cout<<"\n";
        // }

        // n1 * m1    n2 * m2
        // m1 == n2
        // ans = n1 * m2

        vector<vector<int>> ans(n1);
        for(int i=0; i<n1; ++i) {
            for(int j=0; j<m2; ++j) {
                int x =0;
                int l=0;
                while(l < a[i].size()) { // notice this, less than a[i].size; not m1
                    if(b[j].find(a[i][l].pos) != b[j].end()) {
                        x += a[i][l].val * b[j][a[i][l].pos];
                    }
                    l++;
                }
                ans[i].push_back(x);
            }
        }

        return ans;
    }

    vector<vector<int>> multiply(vector<vector<int>> &A, vector<vector<int>> &B) {
        
        return mul(A, B);
        int n1 = A.size();
        int m1 = A[0].size();
        int n2 = B.size();
        int m2 = B[0].size();

        vector<vector<Node>> a(n1), b(m2);


        for(int i=0; i<n1; ++i) {
            for(int j=0; j<m1; ++j) {
                if(A[i][j] != 0) {
                    a[i].push_back(Node(j, A[i][j]));
                }
            }
        }

        // notice this
        for(int i=0; i<m2; ++i) {
            for(int j=0; j<n2; ++j) {
                if(B[j][i] != 0)
                    b[i].push_back(Node(j, B[j][i]));
            }
        }

        // for(int i=0; i<m2; ++i){
        //     for(int j=0; j<b[i].size(); ++j)
        //     cout<<b[i][j].val<<" ";
        //     cout<<"\n";
        // }

        // n1 * m1    n2 * m2
        // m1 == n2
        // ans = n1 * m2

        vector<vector<int>> ans(n1);
        for(int i=0; i<n1; ++i) {
            for(int j=0; j<m2; ++j) {
                int x =0;
                int l=0, r=0;
                while(l < a[i].size() && r < b[j].size()) {
                    if(a[i][l].pos == b[j][r].pos) {
                        x += a[i][l].val * b[j][r].val;
                        l++;
                        r++;
                    }
                    else if(a[i][l].pos < b[j][r].pos)
                        l++;
                    else 
                        r++;
                }
                ans[i].push_back(x);
            }
        }

        return ans;
    }
};
