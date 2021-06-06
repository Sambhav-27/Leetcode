/**
nlogn
 */
class Solution {
public:
    
    ListNode* getMid(ListNode* head, ListNode* tail) {
        ListNode* s = head;
        ListNode* f = head;
        
        while(f != tail && f->next != tail) {
            s = s->next;
            f = f->next->next;
        }
        return s;
    }
    
    TreeNode* fun(ListNode* head, ListNode* tail) { // tail is actually the end of list; not last node
        if(head == tail)  // notice this
            return NULL;
        
        if(head->next == tail) {
            return new TreeNode(head->val);
        }
        
        ListNode* mid = getMid(head, tail);
        
        TreeNode* root = new TreeNode(mid->val);
        root->left = fun(head, mid);
        root->right = fun(mid->next, tail);
        return root;
        
    }
    TreeNode* sortedListToBST(ListNode* head) {
        return fun(head, NULL);
    }
};
