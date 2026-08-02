/**
Good question
https://leetcode.com/problems/find-peak-element/

Binary search works even though array is not sorted.

If mid is not the peak then we will try to go in the direction of increasing peak.
If that peak drops somewhere the element before that is the ans.
Else, if it keeps on increasing then the last element is the answer.

nums[-1] = nums[n] = -∞.

Another simle solution: https://leetcode.com/problems/find-peak-element/discuss/50232/Find-the-maximum-by-binary-search-(recursion-and-iteration)

Since edges are treated as -∞, a peak is guaranteed to exist in any array (even a single-element array, since both neighbors are -∞).

This guarantee lets us binary search: at any index mid, compare it to its neighbor.

If nums[mid] < nums[mid+1], the array is "rising" at mid — there must be a peak somewhere to the right (either it keeps rising until it hits a peak, or it hits the boundary -∞ which forces a peak before it).

If nums[mid] > nums[mid+1], the array is "falling" at mid — there must be a peak at mid or to its left, by the same logic in reverse.

*/

class Solution {
public:
    int findPeakElement(vector<int>& a) {
        
        int b = 0;
        int e = a.size()-1;
        
        while(b < e ) {  // notice no equal to handle for 1 element
            
            if(b+1 == e) { // if array only has 2 elements. This ensure that a[m-1] doesn't result in out of bound exception
                            // because below binary search logic only executes for >=3 elements
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
/*

Why right = mid (not mid - 1) but left = mid + 1?

When nums[mid] > nums[mid+1], mid itself could be the peak — so we can't exclude it. We set right = mid to keep it in range.
When nums[mid] < nums[mid+1], mid is definitely not a peak (its right neighbor is bigger) — so we can safely exclude it and set left = mid + 1
*/
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
