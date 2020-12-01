/*
1. First multiply all odd numbers by 2. Now only operation left is on even numbers(divide). So numbers can only decrease from here.

2. Now we need to find the min element & max element and calulate the ans. After doing this, try to reduce the max element by dividing it. We can only reduce a number until it becomes odd (cause after it becomes odd, we can only increase it.)
Reduce a number and then find the max again (also the ans) & then again reduce it.

Good observation: Once the max element becomes odd, we should stop the process of calculating the ans.
Cause all even numbers would be smaller than it & we want to take the diff of min & max element.
And once max is odd, we can only increase it (which we don't want to do, to minimize the ans).


3. So at every step, we want the min element & max element, and we replace the max element with it's half.

min element can be found by just keeping a variable & updating it every time a new number is added.

For finding max element, we need a max heap cause we are not only adding new numbers, we are also removing numbers and the number removed can be the max element, so we need to find the next max element and this heap.


*/

#define INF 1000000009

class Solution {
public:
    int minimumDeviation(vector<int>& a) {
        
        priority_queue<int> q;
        int small= INF;
        
        for(auto n: a) {
            if(n%2)
                n*=2;
            q.push(n);
            small = min(small, n);
        }
        
        int ans = INF;
        
        while(!q.empty()) {
            if(q.top() %2) break;
            
            int maxElement = q.top(); q.pop();
            ans = min(ans, maxElement-small);
            
            int newElement = maxElement/2;
            small = min(small, newElement);
            q.push(newElement);
        }
        
        ans = min(ans, q.top()-small); // don't forget this; consider last odd element at top of queue
        return ans;
    }
};
