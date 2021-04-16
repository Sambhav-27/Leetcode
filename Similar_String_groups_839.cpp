/**

https://leetcode.com/problems/similar-string-groups/

Just total connected components in graph.
O(n*n *M); M = string length; n = total strings

Can also be done via disjoint sets.
For evry string, check all other strings; If similar mereg.
https://leetcode.com/problems/similar-string-groups/discuss/132374/Short-C%2B%2B-solution-at-220ms-using-disjoint-set

*/

class Solution {
public:
    
    unordered_map<string, bool> visited;
    vector<string> input;
    
    bool isSimilar(string s, string t) {
        if(s.length() != t.length())
            return false;
        
        int diff =0;
        for(int i=0; i<s.length(); ++i) {
            if(s[i] != t[i])
                diff++;
            if(diff > 2)
                return false;
        }
        return true;
    }
    
    void dfs(string v) {
        visited[v] = 1;
        
        for(auto x: input) { // no need to make the graph; we can check here directly
            if(!isSimilar(v, x))
                continue;
            if(!visited[x])
                dfs(x);
        }
    }
    int numSimilarGroups(vector<string>& strs) {
        input = strs;
        
        int ans =0;
        for(auto x: input) {
            if(!visited[x]) {
                ans++;
                dfs(x);
            }
        }
        return ans;
    }
};
