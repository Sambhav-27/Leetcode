
1. input: 2d matrix of 0 & 1
output: max size submatrix composed of only 1s

if(a(i,j) == 0)
dp(i,j) =0
else
dp(i,j) =1 +max(left, up, diagonal)


2. input 2d matrix of 0 & 1
ouput: max rectangle composed of only 1s
Add first row to a array and then find max hist area & then keep on adding subsequent rows to that array; 
if a[i,j] == 0
then temp[i] = 0;
else temp[i]++;
https://github.com/Sambhav-27/Leetcode/blob/master/MaximalRectangle_85.cpp

O(n*n)


3. max sum rectangle less than k
Use approach of 2d kadane's algo, then in the 1d array formed find max sum less than k in nlogn.(Using Prefix sum & lower_bound)
So total time = m*m *nlogn
https://github.com/Sambhav-27/Leetcode/blob/master/MaxSumRectangleLessThank_363.cpp


4. max sum submatrix


5. max sum rectangle
2d kadane; O(n*n*m)


============================================================================

1. Remove min number of parenthesis, so that resultant string is valid. Return that string.
Input: "lee(t(c)o)de)"
Output: "lee(t(c)o)de" or "lee(t(co)de)"
https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/


2. Return the longest valid parenthesis in a string. No removals.
Input: ())((()))
Output: ((()))
https://github.com/Sambhav-27/NerdGuide/blob/master/longets_valid_paranthesis.txt

3. Remove min number of parenthesis, so that resultant string is valid. Return all these valid strings.
Input: "()())()"
Output: ["(())()","()()()"]

Note that () is not a valid output cause it removes more than necessary part.
https://leetcode.com/problems/remove-invalid-parentheses/


==========================================================================


