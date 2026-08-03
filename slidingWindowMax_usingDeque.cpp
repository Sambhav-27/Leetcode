/**
 
 
 - deque will stores indices of elements cuz we would need to remove out of range elements from queu
 - remove out of range elements from front of dq.
 - dq will be sorted with index of largest element at front, and smallest at back.
 - new element will be added from rear;
 - before adding, remove all smaller elements from back
 
 - max element will be at front of dq.
 
 
 */
 

class Solution {
public:

    deque<int> q;

    void insert(vector<int> &a, int index) {
        // pop while element at end is smaller than new element
        // to maintain monotonic decreasing order from front to back
        while(!q.empty() && a[q.back()] < a[index]) {
            q.pop_back();
        }
        q.push_back(index);
    }

    vector<int> maxSlidingWindow(vector<int>& a, int k) {

        
        vector<int> ans;
        for(int i=0; i<k; ++i) {
            insert(a, i);
        }
        ans.push_back(a[q.front()]);

        for(int i=k; i<a.size(); ++i) { // notice that i tracks end of window

            // pop out of index element from front; 
            // because front has the oldest elements as we're inserting from the back
            while(!q.empty() && q.front() <= i-k) {
                q.pop_front();
            }

            insert(a, i);
            ans.push_back(a[q.front()]);
        }

        return ans;
    }
};


// ----------------------
	


#include<bits/stdc++.h>
using namespace std;
#define N 10000007

/**
 https://www.youtube.com/watch?v=gskwUvaFpnA
 
 - deque will stores indices of elements cuz we would need to remove out of range elements from queu
 - remove out of range elements from front of dq.
 - dq will be sorted with index of largest element at front, and smallest at back.
 - new element will be added from rear;
 - before adding, remove all smaller elements from back
 
 - max element will be at front of dq.
 
 
 */
 
 
int a[N];
int main(){
    
    int i,j,n,k,t;
    cin>>t;
    while(t--) {
        cin>>n>>k;
        for(i=0;i<n;++i) cin>>a[i];
        
        
        deque<int> q;
        for(i=0;i<k;++i) {
            while(!q.empty() && a[q.back()] < a[i]) q.pop_back();
            q.push_back(i);
        }
        
        cout<<a[q.front()]<<" ";
        
        // i is at end of window
        for(i=k;i<n;++i) {
            while(!q.empty() && q.front() <= (i-k)) q.pop_front();
            
            while(!q.empty() && a[q.back()] < a[i]) q.pop_back();
            q.push_back(i);
            
            cout<<a[q.front()]<<" ";
            
        }
        cout<<"\n";
    }
    
   
	
	return 0;
}
