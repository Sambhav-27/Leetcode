/**

calculate ht when going from top to bottom, return max(leftchildHt, rightchildHt) from every node;
where ht = distance from root;

Now, if both children have same ht & ht = maxHt, then this is the common ancestor. 
*/

TreeNode* ans;
int maxht;

class Solution {
public:
    
    int fun(TreeNode * root, int ht) {
        
        if(!root) return ht-1;
        maxht = max(maxht, ht);
        
        // above two lines can be replaced by following two lines.
        // because if you don't subtract 1 from ht, you might want to find maxdepth including that ht cuz later on we are comparing the maxdepth.
        // maxht = max(maxht, ht);
        // if(!root) return ht;
        
        
        int x = fun(root->left, ht+1);
        int y = fun(root->right, ht+1);
        
        if(x == maxht && y == maxht) {
            ans = root;
        }
       
        return max(x, y);
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        
        maxht = -1;
        ans = NULL;
        fun(root, 0);
        return ans;
    }
};
