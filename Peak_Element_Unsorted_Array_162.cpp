/**
Good question
https://leetcode.com/problems/find-peak-element/

Binary search works even though array is not sorted.

If mid is not the peak then we will try to go in the direction of increasing peak.
If that peak drops somewhere the element before that is the ans.
Else, if it keeps on increasing then the last element is the answer.

nums[-1] = nums[n] = -∞.

Another simle solution: https://leetcode.com/problems/find-peak-element/discuss/50232/Find-the-maximum-by-binary-search-(recursion-and-iteration)
*/

class Solution {
public:
    int findPeakElement(vector<int>& a) {
        
        int b = 0;
        int e = a.size()-1;
        
        while(b < e ) {  // notice no equal to handle for 1 element
            
            if(b+1 == e) { // if array only has 2 elements.
                return a[b] > a[e] ? b : e;
            }
            
            int m = b + (e-b)/2;
                
            if(a[m-1] < a[m] && a[m] > a[m+1] )
                return m;
            
            if(a[m-1] > a[m]) { // go in the direction of increasing slope.
                e = m-1;
            }
            else {
                b = m+1;
            }
        }
        return b; // notice this
    }
    
    // this also works
    int findPeakElement(vector<int>& a) {
        
        int b = 0;
        int e = a.size()-1;
        
        int ans = b;
        while(b < e ) {  // notice no equal
            
            int m = b + (e-b)/2;
            
            if(a[m] < a[m+1]) {
                ans = m+1;
                b = m+1;
            }
            else {
                e = m;
            }
        }
        return ans; 
    }
};
