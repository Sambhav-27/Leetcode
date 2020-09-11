#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define INF 1e7

/*
https://leetcode.com/discuss/interview-question/805468/Google-or-OA-or-SDE-(2020)or-India
https://leetcode.com/playground/NehmscKu


Given array A of N Integers a1 ,a2, a3...... aN . You are also given two integers S and M. You can pick subarray of size S where you have to perform M operation by incrementing the value of each element value by 1. Find the maximum value of minimum value in array A.
Example
Input:
N = 6 ,M = 5 ,S =2
1 2 3 4 5 6
Output:
4
Explaination:
1st opertaion subarray index range (0,1) 2 3 3 4 5 6
2nd opertaion subarray index range (0,1) 3 4 3 4 5 6
3rd opertaion subarray index range (0,1) 4 5 3 4 5 6
4th opertaion subarray index range (2,3) 4 5 4 5 5 6
5th opertaion subarray index range (0,1) 5 6 4 5 5 6



*/


int n,m,s,a[N];

// check if it is possible to have minimum value in array = minVal in <= m operation
// 1 operation = increment all elemnts any subarray of size s by 1
/* Every time we take left most element which is not yet >= k and update this element, while updating we know that all elements left to current are >=k . So we use the sub array only to the right thus making this greedy algo optimal.
*/
bool possible(int minVal) {
    
    int i,ans = 0, needed[N] = {0}; // needed[i] will store extra increments required by ith element apart form its neigbors.
    int alreadyIncremented = 0;
    for(i=0; i<n; ++i) {
        
        // remove increments of outside window elements
        alreadyIncremented -= (i-s) >=0 ? needed[i-s] : 0;
        
        if(a[i] + alreadyIncremented > minVal) {
            needed[i] = 0;
        }
        else {
            needed[i] = minVal - a[i] - alreadyIncremented;
        }
        
        alreadyIncremented += needed[i];
    }
    
    for(i=0; i<n; ++i) {
        // cout<<needed[i]<<"  ";
        ans += needed[i];
    }
    
    return ans <= m;
}

int fun() {
    int ans = -INF;
    int i, end, beg = a[0];
    for(i=0; i<n; ++i) {
        beg = min(beg, a[i]);
        end = max(end, a[i]);
    }
    end += m; // end = max elemnt + m
    
    while(beg <= end) {
        int mid = (beg + end)/2;
        
        if(possible(mid)) {
            beg = mid +1;
            ans = max(ans, mid);
        }
        else {
            end = mid -1;
        }
    }
    
    return ans;
}


int main() {
   
  
   cin>>n>>m>>s;
   for(int i=0; i<n; ++i) cin>>a[i];
   
   cout<<fun();
    
    return 0;
}
