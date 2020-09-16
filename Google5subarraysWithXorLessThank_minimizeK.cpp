#include <bits/stdc++.h>
using namespace std;
#define N 20
#define M 100005
#define INF 1e9
#define lld long long

/*

https://leetcode.com/discuss/interview-question/813904/google-invitation-for-coding-question.

You are given an array, find the minimum k, such that the count of number of subarrays whose xor is atmost k, is atleast x.

1<=N<=1e5

simplified question:

total subarray >= x
XOR of each subarray <= k

find min k.

Notice, in this question it is <=k not <k. The other question about trie is just less than k.
https://www.spoj.com/problems/SUBXOR/

*/


struct Node {
    map<int,  Node*> m;
    int sum; // stores number of leafnodes under this node; which is equal to total number undr this node
    
    Node() {
        this->m.clear();
        this->sum = 0;
    }
};

void insert(Node* root, int n) {
    for(int i=N-1; i>=0; --i){
        int x = n & (1<<i);
        if(x) x =1;
        
        if(!root->m[x]) {
            root->m[x] = new Node();
        }
        
        root = root->m[x];
        
        root->sum += 1;
    }
}

// return total numbers whose xor with q is more than k
lld query(Node* root, int q, int k) {
    lld ans =0;
    
    for(int i=N-1; i>=0; --i) {
        
        int qi= q & (1<<i);
        if(qi) qi = 1;
        
        int ki = k & (1<<i);
        if(ki) ki = 1;
        
        if(!root) break;
        
        
        // cur ^ qi = ki
        // cur is current bit in tree; we know qi & ki, so we are trying to pick cur such that the number becomes greater than k
        if(qi && ki) {
            root= root->m[0];
        }
        else if(!qi && ki) {
            root = root->m[1];
        }
        else if(qi && !ki) {
            if(root->m[0])
                ans += root->m[0]->sum;
                
            root = root->m[1];
        }
        else if(!qi && !ki) {
            if(root->m[1])
                ans += root->m[1]->sum;
            root = root->m[0];
        }
    }
    return ans;
}
 
// returns true if (total subarrays with xor < k) is >=totsubArraysLowerLimit
bool fun(vector<int> a, lld n, lld k, int totsubArraysLowerLimit) {
    lld i, prefix =0, ans =0;
    Node * root = new Node();
    
    insert(root, 0); // add 0 to consider 1 to i range
    
    for(i=0; i<n; ++i) {
        
        prefix = prefix ^ a[i];
        
        int more  = query(root, prefix, k); // notice query before inserting this prefix
        
        lld total = (i*(i+1))/2; // total subarrays  N(N+1)/2 ; here N = i; Notice i is from 0; and in first iteration trie wil have 0 elements
        int lessEqual = total - more; // subarrays with xor <= k = total subarrays - subarrays with xor > k
        
        
        ans +=lessEqual;
        
        if(ans >= totsubArraysLowerLimit) return true;
        insert(root, prefix);
 
    }
    
    // cout<<k<<":"<<ans<<"    ";
    return ans >= totsubArraysLowerLimit;
}

/*

if a[i] < 10^6 then first 20 bits are sufficient
try to reduce upper limit of k in binary search to further reduce time complexity.
O(n * 32bits * binarySearch)

also note that as you increase K then total subarrays increase, so binary search can be applied. (Not checked anywhere)

*/
lld binarySearch(vector<int> a, int n, int x) {
    
    int beg = 1, end = 10;
    int ans = INF;
    while(beg <= end) {
        
        int mid = (beg + end)/2; // mid is our k 
        
        if(fun(a, n,  mid, x)) {
            end = mid -1;
            ans = min(ans, mid);
        }
        else {
            beg = mid+1;
        }
    }
    return ans;
}

int main() {
   
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    lld i,n,x;
    vector<int> a(M);
    cin>>n>>x;
    for(i=0;i<n;++i)
    cin>>a[i];
    
    cout<<binarySearch(a, n, x)<<"\n";
    
    return 0;
}

