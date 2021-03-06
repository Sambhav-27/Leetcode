/*
LIS: 

O(nlogn);

First let's do n^2 soln but with a different dp;
dp[i] will store the element at which lis of i length ends;
And if there are multiple such elements, we choose the smallest one cause later on we can extend the sequence more using the smaller one;

Now, let cur be the cur elemnt
if(dp[i-1] < cur)
dp[i] = min(dp[i], cur)
 
which means that lis of (i-1) length ends at an element which is smaller than the current element;
Thus, lis of i length ends at current element.

Ex: a = 3,1,2,5,4
let's first write a 2 dp;

x = INF

   | 0  1  2  3  4  5
 3 | -x x  x  x  x  x
 1 | -x 1  x  x  x  x
 2 | -x 1  2  x  x  x
 5 | -x 1  2  5  x  x
 4 | -x 1  2  4  x  x
 
 
 i direction are the input array elements
 j direction is the length of lis
 
 Instead of using a 2d array, we can just use a 1d array of length n+1 as we don't need previous rows value to update current row.
 initially, we say lis of length 0 = -INF & lis of all other length = INF
 
 Now, we have a n^2 solution with 1d array;
 
 But notice, the dp array is always sorted after every iteration & in each iteration we are just finding the next greater value of cur
 and updating that posn using the above rule.
 if(dp[i-1] < cur)
dp[i] = min(dp[i], cur)  // here i is the pos of next greater element.

Thus we can use binary search and thus time is nlogn.

https://cp-algorithms.com/sequences/longest_increasing_subsequence.html



Now the current problem;

(w, h)
If we sort by width and then find the lis using height, we have our answer.
But just one caveat- if width of two elements is same then they can't fit each other; it has to be stricly greater.
So, if after sorting by width, we get

(2,4)
(3,5)
(4,6)
(4,7)

Now, if we find lis using height, we get answer as 4. But ans is 3.
We can't choose both (4,6) & (4,7); We have to choose one of them;
So, if place (4,7) before (4,6) lis would choose one of them and we will get the answer as 3.

Thus, if width is same then we sort in desc by height.


*/

#define INF 1e9

struct Box {
    int w,h;
    Box();
    Box(int a, int b) {
        w = a;
        h = b;
    }
};

bool comp(Box a, Box b) {
        if(a.w == b.w) {
            return a.h > b.h;
        }
        return a.w < b.w;
}

class Solution {
public:
    
    int lis(vector<int> a) {
        int n = a.size();
        vector<int> dp(n+1, INF);
        dp[0] = -INF;
        
        for(int i=0; i<n; ++i) {
            int j = upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
            if(j == n+1) { // dp array size is n+1, not n
                continue; // ideally this should not happen
            }
            cout<<"j: "<<j;
            if(dp[j-1] < a[i]) {
                dp[j] = min(dp[j], a[i]);
            }
        }
        
        int ans =0;
        for(int i=0; i<=n; ++i) {
            if(dp[i] < INF) {
                ans = i;
            }
        }
        return ans;
    }
    
    
    int maxEnvelopes(vector<vector<int>>& input) {
        vector<Box> v;
        for(auto b : input) {
            v.push_back(Box(b[0], b[1]));
        }
        
        sort(v.begin(), v.end(), comp);
        
        vector<int> hts;
        for(auto box: v) {
            hts.push_back(box.h);
        }
        
        vector<int> a = {1};
        // cout<<lis(a)<<"  ";
        return lis(hts);
    }
};
