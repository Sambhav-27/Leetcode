#include <bits/stdc++.h>
using namespace std;
#define N 32

/*
find max xor of any two numbers in an array.

https://www.quora.com/q/threadsiiithyderabad/Tutorial-on-Trie-and-example-problems
https://leetcode.com/discuss/interview-question/821928/Google-online-coding-challenge-August-2020

    Store bits of the numbers in a trie.
    We need a func that can give max Xor of a number y with all elements of array.
    travers y from msb to lsb; and if a bit is 1 we try to go on opposite side of tree to maximize xor, and vice-versa
*/


struct Node {
    map<int,  Node*> m;
    bool end;
    
    Node() {
        this->m.clear();
        this->end = 0;
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
    }
    root->end = true;
}

// returns number with which XOR is max
// i.e. X ^ val = xor; returns that X which gives max xor
int findMax(Node* root, int val) {
    int ans =0;
    for(int i=N-1; i>=0; --i) {
        int x = val & (1<<i);
        if(x) x = 1; // x contains 1 if ith bit is set;
        
        
        if(root->m[1-x]) {  // first try opposite children
            root = root->m[1-x];
            ans |= ((1-x)<<i);
        }
        else if(root->m[x]) {
            root = root->m[x];
            ans |= (x<<i);
        }
    }
    return ans;
}

int main() {
   
    Node * root = new Node();
    // insert(root, 3);
    // insert(root, 4);
    // insert(root, 6);
    
    // int x = findMax(root, 3);
    // cout<<"\n"<<x<<"  ";
    
    
    
    int a[10],n;
    cin>>n;
    int ans =0;
    for(int i=0; i<n;++i) {
        cin>>a[i];
        insert(root, a[i]);
        
        int num2 = findMax(root, a[i]);
        
        ans = max(ans, num2^a[i]);
    }
    
    cout<<ans<<"\n";
    
    return 0;
}

