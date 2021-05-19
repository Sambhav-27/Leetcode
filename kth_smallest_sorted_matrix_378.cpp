/**
https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
Good quesion.
Notice that matrix is sorted both row & column wise.

Another similar question-
kth smallest in an unsorted array.
For that, we use a max heap solution. Or Quick select.


Notice in this question, we don't need max heap. We need min heap.

1. Make a min heap of size k.
2. Put 0th element of first min(k,n) rows in the heap.
3. Now pop k times from the heap. Kth popped element is our answer. In every pop, we push the next element from the row of the popped element.




Time: k log(min(n,k))

*/


struct Node {
    int val, r;
    Node() {}
    Node(int val, int r) : val(val), r(r) {}
};

struct comp {
    bool operator() (const Node& a, const Node& b) {
        return a.val > b.val; // min heap
    }
};

class Solution {
public:
    
    
    int kthSmallest(vector<vector<int>>& a, int k) {
        int n = a.size();
        int m = a[0].size();
        
        vector<int> pos(n, 0); // stores column pointer for every row
        
        priority_queue<Node, vector<Node>, comp> q;
        
        for(int i=0; i<k && i<n; ++i) { // notice this, we only need to put k elements
            q.push(Node(a[i][0], i));
            pos[i] = 1;
        }
        
        int c = 0;
        while(!q.empty()) {
            Node p = q.top(); q.pop();
            
            if(++c == k) {
                return p.val;
            }
            if(pos[p.r] < a[p.r].size()) {
                int val = a[p.r][pos[p.r]];
                q.push(Node(val, p.r));
                pos[p.r]++;
                    
            }
        }
        
        return -1;
    }
};
