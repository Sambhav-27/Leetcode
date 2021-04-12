/*
Generate all unique subsets
Ex: [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]


There are 2 ways:
1. Iterate from 0 to 2^n and put numbers according to the bits of i.
2. backtracking- at every point you can choose this number of not choose this

How to make it unique:
Sort the input first.
Now, if cur element = previous ele & previous element wasn't chosen.
So, don't choose this one also. [Draw a tree and check]

*/

class Solution {
public:
    
    vector<vector<int>> ans;
    vector<int> input;
    
    void fun(int j, vector<int> cur, bool chosen) {
        if(j == input.size()) {
            ans.push_back(cur);
            return;
        }
    
        fun(j+1, cur, false);
        
        if(j>0 && input[j-1] == input[j] && !chosen) // to make it unique
            return;

        cur.push_back(input[j]);
        fun(j+1, cur, true);
        cur.pop_back();
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& a) {
        
        sort(a.begin(), a.end()); // sorting
        input = a;
        vector<int> v;
        fun(0, v, true);
        return ans;
        
    }
};
