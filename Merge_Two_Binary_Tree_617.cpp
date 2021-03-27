/**
 * Good question. Not easy.
 * };
 */
class Solution {
public:
    
    
    TreeNode* fun(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2)
            return NULL;
        
        int x = 0;
        if(root1)
            x += root1->val;
        if(root2)
            x += root2->val;
        
        TreeNode* cur = new TreeNode(x);
        
        cur ->left = fun(root1 ? root1->left : NULL, root2 ? root2->left : NULL);
        cur->right = fun(root1 ? root1->right: NULL, root2 ? root2->right: NULL);
        
        return cur;
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return fun(root1, root2);
    }
};
