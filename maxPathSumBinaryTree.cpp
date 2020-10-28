/*
// return max value from each node including current node
// at any node, check if it is max sum considering-
- only current node
- current node + left subtree
- current nde + right
- current + lelft + right

and return from node max(current,  current+left,  current+right)

*/
#define INF 1e6
int ans;
class Solution {
public:
    
    int fun(TreeNode* root) {
        if(!root) return 0;
        
        int x = fun(root->left);
        int y = fun(root->right);
        
        int z = root->val;
        ans = max(ans, max(x+y+z, max(z, max(z+x, z+y))));
        
        return max(z, z + max(x, y));
    }
    int maxPathSum(TreeNode* root) {
        ans = -INF;
        fun(root);
        return ans;
    }
};
