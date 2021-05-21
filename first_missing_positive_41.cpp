/*
https://leetcode.com/problems/first-missing-positive/

O(n) time & O(n) space soln is to just keep a map.

O(n) time & O(1) space:
We do not care about numbers <= 0;
Also, duplicates won't be a problem.

traverse the array & swap every number with number at index = a[i]-1
Ex- If a[i] = 5
then swap it with the 5th element (4th index in 0 based)
Keep on swapping like this.

At the end, the element which is not at its place is the answer

Notice that if the array size is n; then the missing elemeny will be in the range [1, n+1]
if a[i] > n+1; we can just ignore it.

*/

class Solution {
public:
    int firstMissingPositive(vector<int>& a) {
        
        int n = a.size();
        
        // this is O(n)
        for(int i=0; i<n; ++i) {
            while(a[i] > 0 && a[i] <= n && a[i] != a[a[i]-1]) { // only for [1 to n] elements
                swap(a[i], a[a[i] -1]);
            }
        }
        
        
        for(int i=0; i<n; ++i) {
            if(i+1 != a[i])
                return i+1; // i+1 is missing; not a[i]
        }
        
        return n+1;
        
    }
};
