/*

Average time: logn
worst case time: O(n) for cases like:
[1,1,1,1,1,1,1,1,1,1,3,1] 3

it will always go in the else part & b will be incremente by 1.


test case:
[1,0,1,1,1] 0


https://leetcode.com/problems/search-in-rotated-sorted-array-ii/discuss/28216/Java-1ms-binary-search-solution-with-comments


https://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-rotated-array-with-duplicates/

The idea is the same as the previous one without duplicates. The only difference is that due to the existence of duplicates, arr[low] == arr[mid] could be possible, the first half could be out of order (i.e. not in the ascending order, e.g. {3, 1, 2, 3, 3, 3, 3}) and we have to deal this case separately. 
In that case, it is guaranteed that arr[high] also equal to arr[mid], so the condition arr[mid] == arr[low] == arr[high] can be checked before the original logic, and if so then move left and right both towards the middle by 1 and repeat.
*/

class Solution {
public:
    bool search(vector<int>& a, int target) {
        int b = 0;
        int e = a.size()-1;
        
        while(b<=e) {
            int m = (b+e)/2;
            
            if(a[m] == target)
                return true;
            
            if(a[b] == a[m] && a[m] == a[e]) { // for cases like [1,0,1,1,1]
                b++;
                e--;
                continue;
            }
            
            if(a[b] <= a[m]) {
                if(a[b] <= target && target <= a[m]) // equal sign is required.
                    e = m-1;
                else 
                    b = m+1;
                
            }
            else { 
                if(a[m] <= target && target <= a[e])
                    b = m+1;
                else 
                    e = m-1;
            }
            
        }
        return false;
    }
    
    
    // following code also works
    
    /*
    bool search(vector<int>& a, int target) {
        int b = 0;
        int e = a.size()-1;
        
        while(b<=e) {
            int m = (b+e)/2;
            
            if(a[m] == target)
                return true;
            
            if(a[b] < a[m]) { // left part is strictly sorted
                if(a[b] <= target && target <= a[m]) // equal sign is required.
                    e = m-1;
                else 
                    b = m+1;
                
            }
            else if(a[m] < a[e]) { // right part is strictly sorted
                if(a[m] <= target && target <= a[e])
                    b = m+1;
                else 
                    e = m-1;
            }
            else { // for cases like [1,0,1,1,1] 0; 
                if(a[b] == target) // start can be target
                    return true;
                b++;
            }
        }
        return false;
    }
    
    */
};
