#include <bits/stdc++.h>
using namespace std;
#define N 32
#define M 100005
#define lld long long

/*
https://www.spoj.com/problems/SUBXOR/

https://www.quora.com/q/threadsiiithyderabad/Tutorial-on-Trie-and-example-problems

XOR(L, R) = XOR(1, L-1) ^ XOR(1, R)


Suppose we have a func query(q, k) that can give total number in a list whose xor with q is less than k.
i.e. if((a[i]^ q) < k) ans++;
and this works in logn time.

Now we consider every subarray which end at position i; We count these subarray for every i and that is our answer.

maintain p = a[1] ^ a[2] ... ^ a[i]
& in the tree we have a[1], a[1]^a[2], a[1]^a[2]^a[3], ..... a[1]^a[2]...a[i-1];

& NOTICE a[1] ^ p means XOR(2, i)
a[1]^a[2] ^ p means XOR(3, i)


Thus query(p, k) can give ans for every i.


How to implement query(q, k):

start from msb, consider every bit of q & k.
we want to take that route in trie that satisfies curBit ^ qi = ki;
Ex- qi = 1, ki = 1;

then add total leaf nodes of right child (1) because 1^qi = 1^1 = 0 will always be less thn ki.
and then proceed to the left child to do the same for every bit.




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

// return total numbers whose xor with q is less than k
lld query(Node* root, int q, int k) {
    lld ans =0;
    
    for(int i=N-1; i>=0; --i) {
        
        int qi= q & (1<<i);
        if(qi) qi = 1;
        
        int ki = k & (1<<i);
        if(ki) ki = 1;
        
        if(!root) break;
        
        // cur ^ qi = ki
        // cur is current bit in tree; we know qi & ki, so we are trying to pick cur such that the number becomes less than k
        if(qi && ki) {
            if(root->m[1])
                ans += root->m[1]->sum;
            
            root= root->m[0];
        }
        else if(!qi && ki) {
            if(root->m[0])
                ans += root->m[0]->sum;
                
            root = root->m[1];
        }
        else if(qi && !ki) {
            root = root->m[1];
        }
        else if(!qi && !ki) {
            root = root->m[0];
        }
    }
    return ans;
}

lld fun(vector<int> a, lld n, lld k) {
    lld i, prefix =0, ans =0;
    Node * root = new Node();
    
    insert(root, 0); // add 0 to consider 1 to i range
    
    for(i=0; i<n; ++i) {
        
        prefix = prefix ^ a[i];
        
        ans += query(root, prefix, k); // notice query before inserting this prefix
        
        insert(root, prefix);

    }
    return ans;
}
int main() {
   
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    lld i,t,n,k;
    vector<int> a(M);
    cin>>t;
    while(t--) {
        cin>>n>>k;
        for(i=0;i<n;++i)
        cin>>a[i];
        
        cout<<fun(a, n, k)<<"\n";
    }
    
    return 0;
}

