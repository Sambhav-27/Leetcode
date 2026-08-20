/*
Input contains distinct characters;

TC= n! * n 

*/


class Solution {
public:

    vector<vector<int>> ans;
    vector<bool> used;

    void generate(vector<int> &cur, vector<int> & a) {
        if(cur.size() == a.size()) {
            ans.push_back(cur);
            return;
        }

        
        for(int i=0; i<a.size(); ++i) { // notice loops starts from 0; for every position try all characters
            if(used[i]) { // skip characters already used in this recursion stack i.e. don't repeat a character
                continue;
            }

            cur.push_back(a[i]);
            used[i] = true;

            generate(cur, a);

            cur.pop_back();
            used[i] = false;
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> cur;

        used.resize(nums.size(), false);
        generate(cur, nums);

        return ans;
        
    }
};



-------

/*

Input can containn duplicates but output has to contain unique permutations.
e.g. aab; output = aab, aba, baa

TC = n! * n

but The true output size is
    n! / (c1! . c2!. . . ck!)

where 
c1,c2,…,ck are the multiplicities of each repeated character. For "aab" (n=3, one character repeated twice): 
3!/2!=3
3!/2!=3
*/

class Solution {
public:

    vector<vector<int>> ans;
    vector<bool> used;

    void generate(vector<int> &cur, vector<int> & a) {
        if(cur.size() == a.size()) {
            ans.push_back(cur);
            return;
        }

        
        for(int i=0; i<a.size(); ++i) { // notice loops starts from 0; for every position try all characters
            if(used[i]) { // skip characters already used in this recursion stack i.e. don't repeat a character
                continue;
            }

            if(i > 0 && a[i] == a[i-1] && !used[i-1]) { // notice this is counter intuitive; if previous is not used then skip
            // think of it like- always process from left to right; so in "aab" don't process the second 'a' if the previous 'a' wasn't processed.
            // right to left processing is not allowed because we need unique permutations
            // if you skip if previous was used then you will never build a string like "aa"
                continue;
            }

            cur.push_back(a[i]);
            used[i] = true;

            generate(cur, a);

            cur.pop_back();
            used[i] = false;
        }
        
    }


    vector<vector<int>> permuteUnique(vector<int>& nums) {

        vector<int> cur;

        sort(nums.begin(), nums.end());

        used.resize(nums.size(), false);
        generate(cur, nums);

        return ans;
        
    }
};


  
