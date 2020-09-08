#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define pb push_back
#define INF 1e9


/*

LIS: O(nlogn)
https://cp-algorithms.com/sequences/longest_increasing_subsequence.html#toc-tgt-9
dp[i] =  stores element at which 'i' length subsequence terminates.


LCS is done in O(n^2) using dp.
But if array has distinct elements then it can be converted to LIS problem and can be solved in nlogn

say Array A has distinct elements;
then form array C as: for every element of B, find it's location in A and then store that location(index) in C.

Now finding LIS will give LCS of A & B.

https://leetcode.com/discuss/interview-question/833119/Google's-Online-Challenge-Coding-SWE-New-Grad-2021-(India)
https://stackoverflow.com/questions/30768610/finding-longest-common-subsequence-in-onlogn-time

*/



vector<int>a,b,c;

int lis(vector<int> & a) {
    int n = a.size();
    
    vector<int>dp(n+1, INF); // notice extra element
    dp[0] = -INF;
    
    for(int i=0; i<n;++i) {
        int j = upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin(); // notice when element is not found then j will be n+1, and dp[n+1] = INF; so it's fine.
        
        
        if(dp[j-1] < a[i] && a[i] < dp[j]) {
            dp[j] = a[i];
        }
    }
    
    for(int i=n; i>=0; --i) {
        if(dp[i] <INF)
        return i;
    }
    return 0;
}

int lcs() {
    
   
    for(int i=0; i<b.size(); ++i) {
        int j =  lower_bound(a.begin(), a.end(), b[i]) - a.begin(); // if no element is found then a.end() is returned
        
        if(j == a.size()) {
            // b[i] doesn't exists in a;
            continue;
        }
        c.pb(j);
    }
    
    return lis(c);
}

int main() {
    
    int i, n,m;
    cin>>n>>m;
    for(i=0;i<n;++i) {
        int x;
        cin>>x;
        a.pb(x);
    }
    for(i=0;i<m;++i){
        int x;
        cin>>x;
        b.pb(x);
    }
    
    
    cout<<lcs()<<"\n";
   
    
	return 0;
}
