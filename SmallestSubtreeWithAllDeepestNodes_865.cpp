
/*


From every node return 2 things-
1. height of current node (from leaf)
2. which subtree deepest node lies in


*/
 struct Pair {
    int height;
    TreeNode* node;

    Pair(int h, TreeNode* n) {
        height = h;
        node = n;
    }
 };

class Solution {
public:

    Pair fun(TreeNode* root) {
        if(!root) {
            return Pair(0, root);
        }

        Pair left = fun(root->left);
        Pair right = fun(root->right);

        if(left.height == right.height) { // current node is LCA if both children have same height
            return Pair(left.height+1, root);
        }
        else if (left.height > right.height) {
            return Pair(left.height+1, left.node);
        }
        return Pair(right.height+1, right.node);
    }




    TreeNode* subtreeWithAllDeepest(TreeNode* root) {

        return fun(root).node;
        
    }
};

-------------------


















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
