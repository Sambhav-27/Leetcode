/*
1. From right to left, find the firs dip in numbers. i.e. first i such that a[i] < a[i+1]
2. Find the *rightmost* next greater number of ith number towards right of i.
3. Swap these two
4 sort(i+1, end); // since all numbers to right are in dec order, reversing would be equal to sorting


https://leetcode.com/problems/next-permutation/discuss/13994/Readable-code-without-confusing-ij-and-with-explanation


Test cases:

1152
9560519632
2916732


*/
#define INF 1e8

class Solution {
public:
    void nextPermutation(vector<int>& a) {
        
        int pos = a.size()-1;
        for(int i=a.size()-1; i>=1; --i) {
            if(a[i-1] < a[i]) {
                pos = i-1;
                break;
            }
        }
        
        int nextlarg = pos;
        int nextlargVal = INF;
        for(int i=pos+1; i<a.size(); ++i) {
            if(a[i] > a[pos]) {
                if(a[i] <= nextlargVal) { // we need to find the rightmost greater value, so equal sign
                    nextlargVal = a[i];
                    nextlarg = i;
                }
            }
        }
        
        if(nextlarg == pos) {
            sort(a.begin(), a.end());
            return; // already largest pernutation i.e. desc order
        }
        
        swap(a[pos], a[nextlarg]);
        reverse(a.begin()+pos+1, a.end()); // notice no need of sorting
        // sort(a.begin()+pos+1, a.end());
        
    }
};
