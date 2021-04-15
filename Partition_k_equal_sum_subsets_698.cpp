/*
We have to put n items in k buckets.
At every step, 1 item has k options to be put into.
Time: k^n


if(arrayssum is not a multiple of k then return false)
if(k > a.size()) return false;

Each bucket will get totalsum/k sum.

Optimisations:
1. if at anytime bucket + a[i] > k then return 0;
So, start by larger numbers first, so that tree is pruned faster.
Thus, sort the array in decreasing order

2. try to put current element in a non empty bucket or first empty bucket. Do not try all empty buckets, cause it's all the same.

Ex- buckets:  a|__|__

put b in either 1st or 2nd bucket

ab|___|__
or a|b|__

as a|__|b is similar to the above bucket.


*/

bool comp(int a, int b) {
    return a >b;
}
class Solution {
public:
    
    vector<int> a;
    int limit;
    
    // bool isEqual(vector<int> & a) {
    //     for(int i=1; i<a.size(); ++i) {
    //         if(a[i] != a[i-1])
    //             return 0;
    //     }
    //     return 1;
    // }
    
    bool fun(int j, vector<int> &bucket) {
        if(j == a.size()) {
            return 1;
            // return isEqual(sums); // no need to add this check, as we are not allowing bucket sum to be greater than k; And bucket sum can't be less than k cause less sum in one bucket means more sum in some otehr bucket.
        }
        
        bool flag = false;
        for(int i=0; i<bucket.size(); ++i) {
            
            if(flag) // empty bucket already encountered; stop trying other empty buckets.
                break;
            if(bucket[i] == 0) {
                flag =1;
            }
            
            if(bucket[i] + a[j] > limit)
                continue;
            
            bucket[i] += a[j];
            if(fun(j+1, bucket))
                return 1;
            bucket[i] -= a[j];

        }
        return 0;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end(), comp);
        a = nums;
        
        int totalsum =0;
        for(auto x: nums)
            totalsum += x;
        
        limit = totalsum/k;
        if(k > nums.size() || totalsum % k != 0)
            return false;
        
        vector<int> buckets(k);
        return fun(0, buckets);
    }
};
