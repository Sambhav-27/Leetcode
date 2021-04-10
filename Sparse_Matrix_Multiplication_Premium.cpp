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
