#include <bits/stdc++.h>
using namespace std;
#define N 100005

/*

Do this first: https://github.com/Sambhav-27/Leetcode/blob/master/slidingWindowMax_usingDeque.cpp

Q2 of
https://leetcode.com/discuss/interview-question/818100/Google's-Online-Challenge-Coding-Intern-(India)

Just keep track of maximum element of window, and total opertions required for particular window is: (length of window * max. of window) - sum of window.
if (length of window * max. of window) - sum of window>K, slide starting pointer of window.

*/
int fun(int*a, int n, int k) {
    int beg, end,i,size;
    
    beg = end =0;
    int maxx = a[0], sum = a[0];
    int ans = 1;
    deque<int> q;
    q.push_back(0); // 0th index
    
    while(end < n) {
        
        // notice that beg can never become > end
        // cuz as soon as beg == end & diff will be 0 & thus diff won't be > k. Thus end will move, not beg.
        
        maxx = a[q.front()];
        size = end-beg+1;
        
        cout<<beg<<","<<end<<": "<<maxx<<"   ";
        int diff = size*maxx - sum;
        
        
        if(diff <= k) { // increase window to right; notice <=; if it is equal inrease window;
                        // so that in next iteration next window can be considered. Ex k=0; a= 8,6,7
            end++;
            sum += a[end];
            
            // while increaing elements will be added at back in sorted order; front has largest
            while(!q.empty() && a[q.back()] <= a[end]) q.pop_back();
            q.push_back(end);
            
            ans = max(ans, size);
            
        }
        else { // decrease window by moving beg
            sum -= a[beg];
            beg++;
            
            // while decreasing elements will be removed from  front
            while(!q.empty() && q.front() < beg) q.pop_front();
        }
    }
    return ans;
}


int main() {
   
   
   int i,test,n,k,a[N];
   cin>>test;
   
   while(test--){
       cin>>n>>k;
       for(i=0;i<n;++i)
       cin>>a[i];
       
       
       cout<<fun(a, n, k)<<"\n";
   }
   
    
	return 0;
}
