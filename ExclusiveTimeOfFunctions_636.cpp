/**
Again just implementation;
End time in problem statement is confusing.
See this to understand:
https://leetcode.com/problems/exclusive-time-of-functions/discuss/105084/How-is-function-1-executing-4-units-of-time


if it is start then:
update time for stack top & push this item;
else 
pop & update time of popped(cur) item; popped & cur will have same id;
Also, update the time of top element to cur time;

*/
struct pii {
    int id,time;
     
    pii() {}
    pii(int a, int b) {
        id=a; time=b;
    }
};


class Solution {
public:
    
    vector<string> splitString(string s) {
        vector<string> tokens;
        
        // obtain a c style string from c++ string
        char * cstr = new char[s.length() +1]; // note the dynamic allocation 
        strcpy(cstr, s.c_str()); // s.c_str() return a const string
        
        char * p = strtok(cstr, ":");
        while(p) {
            tokens.push_back(p); // note how returned value can be put in a c++ string
            p = strtok(NULL, ":"); // strtok internally maintains a static pointer to the next token, so if we pass null, it uses that pointer.
        }
        return tokens;
    }
    
    vector<int> exclusiveTime(int n, vector<string>& a) {
        
        stack<pii> s;
        vector<int> ans(n);
        
        for(auto cur: a) {
            vector<string> tokens = splitString(cur);
            int curtime = stoi(tokens[2]);
            int curid = stoi(tokens[0]);
            
            if(tokens[1] == "start") {
                if(!s.empty()) {
                    pii p = s.top();
                    ans[p.id] += curtime - p.time;
                }
                s.push(pii(curid, curtime));
            }
            else {
                // id of stack top and cur should be same & stack should be non empty
                
                curtime +=1; // apparently problem statemnt is such that end time is given as 1 less
                pii p = s.top(); s.pop();
                ans[p.id] += curtime - p.time;
                
                if(!s.empty()) {
                    // update start time of stack top;
                    pii prev = s.top(); s.pop();
                    s.push(pii(prev.id, curtime));
                }
                
            }

        }
        
        return ans;
    }
};
