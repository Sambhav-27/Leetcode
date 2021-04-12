/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    void rev(ListNode* head, ListNode* &temp) {
        if(!head)
            return;
        
        if(!head->next) {
            temp = head;
            return;
        }
        rev(head->next, temp);
        
        head->next->next = head;
        head->next = NULL;
    }
    
    ListNode* iterative(ListNode* head) {
        ListNode* prev = NULL;
        ListNode *cur = head;
        
        while(cur) {
            ListNode* next = cur->next;
            cur->next = prev;
            
            prev = cur;
            cur = next;
        }
        return prev;
    }
    
    ListNode* reverseList(ListNode* head) {
        // ListNode* temp = head;
        // rev(head, temp);
        // return temp;
        
        return iterative(head);
    }
};
