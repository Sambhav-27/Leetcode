/*
1. Form a prefix sum array
2. generate a random number between [0, arraySum)
3. Find first greater element than this random number in the prefix array. Return index of this number.

Ex: a =  [1,5,2]
prefix = [1,6,8]

So if random number is betwen [2,5], we return 1
if betwen [6,7] we return 2;

*/

class Solution {
public:
    
    // 1 5 2
    // 1 6 8
    
    vector<int> prefix;
    
    // find first greater element
    int fun(vector<int> a, int k) {
        int b = 0;
        int e = a.size()-1;
        
        while(b<=e) {
            int m = (b+e)/2;
            if(m == 0 && a[m] > k) return m;
            
            if(m >= 1 && a[m-1] <= k && a[m] > k)
                return m;
            
            if(a[m] <= k)
                b = m+1;
            else
                e = m; // notice this
        }
        return -1;
    }
    
     // this also works
    int fun(vector<int> a, int k) {
        int b = 0;
        int e = a.size()-1;
        
        int ans = e+1;
        
        while(b<=e) {
            int m = b + (e-b)/2;
            
            if(a[m] > k) {
                ans = m;
                e = m-1;
            }
            else {
                b = m+1;
            }
        }
        return ans;
    }
    
    Solution(vector<int>& a) {
        
        srand(time(NULL)); // this should be done only once.

        prefix.assign(a.size(), 0);
        prefix[0] = a[0];
        for(int i=1; i<a.size(); ++i)
            prefix[i] = prefix[i-1] + a[i];
    }
    
    int pickIndex() {
        
        
        int arraySum = prefix[prefix.size()-1];
        int randomNum = rand() %arraySum;
        
        return fun(prefix, randomNum);
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
