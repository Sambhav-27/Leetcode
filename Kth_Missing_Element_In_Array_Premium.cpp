/*

https://www.geeksforgeeks.org/k-th-missing-element-in-sorted-array/
https://medium.com/@edward.zhou/leet-code-1060-missing-element-in-sorted-array-explained-python3-solution-a1277b6ce32b
https://leetcode.com/problems/missing-element-in-sorted-array/

not submitted anywhere

*/

#include<bits/stdc++.h>
using namespace std;

int fun(vector<int> a, int k) {
    int b =0;
    int e = a.size()-1;
    
    if(k <= 0)
        return -1;
        
    int diff = a[e] - a[0] - (a.size()-1);
    if(k > diff) {
        return a[e] + k - diff;
    }
    
    while(b <= e) {
        
        int m = b + (e-b)/2;
        int diff = a[m] - a[0] - m;
        
        if(m != 0) {
            int prevdiff = a[m-1] - a[0] - (m-1);
            
            if(diff >=k && prevdiff <k) {
                int del = k - prevdiff;
                return a[m-1]+del;
            }
        }
        if(diff < k) {
            b = m;
        }
        else if(diff > k) {
            e = m;
        }
    }
    return -1;
}
int main() {
    
    vector<int> a = {2, 3, 5, 9, 10};;
    int k = 1; // ans = 8
    
    // cout<<fun(a, 5);
    for(int i=1; i<13; ++i) {
        cout<<i<<": "<<fun(a, i)<<"\n";
    }
    
}
