/**

https://leetcode.com/problems/count-complete-tree-nodes/

Notice, since it is a complete tree, height = log(n)

Time: O(logn * logn); Looks nlogn but it is just lognlogn;

At every step, if ht of left & right child is not same then only we are checking both children;
if ht is same, then we just return total nodes in that subtree;

https://leetcode.com/problems/count-complete-tree-nodes/discuss/61953/Easy-short-c%2B%2B-recursive-solution

*/
class Solution {
public:
    
    int fun(TreeNode* root) {
        if(!root)
            return 0;
        
        int hl=0, hr=0;
        TreeNode* l = root;
        while(l) {
            hl++;
            l = l->left;
        }
        
        TreeNode* r = root;
        while(r) {
            hr++;
            r = r->right; // notice
        }
        
        if(hl == hr) 
            return pow(2, hl)-1;
        
        return 1 + fun(root->left) + fun(root->right);
    }
    
    int countNodes(TreeNode* root) {
        return fun(root);
    }
};
