/*

https://leetcode.com/problems/heaters/


Don't assume array is sorted.

1st soln: Binary search. Try to reduce r;

2nd soln: 
for every house, find distance to first heater on left, and right.

Ans = max(min(lr[i], rl[i])) for all i

nlogn for sorting, rest all is O(n)


https://leetcode.com/problems/heaters/discuss/95887/C%2B%2B-clean-solution-with-explanation

*/

#define INF 2e9

class Solution {
public:
    int findRadius(vector<int>& a, vector<int>& heaters) {
        sort(a.begin(), a.end());
        sort(heaters.begin(), heaters.end());
        
        int i,n = a.size();
        
        vector<int> lr(n, INF), rl(n, INF);
        
       
        i=0;
        for(int j=0; j<heaters.size() ; ++j) { // notice traversing left to right but filling rl
            while(i<n && a[i] <= heaters[j]) {
                rl[i] = heaters[j] - a[i];
                i++;
            }
        }
        
        i=n-1;
        for(int j=heaters.size()-1; j>=0; --j) {
            while(i>=0 && a[i] >= heaters[j]) {
                lr[i] = a[i] - heaters[j];
                i--;
            }
        }
        
        
        

        
        int ans = 0;
        for(int i=0; i<n; ++i) {
            ans = max(ans, min(lr[i], rl[i]));
        }
        
        return ans;
        
        
    }
};
