/*

https://leetcode.com/problems/odd-even-jump/

In odd jumps, we can go the next greater or equal element on right;
in Even jumps, we can go the next smaller or equal element on right (just smaller element on right)

So, for every element we want the next greater & next smaller on the right.
We can use stack based approach just like in max hist area.
or,

If we start from right & maintain the elemnts in a sorted order; Then we can find next greater & next smaller in nlogn.


To keep elements in sorted order, we are using a map;
next greater or equal = lower bound
next smaller or equal = previous element of upper bound


Now, we can use dp. For every element we maintain two variables, higher & lower;
indicating if take the next higher elemnt from current, can we reach end.

Thus higher[i] = lower[nextgreater]
lower[i] = higher[nextsmaller]

cause we are alternating high & low jumps.

Now, we want to count total valid starting points;
Since, first jump will be odd, it will be to a higher element.
So, ans = sum of when higher[i] = true



https://leetcode.com/problems/odd-even-jump/discuss/217981/JavaC%2B%2BPython-DP-using-Map-or-Stack

*/

class Solution {
public:
    int oddEvenJumps(vector<int>& a) {
        
        int n = a.size();
        vector<bool> higher(n, false), lower(n, false);
        higher[n-1] = lower[n-1] = true;
        
        map<int, int> m; // val to index
        m[a[n-1]] = n-1;
        
        int ans =1; // cause end is always reachable
        for(int i=n-2; i>=0; --i) {
            auto it = m.lower_bound(a[i]);
            
            int nextgreater = -1, nextsmaller = -1;
            if(it != m.end()) {
                nextgreater = it->second;
            }
            it = m.upper_bound(a[i]);
            if(it != m.begin()) {
                it--;
                nextsmaller = it->second;
            }
            
            // deafult is false
            if(nextgreater != -1) {
                higher[i] = lower[nextgreater];
            }
            if(nextsmaller != -1) {
                lower[i] = higher[nextsmaller];
            }
            
            m[a[i]] = i; // don't forget to put in map
            
            if(higher[i]) // odd jumps. i.e starting from cur element
                ans++;

        }
        return ans;
        
    }
};
