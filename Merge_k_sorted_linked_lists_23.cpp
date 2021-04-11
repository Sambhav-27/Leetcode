/**
It's easier than merging k sorted arrays, cause here, each popped Node itself holds a pointer to next element.
Time: Nlogk; N = total elements across all lists
Space: log k


Another soln: Divide & conquer like merge sort; Only uses space of recursion
https://leetcode.com/problems/merge-k-sorted-lists/discuss/10610/C%2B%2B-code-O(NlogK)-in-time-O(1)-in-space-Divide_Conquer

Another soln: Just merge first two arrays & push them to the end. Erase first 2 elements.
Keep on doing until there is 1 list left
https://leetcode.com/problems/merge-k-sorted-lists/discuss/10531/Sharing-my-straightforward-C%2B%2B-solution-without-data-structure-other-than-vector


*/

struct comp {
    bool operator()(const ListNode* a, const ListNode* b) {
        return a->val > b->val; // min heap
    }
};

class Solution {
public:
    
    void push(ListNode* &head, ListNode* &tail, ListNode* p) {
        if(!head) {
            head = p;
            tail = p;
            return;
        }
        tail -> next = p;
        tail = p;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode * ans = NULL, *tail = NULL;
        priority_queue<ListNode*, vector<ListNode*>, comp> q;
        
        vector<ListNode*> curs;
        for(auto x: lists) {
            if(x) // apparently null values are comming in input; We don't want them in output
                q.push(x);
        }
        
        while(!q.empty()) {
            ListNode * p = q.top(); q.pop();
            
            push(ans, tail, p);
           
            if(p->next) {
                p = p->next;
                q.push(p);
            }
        }
        return ans;
    }
};
