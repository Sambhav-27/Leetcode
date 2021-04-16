class Solution {
public:
    
    int fun(vector<int> &a) {
        int n = a.size();
        
        int l = 0, r= n-1;
        int ans =0;
        int maxlevel = 0;
        while(l <= r) {
            int ht;
            if(a[l] < a[r]) {
                ht = a[l++];
            }
            else {
                ht = a[r--];
            }
            
            maxlevel = max(maxlevel, ht); // min of max ht on left & right including self
            ans += maxlevel - ht;
        }
        return ans;
            
            
    }
    
    int trap(vector<int>& a) {
        
        return fun(a);
        
        int ans =0;
        int n = a.size();
        
        if(n < 1)
            return 0;
        
        vector<int> left(n);
        vector<int> right(n);
        
        left[0] = a[0];
        
        for(int i=1; i<n; ++i) {
            left[i] = max(left[i-1], a[i]);
        }
        
        right[n-1] = a[n-1];
        for(int i=n-2; i>=0; --i) {
            right[i] = max(a[i], right[i+1]);
        }
        
        
        for(int i=0; i<n; ++i) {
            ans += min(left[i], right[i]) - a[i];
        }
        return ans;
        
    }
};
