/*
https://www.geeksforgeeks.org/number-subarrays-sum-exactly-equal-k/

Maintain a map which will store count of cur sum occurred in the past;

so add to answer how many times curSum-k occurred in the past.
*/
class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
        
        unordered_map<int, int> m; // sum vs number of times it occurred.
        m.insert({0,1});
        
        int sum = 0;
        int ans = 0;
        for(auto x: a) {
            sum += x;
            
            ans += m[sum-k];
            m[sum]++;
        }
        return ans;
    }
};
