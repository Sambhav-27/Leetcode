// just see balacnced paranthesis; rest all is extra and should be removed;
// question is not to count min character to remove
// but also return a valid string

class Solution {
public:
    string minRemoveToMakeValid(string a) {
        stack<int> s; // store index
        
        set<int> extra; // stores indices of removed characters
        
        for(int i=0; i<a.length(); ++i) {
            char ch = a[i];
            if(ch == ')') {
                if(!s.empty()) {
                    s.pop();
                }
                else {
                    // ans++;
                    extra.insert(i);
                }
            }
            else if (ch== '(') {
                s.push(i);
            }
        }
        
        while(!s.empty()) {
            // ans++;
            extra.insert(s.top());
            s.pop();
            
        }
        
        string ans;
        for(int i=0; i<a.length(); ++i) {
            if(extra.find(i) == extra.end()) {
                ans += a[i];
            }
        }
        return ans;
        
    }
};
