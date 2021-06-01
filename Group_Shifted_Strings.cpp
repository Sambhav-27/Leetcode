/*
https://xiaoguan.gitbooks.io/leetcode/content/LeetCode/249-group-shifted-strings-medium.html

Notice that consecutive chars of a string need not have same diff.
So, "abx" is a valid input
"abx" "bcy" will go to the same set.


Don't think about Disjoint sets, it will require comparing every string with the other string.
We can do it O(nm); n = total strings. m = avg length of string


The problem looks quite like the grouping anagrams. So the idea is the same: for each string, find out its "original" format,
and add it to that format.

Two strings in same group will have same pattern.

*/

string getPattern(string& s) {
        string key;
  
        for (int i = 1; i < s.length(); ++i) {
            int diff = s[i] - s[i-1];
          
            if (diff < 0) diff += 26; // this is necessary; cause we always subtract first char from second
            
            key += 'a' + diff + '_';
        }
        return key;
    }

vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> m;
  
        for (auto s: strings) {
            m[getPattern(s)].push_back(s);
        }
  
        vector<vector<string>> res;
        for (auto& a: m) {
            res.push_back(a.second);
        }
        return res;
 }
