// when both nodes are guaranteed to be present in the tree

TreeNode* lca(TreeNode * root, TreeNode *p, TreeNode *q) {
        if(!root) {
            return NULL;
        }
        
        if(root->val == p->val || root->val == q->val)
            return root;
        
        auto l = lca(root->left, p, q);
        auto r = lca(root->right, p, q);
        
        if(l && r)
            return root;
        if(l)
            return l;
        return r;
}




// lca in bst; both nodes guaranteed to be present
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return NULL;
        
        if(root == p || root == q)
            return root;
        
        if(p->val < root->val && root->val < q->val)
            return root;
        
        if(q->val < root->val)
           return lca(root->left, p, q);
        else 
           return lca(root->right, p, q);
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val > q->val) {
            swap(p, q);
        }
        return lca(root, p, q);
    }



// lca with parent pointer; It's like intersection of two linked lists
// https://www.lintcode.com/problem/474/
 int fun(ParentTreeNode* head, ParentTreeNode* root) {
        int c =0;
        while(head != root) {
            c++;
            head = head->parent;
        }
        return c;
    }
    ParentTreeNode * lowestCommonAncestorII(ParentTreeNode * root, ParentTreeNode * headA, ParentTreeNode * headB) {
        int l1 = fun(headA, root);
        int l2 = fun(headB, root);
        
        if(l2 > l1) {
            swap(l1, l2);
            swap(headA, headB);
        }
        
        int diff = l1 - l2;
        while(diff--) {
            headA = headA ->parent;
        }
        
        while(headA != root && headB != root) {
            if(headA == headB)
                return headA;
            headA = headA->parent;
            headB = headB->parent;
        }
        return root;
    }





// lca when nodes may not be in the tree

/*
Nodes may or may not be in the tree
https://www.lintcode.com/problem/578/

Another O(2n) soln is to first check the nodes in one traversal & then regular lca.

*/

class Solution {
public:
    int found = 0;

    TreeNode* lca(TreeNode * root, TreeNode *p, TreeNode *q) {
        if(!root) {
            return NULL;
        }
        
        if(root == p || root == q) {
            found++;
            // even if we found a node, we cannot return it as a lca cause then found will be 1; we still need to 
            // search the rest of tree for the other node.
            if(found == 2)
                return root;
        }
                
        
        auto l = lca(root->left, p, q);
        auto r = lca(root->right, p, q);
        
        // now, we have already traversed the subtree of root, so if root mathces any of the nodes, we can return 
        // from here that this node is the lca.
        if(l && r || root == p || root == q)
            return root;
        if(l)
            return l;
        return r; // if r is NULL, we need to return NULL; this statement covers that also
    }
    TreeNode * lowestCommonAncestor3(TreeNode * root, TreeNode * A, TreeNode * B) {
        found = 0;
        TreeNode* ancestor = lca(root, A, B);
        if(found < 2)
            return NULL;
        return ancestor;
    }
};












