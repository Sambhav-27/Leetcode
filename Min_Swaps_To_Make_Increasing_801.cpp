/*

Why greedy won't work?
 1, 7, 8, 9
 6, 2, 3, 4

Ans is 1 (swap 0th index); But greedy will give 3.
When we are at index 1, we see it doesn't maintain the order & then we will swap. Same for index 2 & 3.

dp.
For every index, we maintain 2 variables-
swap[i] means min swaps required to make the sequecne [0,i] in increasing order given that we must swap ith indices
notswap[i] means min swaps required to make the sequecne [0,i] in increasing order given that we do not swap ith indices

https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/discuss/119879/JavaC%2B%2BPython-DP-O(N)-Solution


*/

#define INF 1e8

class Solution {
public:
    int minSwap(vector<int>& a, vector<int>& b) {
        
        
        int n = a.size();
        vector<int> swap(n, INF), notswap(n, INF);
        
        swap[0] = 1;
        notswap[0] = 0;
        
        for(int i=1; i<n; ++i) {
            if(a[i-1] < a[i] && b[i-1] < b[i]) { // perfect order;
                notswap[i] = notswap[i-1];
                swap[i] = 1+ swap[i-1];
            }
            if(b[i-1] < a[i] && a[i-1] < b[i]) { // we need a swap
                
                // Notice it is another if; else if, won't work cause both conditions can be true; This index is a candiate of swappping & not swapping both
                swap[i]= min(swap[i], 1+notswap[i-1]);
                notswap[i] = min(notswap[i], swap[i-1]);
            }
            else {
                // sequence not possible
            }
        }
        
        
        return min(swap[n-1], notswap[n-1]);
        
    }
};
