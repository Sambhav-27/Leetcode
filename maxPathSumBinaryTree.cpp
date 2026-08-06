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

// ans is used to store the best sum.
// it can also be modelled as a return value;
// in that case the function will return 2 values- best path, and best sum
int ans;
class Solution {
public:
    
    int fun(TreeNode* root) {
        if(!root) return 0;
        
        int left = fun(root->left);
        int right = fun(root->right);
        
        int cur = root->val;

        // No need to include only left, or only right in this because the returned values from children
        // are not best sum, they are best path from the children;
        // and best sum was already evaluated at the children
        // Hence, cur has to be included to calculate sum
        ans = max(ans, max(cur+left+right, max(cur, max(cur+left, cur+right))));
        

        // notice you either include left, or right; you don't include both.
        // because you're returning the best path (not best sum). Best path can only include left or right branch
        return max(cur, cur + max(left, right));
    }
    int maxPathSum(TreeNode* root) {
        ans = -INF;
        fun(root);
        return ans;
    }
};


-----------------------
    

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
