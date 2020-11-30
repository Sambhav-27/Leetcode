/*
Question is to basically find lexicographically smallest sequence.
first element is min element from [0, n-k]
second element is min from [index of 1st element, n-k+1]
third element is min from[index of 2nd elemnt, n-k+2]




We keep a monotonically increasing(duplicates allowed) stack with botton = smallest & top = largest
Stack size should never reach more than k.

at the end stack will contain the ans from bottom to top.

If cur element is less than top of stack, we keep on popping from stack.
But we make sure that we don't pop all the elements such that we can't even select k elements.
Thus we see that if rest of the elements can make the stack size k, if yes, then only we pop


*/

class Solution {
public:
   
    vector<int> mostCompetitive(vector<int>& a, int k) {
        
        stack<int> s;
        int n = a.size();
        for(int i=0; i<n; ++i) {

            while(!s.empty() && s.top() > a[i]) {
                int totalElementsLeftInArray = n-i; // elements yet to be seen including current
                int totalElementsLeftToSelect = k - (s.size()-1); // -1 because we will pop this element
                
                if((totalElementsLeftInArray >= totalElementsLeftToSelect)) {
                    s.pop();
                }
                else break;
            } 
            
            if(s.size() < k)
                s.push(a[i]);
        }
        
        
        vector<int> ans;
        while(!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};
