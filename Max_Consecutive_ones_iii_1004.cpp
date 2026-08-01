/*

Window strategy;
Expand the window to right, until the k+1th zero & then compress from left until next zero.

Was difficult to implement.

O(n)


*/

class Solution {
public:
    int longestOnes(vector<int>& a, int k) {

        int l=0, r =0;
        int ans = 0;
        int consumed = 0;

        while(r < a.size()) {
            if(a[r] == 1) {
                r++;
            }
            else if (a[r] == 0) {
                if(consumed < k) { // expand while you can
                    consumed++;
                    r++;
                }
                else { // shrink
                    ans = max(ans, r-l);
                    while (l<=r) {
                        if(a[l] == 1) {
                            l++;
                        }
                        else if (a[l] == 0) {
                            consumed --;
                            l++; break;
                        }
                    }
                }

            }
        }
        ans = max(ans, r-l); // don't forget this; this is required if we never shrink
        return ans;
        
    }
};

// ----------------

class Solution {
public:
    int longestOnes(vector<int>& a, int k) {
        
        int i,j,l,r,n=a.size();
        
        // 1101001; k=2
        
        l=r=0;
        int cur = 0;
        int ans = 0;
        if(a[0] == 0)
            cur=1;
        while(l<n && r<n) {
            
            
            if(cur <= k) {
                r++; // increment r; because currently r points to previous zero
                while(r < n) {
                    if(a[r] == 0)
                        cur++;
                    if(cur == k+1) break;
                    r++;
                }
                
               
            }
            else {
                while(cur > k && l <=r) {
                    if(a[l] == 0)
                        cur--;
                    l++;
                }
                
            }
            ans = max(ans, r-l);
        }
        
        return ans;
    }
};
