/**

Notice question asks absolute difference.

bottom up:

From every node, we need to return two things: max in the subtree & min in the subtree;
then we calculate at current node;

top down:
we push maxl & minl from every node & then compare; This will require different copies for every path, so pas by value.

*/

#define INF 1e9

class Solution {
public:
    int ans = -INF;
    
    void topdown(TreeNode* root, int minl, int maxl) {
        if(!root)
            return;
        
        minl = min(minl, root->val);
        maxl = max(maxl, root->val);
        
        ans = max(ans, abs(root->val - minl));
        ans = max(ans, abs(root->val - maxl));
        
        topdown(root->left, minl, maxl);
        topdown(root->right, minl, maxl);
    }
    
    pair<int, int> fun(TreeNode* root) {
        if(!root) {
            return {INF, -INF}; // note this
        }
        
        if(!root->left && !root->right) {
            return {root->val, root->val};
        }
        
        auto l = fun(root->left);
        auto r = fun(root->right);
        
        int minl = min(l.first, r.first);
        int maxl = max(l.second, r.second);
        
        ans = max(ans, abs(root->val - minl));
        ans = max(ans, abs(root->val - maxl));
        
        
        return {min(root->val, minl), max(root->val, maxl)};
    }
    
    int maxAncestorDiff(TreeNode* root) {
        ans = -INF;
        // fun(root);
        topdown(root, INF, -INF); // note this
        return ans;
    }
};
