/**

Time: O(2n); not n^2

Two null tree are equal
One null & other is not then return false;
If current node's value is different then they can't be flip equivalent.
Then check
left subtree with left subtree && right subtree with right subtree (no flip)
&
left with right && right with left (flip case)

https://leetcode.com/problems/flip-equivalent-binary-trees/discuss/203003/C%2B%2B-Recursive-Solution-with-Explanation
 */
class Solution {
public:
    
    bool fun(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2)
            return true;
        
        if(!root1 || !root2)
            return false;
        
        if(root1->val != root2->val)
            return false;
        
        return (fun(root1->left, root2->left) && fun(root1->right, root2->right))
        || (fun(root1->left, root2->right) && fun(root1->right, root2->left));
        
    }
    
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return fun(root1, root2);
    }
};
