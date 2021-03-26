/*

Notice the fact that intervals in a list will be non-overlapping & sorted.
Just an immpl of 2 pointer approach


*/

class Solution {
public:
    bool isOverlapping(vector<int> a, vector<int> b) {
        if(a[1] < b[0] || b[1] <a[0])
            return false;
        return true;
    }
    
    vector<vector<int>> intervalIntersection(vector<vector<int>>& a, vector<vector<int>>& b) {
        vector<vector<int>> ans;
        int i=0,j=0;
        
        int n=a.size(),m=b.size();
        
        while(i<n && j<m) {
            if(isOverlapping(a[i], b[j])) {
                vector<int> cur;
                cur.push_back(max(a[i][0], b[j][0])); // 0 is start
                cur.push_back(min(a[i][1], b[j][1])); // 1 is end
                ans.push_back(cur);
                
                if(a[i][1] < b[j][1]) {
                    i++;
                }
                else {
                    j++;
                }
            }
            else {
                if(a[i][1] < b[j][0]) {
                    i++;
                }
                else {
                    j++;
                }
            }
        }
        return ans;
        
    }
};
