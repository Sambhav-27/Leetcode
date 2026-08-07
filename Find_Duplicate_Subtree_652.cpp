/*
Core idea — serialize every subtree, then count. Two subtrees are duplicates if and only if their structures and values are identical.
So if we can turn each subtree into a unique string that fully captures its shape and values, then "find duplicate subtrees" becomes
"find serialized strings that occur more than once" — just a hashmap count.


Complexity: O(n²) time in the worst case — building each serialization string can take O(n) due to string concatenation, across O(n) nodes.
Using integer IDs per unique serialization (map each distinct string to a small int, then serialize using the IDs of children
instead of full strings) brings the per-node cost down to O(1), giving O(n) time, O(n) space overall


unordered_map<string, int> idMap;  // string to id map;
function will return id instead of string in this case


*/



/*

Traverse the tree in bottom up manner & store every subtree in a map.
How do we store a subtree?
We store it in serialized form as string.

If at any point we see that a string has multiple nodes then that means it is a duplicate.

Serialized string is also calculated in the same function.

*/

class Solution {
public:
    unordered_map<string, vector<TreeNode*>> m;
    
    // return serialized string of this tree
    string fun(TreeNode* root) {
        if(!root) {
            return "$"; // marked for null nodes
        }
        
        string left = fun(root->left);
        string right = fun(root->right);
        
        // we need # so that right of cur node doesn't get mixed with left of next node
        string cur = "#" + left + to_string(root->val) + right + "#";
        m[cur].push_back(root);
        return cur;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans;
        fun(root);
        for(auto kv: m) {
            if(kv.second.size() > 1) {
                ans.push_back(kv.second[0]);
            }
        }
        return ans;
    }
};
