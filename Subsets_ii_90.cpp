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


Look at this to understand the uniqueness condition https://github.com/Sambhav-27/Leetcode/blob/master/Permutations.cpp

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


----------


    class Solution {
public:
    
    // if ith bit is set in num then include ith number from array in this subset.
    // with this logic, number of elements in array has to be < 32
    vector<int> generateOneSubset(vector<int> &a, int n) {
        vector<int> subset;
        for(int i=0; i<31; ++i) {
            if(n & (1<<i)) { // this just checks if ith bit is set in n; if set then include this number in output
                subset.push_back(a[i]); // this doesn't result in index our of bound because n is bounded by 2^a.size()
            }
        }
        return subset;
    }
    
    vector<vector<int>> ans;
    vector<int> input;
    
    void fun(int j, vector<int> cur) {
        if(j == input.size()) {
            ans.push_back(cur); // only add to answer when it reaches end; because you add to answer when for all
                            // elements you have made a decision to whether choose it or not choose it (i.e. only at leaf node of tree)
            return;
        }

        // choose this
        cur.push_back(input[j]);
        fun(j+1, cur);
        cur.pop_back();
        
        // or don't choose this
        fun(j+1, cur);
    }
    
    vector<vector<int>> subsets(vector<int>& a) {

//         int n = pow(2, a.size());
//         vector<vector<int>> ans;
//         for(int i=0; i<n; ++i) { // notice n = 2^a.size()
//             ans.push_back(generateOneSubset(a, i));
//         }
//         return ans;
        
        input = a;
        vector<int> v;
        fun(0, v);
        return ans;
    }
};
