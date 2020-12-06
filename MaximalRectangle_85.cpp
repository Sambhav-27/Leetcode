/*

1. See Tushar roy Video
Form a temp array from first row & find the maximum histogram area.
After that add second row to the temp array and then again calculate.
ans = max of all such temp arrays.

2. Max histogram area: https://stackoverflow.com/questions/4311694/maximize-the-rectangular-area-under-histogram

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
    
    int maximalRectangle(vector<vector<char>>& a) {
        
        int i,j,n,m,ans=0;
        n = a.size();
        if(n == 0)
            return 0;
        m = a[0].size();
        
        int temp[N]= {0};
        
        for(i=0; i<n; ++i) {
            for(j=0; j<m; ++j) {
                if(a[i][j] == '0')
                    temp[j] = 0;
                else
                    temp[j]++;
            }
            ans = max(ans, getArea(temp, m));
        }
        
        
        return ans;
    }
};
