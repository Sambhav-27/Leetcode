/* array elements are distinct.

Test cases:
[3,1] 1   => this shows why equal sign is required


*/

class Solution {
public:

    int search(vector<int>& a, int target) {
        int b = 0;
        int e = a.size()-1;
        
        while(b<=e) {
            int m = (b+e)/2;
            
            if(a[m] == target)
                return m;
            
            if(a[b] <= a[m]) { // left part is sorted // equal sign is required.
                if(a[b] <= target && target <= a[m]) // these equal to signs are required even though array has only distinct elements; cause target can be equal to b or e
                    e = m-1;
                else 
                    b = m+1;
                
            }
            else { // right part is sorted
                if(a[m] <= target && target <= a[e])
                    b = m+1;
                else
                    e = m-1;
            }
        }
        return -1;
        
    }
};
