/*
https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

Question- separate nodes acc to x distance;
Within same x distance, nodes with less y  should come first;
If two nodes have same x & y then node with smaller value should come first.

Duplicates are allowed.


Test case: [3,1,4,0,2,2]
ans: [[0],[1],[3,2,2],[4]]


*/

vector<vector<int>> ans;
map<int, map<int, multiset<int>>> m; // outer map key = x; // inner map key = y

class Solution {
public:
    
    void fun(TreeNode* root, int x, int y) {
        if(!root) {
            return;
        }
        
        m[x][y].insert(root->val); // inserting in map of map
        fun(root->left, x-1, y+1); // note that x can become negative; so have to use map
        fun(root->right, x+1, y+1);
        
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        m.clear();
        ans.clear();
        fun(root, 0, 0);
        
        for(auto outerIt: m) {
            vector<int> onelevel;
            
            for(auto innerIt: outerIt.second) {
                multiset<int> st = innerIt.second;
                copy(st.begin(), st.end(), inserter(onelevel, onelevel.end())); // copy all set elements to vector
            }
            ans.push_back(onelevel);
        }
        return ans;
    }
};
