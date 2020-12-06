/*

1 Max histogram area: https://stackoverflow.com/questions/4311694/maximize-the-rectangular-area-under-histogram

Treat current bar as ht of rectangle, then we just need to find the first smaller element on left & first smaller element on right, and calculate the area.

For finding first smaller element on left & right, we use a stack.
Stack will be in increasing order from bottom to top.
It will store the index of element insted of the actual element cause we need to find the difference in position of two elements. (length of rectangle)

cur element = stack top
first smaller on left, l = 2nd element on stack from top.
first smaller on right, r = cur element(ith)

For finding 2nd element from top, beware that stack can become empty after popping top.

so, ht = a[stack top]
len = r-l-1. Note that firt smaller elements are not included in the rectangle.


Also take care of the case when after traversing all elements, stack is still not empty.
Ex- 3,1,3,2,2

Here, there is no smaller element on the right, so we set r = n(0 based index)



*/

#define N 300

class Solution {
public:
    
    int getArea(int *a, int n) {
        stack<int> s;
        int ans = 0;
        for(int i=0; i<n; ++i) {
            
            while(!s.empty() && a[i] < a[s.top()]) {
                
                int top = s.top(); s.pop();
                int ht = a[top];
                
                int left = -1;
                if(!s.empty())
                    left = s.top();
                int len = i-left-1;  // len = r-l-1

                ans = max(ans, len*ht);
            }
            s.push(i);
        }
        
        while(!s.empty()) {
                
            int top = s.top(); s.pop();
            int ht = a[top];

            int left = -1;
            if(!s.empty())
                left = s.top();
            int len = n-left-1;  // len = r-l-1; notice i is n here

            ans = max(ans, len*ht);
        }
        
        
        return ans;
    }
    
    
};
