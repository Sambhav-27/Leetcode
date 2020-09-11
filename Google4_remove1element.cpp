You are given an array of N elements. You are allowed to delete at maximum one element from the provided array. 
The order of elements remains the same in the resultant array. You are required to maximize the number of subarrays 
that contain both maximum and minimum elements of the resultant arary.
Constraints
N = 10^5


https://leetcode.com/discuss/interview-question/805468/Google-or-OA-or-SDE-(2020)or-India


Q2, Intuitive O(n) solution even with duplicates:
Removing 1 element = checking in subarray of size n-1;

For every subarray of size n-1, find index of max & min element.

say array is

2 3 8 3 4 1 5 7 6 9
and we are considering only first n-1 elements, then
total elements on left of max element = 2
total elements on right of min element = 3

so total subarrays that contains these two elements = 2 * 3 = 6.
Same applies for if min element occurs before max element. This is O(1) operation after generating the max & min elements.

Do this for every subarray of size n-1, and take their max. Since, it's at max 1 element, we need to do this check for the whole array also.


Alternatively:


Notice that if we don't delete the largest/smallest term from the sequence then the smallest/largest term will remain in the sequence, 
so you can't increase the number of good subarrays. So you'll have only 3 options: not delete any term, delete the largest term, delete the smallest term.


v.erase(find(v.begin(), v.end(), a[pos]));




see 
gerrob@ answer
