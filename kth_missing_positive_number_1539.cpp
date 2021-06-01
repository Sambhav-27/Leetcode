/**
Find min index such that total missing element till that index is >= k

then cal ans from its previous element.

Similar: https://github.com/Sambhav-27/Leetcode/blob/master/Kth_Missing_Element_In_Array_Premium.cpp
*/

class Solution {
public:
    int getCount(vector<int>& a, int i) {
        return a[i] - 1 - i; // if we want to check from a[0] then a[i] - a[0] - i
    }
    
    
    int findKthPositive(vector<int>& a, int k) {
        
        int n = a.size();
        int b = 0;
        int e = n -1;
        
        // check if after last element
        if(k > getCount(a, n-1)) {
            return a[n-1] + k - getCount(a, n-1);
        }
        
        // check if before first element
        if(a[0] > k) {
            return k;
        }
        
        int ans;
        
        while(b <= e) {
            int m = b + (e-b)/2;
            
            int diff = getCount(a, m);
            
            if(diff < k) {
                b = m+1;
            }
            else {
                ans = m;
                e = m-1;
            }
        }
        
        // we alread checked for first element, so ans-1 is safe
        return a[ans-1] + k - getCount(a, ans-1);        
        
    }
};
