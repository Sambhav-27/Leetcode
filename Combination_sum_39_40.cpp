// input doesn't have duplicates
// one number can be picked any number of times.

#define pb push_back

class Solution {
public:
    
    vector<int> a;
    int tar;
    vector<vector<int>> ans;
    
   
    void fun(int j, int sum, vector<int> cur) {
        if(sum == tar) {
            ans.pb(cur);
            return;
        }
        if(sum > tar) {
            return;
        }
        
        for(int i=j; i<a.size(); ++i) { // doesn't start from 0 because ordering doesn't matter here;
                            // i.e. in  [2,3,6,7]; when 3 is picked you don't want to pick 2 in next iteration because [2,3] had already been previously picked
            sum += a[i]; // this is not aggregating; notice that it gets reset after the recursive call;
                        // so [2,3,6,7] when 3 is picked, 2 is not in the current sum
            cur.pb(a[i]);
            
            fun(i, sum, cur);
            
            cur.pop_back();
            sum -= a[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& input, int target) {
        a = input;
        tar = target;
        
        ans.clear();
        vector<int> v;
        fun(0, 0, v);
        return ans;
    }
};






// input has duplicates.
// one number can be picked only once.
// duplicates not allowed in output

/*

[1,1,2] tar = 3
ans = [1,2]

[1,1,2] tar = 4
ans = [1,1,2]

[10,1,2,7,6,1,5] tar = 8
ans = [[1,1,6],[1,2,5],[1,7],[2,6]]

Notice that [2,1,5] is a duplicate answer

*/

#define pb push_back

class Solution {
public:
    
     vector<int> a;
    int tar;
    vector<vector<int>> ans;
    
   
    void fun(int j, int sum, vector<int> cur) {
        if(sum == tar) {
            ans.pb(cur);
            return;
        }
        if(sum > tar) {
            return;
        }
        
        for(int i=j; i<a.size(); ++i) {
            if(i>j && a[i] == a[i-1]) continue;
            
            sum += a[i];
            cur.pb(a[i]);
            
            fun(i+1, sum, cur);
            
            cur.pop_back();
            sum -= a[i];
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& input, int target) {
        sort(input.begin(), input.end());
        
        a = input;
        tar = target;
        
        ans.clear();
        vector<int> v;
        fun(0, 0, v);
        return ans;
        
    }
};
