/*
Just like 0 sum subarray.
If we have seen this sum already at index i;
and current index is j
then subarray from i+1 to j must have a sum of 0

Test cases:
[0,0] 0
[1,2,3] 0
[1,2,3] 1

*/

class Solution {
public:
    bool checkSubarraySum(vector<int>& a, int k) {
        unordered_map<int, int> m;
        
        m[0] = -1; // don't forget this to take into account of first element
        
        if(k==0) { // check if there is a subarray of sum 0
            int sum =0;
            for(int i=0; i<a.size(); ++i) {
                sum += a[i];

                if(m.find(sum) != m.end()) {
                    int j = m[sum];
                    if(i-j >= 2)
                        return 1;
                }
                else m[sum] =i;
            }
            return false;
        }
        
        int sum =0;
        for(int i=0; i<a.size(); ++i) {
            sum += a[i];
            
            if(m.find(sum%k) != m.end()) {
                int j = m[sum%k];
                if(i-j >= 2)
                    return 1;
            }
            else  // we want subarryay of size 2, so if already seen this sum, we don't want to update that value with the new one.
            m[sum%k] =i;
        }
        return 0;
    }
};
