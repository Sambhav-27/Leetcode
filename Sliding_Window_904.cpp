/**

Max window with at most 2 distinct elements;

Sliding window approach;

Instead of keeping a freq[N] array, we are keeping a map cause we need to count elemnts having >0 freq;
In freq, we have to traverse the whole array; In map we can just get size of map;

 we need to count the elements having frequ>0, so instead of an array, we keep a map & take its size; when  frequ of any element becomes 0, we delete it from the map.

*/

class Solution {
public:
    
    bool check(unordered_map<int, int> &f) {
        return f.size() > 2;
    }
    
    int totalFruit(vector<int>& a) {
        
        int ans = 1;
        int n = a.size();
        int l = 0, r =0;
        
        
        unordered_map<int, int> f; // value to their frequency // this is good
        f[a[0]]++;
        
        while (r< n) {
            while(l<= r && check(f)) {
                f[a[l]]--;
                if(f[a[l]] == 0) { // we need to count the elements having frequ>0, so instead of an array, we keep a map & take its size; when  frequ of any element becomes 0, we delete it from the map.
                    f.erase(a[l]);
                }
                l++;
            }
            
            ans = max(ans, r-l+1);
            ++r;
            if(r < n) {
                f[a[r]]++; // here we don't know whether sequence became invalid again, hence, we calculate answer before it
            }
        }
        
        return ans;
    }
};
