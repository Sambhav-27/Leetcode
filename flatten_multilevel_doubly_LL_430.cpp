/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
/*
Traverse the list iteratively in horizontal direcn;
If a list has child node, then recursively modify the child node;

Then traverse to the end of list iteratively to get the tail.

Note: time is O(n); At max we are visiting every node twice.


*/


class Solution {
public:

    
    Node* flatten(Node* head) {
        Node * cur = head;
        
        while(cur) {
            
            // no child, just move forward
            if(!cur->child) {
                cur = cur->next;
                continue;
            }
            
            Node* rest = cur->next;
            
            // modify the child recursively
            cur->next = flatten(cur->child);
            cur->next->prev = cur;
            cur->child = NULL;
            
            // get the tail from child
            while(cur->next)
                cur = cur->next;
            
            // attach tail to rest of node
            if(rest) {
                cur->next = rest;
                rest->prev = cur;
            }
            
            cur = rest;
            
        }
        return head;
    }
};
