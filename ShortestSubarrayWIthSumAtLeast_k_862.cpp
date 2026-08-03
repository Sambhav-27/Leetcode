
/**

1. Convert array to prefix sum array.
2. Find 2 index j and i such that j< i and a[i] - a[j] >=k; Use deque for this.


q is in increasing order from front to back

Elements always insert at the back. And removed from the back too to maintain monotonicity.

q front is only used for comparing with answer. if it's a valid comparison then we pop from the front too.

1. check validity. Compare current element with q front (the oldest element). If valid then add to answer, and pop to give other elements a chance.

2. add/remove from the back to maintain monotonicity.

e.g.,      2 -1 5 -2 5     k = 8
prefix = 0 2 1 6 4 9 




**/


#define INF 1e6
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {

        deque<int> q;
        vector<int> a; // to store prefix;
        a.push_back(0); // notice this. first element is 0 

        for(int i=0; i<nums.size(); ++i) {
            a.push_back(a[i] + nums[i]);
        }


        int ans = INF;

        for(int i=0; i<a.size(); ++i) {

            // compare current with q front
            while(!q.empty() && a[i] - a[q.front()] >= k) {
                ans = min(ans, i-q.front());
                q.pop_front();
            }

            // maintain monotonicity by comparing with back
            while(!q.empty() && a[i] < a[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
        }

        if(ans == INF) {
            return -1;
        }
        return ans;






        


        
    }
};






-----------------------------
    

/**

https://medium.com/@hch.hkcontact/goldman-sachs-top-50-leetcode-questions-q12-shortest-subarray-with-sum-at-least-k-d17e99ece755
https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/discuss/204290/Monotonic-Queue-Summary

If the array contains only positive numbers then we can use window strategy. But in this case, it contains negative numebrs also.
So, when we try to reduce the window size by incrementing left pointer, we are not sure that it will decrease the sum of the window, it can increase it also.

To solve this we operate on the prefix sum of the array.
Ex:           2 -1 1 3
Prefix:     0 2  1 2 4

Now for every ith element, if we can find the nearest smaller element by k on the left then we have found a window.
In other words: a[j] <= a[i] -k   ; For every i we need to find this j; and j<i


Now, we use a deque which is sorted in increasing order from back to front.
And we compare the current element, with each element from the back of the q, and keep on popping until element at back of q is <= a[i]-k


Ex: Let prefix array= 0,6,3,2,4,5,6,10,11,12,4,5,6,7; K = 8

q = 0,6
Now comes 3,
we pop 6 and push 3; 6 was useless because if later on some element can form a 'atleast k sum subarray' then it can also form that subarray with window start at 3; And size of this window will be smaller.
Say later on, we found 10 then 10-6 is 4 and 10-3 is 7 and this 7 will always be greater than 4.


Doing so, q becomes = 0,2,4,5,6
Now comes 10.
We compare 10 with back of queue i.e. 0; 10-0 is greater than k, so we pop and update the answer
then we compare 10 and 2; and again update the answer.

This 0 is popped because it becomes useless as after comparing with current element, it will only increase the window size for further elements.

*/

#define pb push_back
#define INF 1e9

class Solution {
public:
    
    int fun(vector<int>& a, int k) {
        deque<int> q; // stores index
        
        int i,n= a.size();
        vector<int> prefix;
        
        prefix.pb(0);
        for(i=0; i<n; ++i) {
            prefix.pb(prefix[i] + a[i]);
        }
 
        q.push_back(0); // don't forget this when only first element forms the sum
        int ans = INF;
        for(i=1; i<=n; ++i) { // prefix array starts from 1, it has extra 0 at beginning
            
            while(!q.empty() && prefix[q.front()] >= prefix[i])
                q.pop_front();
            
            q.push_front(i);
            
            // comparing from back of q
            while(!q.empty() && (prefix[i] - prefix[q.back()] >= k)) {
                ans = min(ans, i-q.back());
                q.pop_back();
            }
        }
        
        if(ans == INF)
            ans = -1;
        return ans;
    }
    
    int shortestSubarray(vector<int>& a, int k) {
        
        return fun(a, k);
        
    }
};
