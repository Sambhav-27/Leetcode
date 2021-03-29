// just like merging overlapping intervals
// remember input intervals are non overlapping and we need to merge all intervals with which cur overlaps.

class Solution {
public:
    
    bool isOverlapping(vector<int> a, vector<int> b) {
        if(a[1] < b[0] || b[1] < a[0])
            return 0;
        return 1;
    }
    vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& cur) {
        vector<vector<int>> ans;
        
        for(int i=0; i<a.size(); ++i) {
            if(isOverlapping(a[i], cur)) {
                cur[0] = min(a[i][0], cur[0]);
                cur[1] = max(a[i][1], cur[1]);
            }
            else {
                if(cur[1] < a[i][0]) {
                    ans.push_back(cur);
                    cur = a[i];
                }
                else {
                    ans.push_back(a[i]);
                }
            }
        }
        
        ans.push_back(cur); // don't forget this
        return ans;
    }
};
