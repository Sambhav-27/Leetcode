/**

Leetcode 1055: Shortest way to form string
Given 2 strings- src and target
Find the min number of subsequences of src that must me concatenated to form target.
Ex: src = "lan"; target = "allan"
ans = 3; // a + l + lan


Asked multiple times in Google phone screen
https://leetcodex.xyz/discuss/interview-question/algorithms/177090/google-phone-screen-shortest-way-to-form-string
https://leetcode.com/discuss/interview-question/358669/google-shortest-way-to-form-string

https://medium.com/swlh/google-interview-question-leetcode-1055-7670fbaf5bd3

O(n^2 solution)
Traverse target string and check if each character is in src after the index at which the previous character was found; If string ends then start again from src
ex: src = lan; target = allan

a found at index 1
then search for l after index 1. not found; set index = 0 and search again;
found at index =0; 
then search for 2nd l after index 0; not found; set undex = 0 and search again;
found at index 0
.. and so on


---------------------------------------------------------------------------


n = src.length    m = dst.length

Time: O(m + n*26); Space: O(n*26)


Problem with above approach is that for every character in dst => we are traversing the src again 
to find the first occurrence of that char after the index at which previous char was found

What if we can find this in O(1) then time complexity reduces to O(m);

in other words: Given an index i, and a char ch, we need to find the first occurence of ch in src after i

So, at every index we store the first occurrence of every character after that index.
Ex: src = lan

then this map will be as
0 => l:0  a:1   n:2;           rest all characters have -1 as index
1 => a:1  n:2
2 => n:2


How to form this map?
Traverse src from right to left;
and map of pos i can be obtained from map of pos i+1 by just updating the pos of cur char.
Also, traversing from right makes sure that overwriting a characer's position means we are storing its first occurrence from left.


After generating this map, run the above O(n^2) algo and instead of traversing just get the postion from the map as m[i][ch]

If at any step we are unable to find the character, we reset index to 0.
But if index was already 0, that mean char is not present in src and we return -1;


*/


#define N 26

class Solution {
public:
    
    int fun(string src, string dst) {
        int n = src.length();
        
        // this is our array of map
        vector<vector<int>> f(n);
        
        vector<int> temp(N, -1);
        for(int i=n-1; i>=0; --i) {
            temp[src[i]-'a'] = i;
            
            f[i] = temp;
        }
        
        
        int ans = 1; // ans is 1 for two equal strings
        int prevPos=0;
        for(int i=0; i<dst.length(); ) {
            char ch = dst[i];
            
            if(f[prevPos][ch-'a'] != -1) {
                prevPos = f[prevPos][ch-'a'] +1;
                ++i;
            }
            else {
                if(prevPos == 0) { // if we already searched from starting then this letter is not present
                    return -1;
                }
                prevPos=0;
                ans++;
            }
        }
        
        return ans;
    }
    
    
    int main(string src, String dst) {
        int ans = fun("lan", "allan");
        return ans;
    }
};
