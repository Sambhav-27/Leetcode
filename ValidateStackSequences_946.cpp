/**
Implementation based.
Can be done in O(1) space by just two pointers and not maintaining a stack.

keep on pushing from pushed array; before pushing check if current element to be pushed equal to popped element;
if yes, then pop from stack.


*/

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        
        int i=0,j=0;
        while(i<pushed.size()) {
            // first check if equal to top element;
            if(!s.empty() && s.top() == popped[j]) {
                j++;
                s.pop();
            } else {
                s.push(pushed[i++]);
            }
        }

        // check rest of the stack
        while(!s.empty()) {
            if(s.top() != popped[j])
                return false;
            s.pop(); j++;
        }
        
        return true;
    }
};


-----------








/**
Implementation based.
Can be done in O(1) space by just two pointers and not maintaining a stack.
*/

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        
        int i=0,j=0;
        while(i<pushed.size()) {
            // first check if equal to top element;
            if(!s.empty() && s.top() == popped[j]) {
                j++;
                s.pop();
            }
            else {
                if(pushed[i] == popped[j]) {
                    i++; j++;
                }
                else {
                    s.push(pushed[i++]);
                }
            }
        }
        
        while(!s.empty()) {
            if(s.top() != popped[j])
                return false;
            s.pop(); j++;
        }
        
        return true;
    }
};
