/*

One simple sol is to check if we can form 1, or 2, or 3... on the upper or lower tiles. O(12n);

Alter solution:

Count freq of each number & see if we can form the required pattern.

*/

#define INF 1e7

class Solution {
public:
    int minDominoRotations(vector<int>& a, vector<int>& b) {
        
        // a and b will be of same size;
        
        int ca[7] = {0};
        int cb[7] = {0};
        int cc[7] = {0}; // required to check if this number can be used
        
        for(int i=0; i<a.size(); ++i) {
            ca[a[i]]++;
            cb[b[i]]++;
            
            if(a[i] == b[i]) {
                cc[a[i]]++; // if both have same then increment only once.
            }
            else {
                cc[a[i]]++;
                cc[b[i]]++;
            }
        }
        
        int ans = INF;
        for(int i=1; i<7; ++i) {
            if(cc[i] < a.size()) {
                continue; // cannot use this number
            }
            
            int x = a.size() - max(ca[i], cb[i]);
            ans = min(ans, x);
        }
        
        if(ans == INF) ans = -1;
        return ans;
    }
};
