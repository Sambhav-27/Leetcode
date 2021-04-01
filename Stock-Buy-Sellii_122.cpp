/**

If at any point there is a dip in price; a(i+1) < a(i)
sell previously owned on ith day & buy next on i+1th day

*/

class Solution {
public:
    int maxProfit(vector<int>& a) {
        
        int prev = a[0];
        int ans =0;
        for(int i=0; i<a.size()-1; ++i) {
            if(a[i] > a[i+1]) {
                ans += a[i]- prev;
                prev = a[i+1];
            }
        }
        
        // don't forget this
        if(a[a.size()-1] > prev)
        ans += a[a.size()-1]-prev;
        return ans;
    }
};
