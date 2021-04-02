/**

From current string, we can remove 1 char;
form strings for next level by remoeving a single '(' or ')'.
Try this for all positions.
Ex: s = (ab)())
Then next level strings are:
ab)())
(ab())
(ab)))
(ab)()
(ab)()

Since last 2 are same, we only consider one of them.

Now keep on doing this process until we get a valid string;
dfs won't work cause it will not give answer with minimum removal(longest valid string)

However, bfs is done level wise, so it will work.

Once you encounter a valid string, stop at that level.
And also check for other valid string in the q after bfs terminates.


Time: n*2^n

We can remove 0 char to form valid string. Total ways = nc0
We can remove 1 char to form valid string. Total ways = nc1
We can remove 2 char to form valid string. Total ways = nc2


We can remove n char to form valid string. Total ways = ncn

nc0 + nc1 + ... ncn = 2^n

Once we remove a char, we traverse the string to form the new string, so n comes from that.


*/

class Solution {
public:
    vector<string> ans;
    unordered_map<string, bool> visited; // this also removes duplicate states
    bool valid(string s) {
        int l = 0;
        for(auto ch: s) {
            if(ch == '(')
                l++;
            else if(ch == ')')
                l--;
            
            if(l < 0)
                return false;
        }
        return l==0;
    }
    
    void bfs(string s) {
        queue<string> q;
        q.push(s);
        visited[s] =1;

        while(!q.empty()) {
            string p = q.front(); q.pop();
            if(valid(p)) {
                ans.push_back(p);
                break;
            }

            // remove ith character & check
            for(int i=0; i<p.length(); ++i) {
                string t;
                if(p[i] == '(' || p[i] == ')') {
                    for(int j=0; j<p.length(); ++j) {
                        if(j != i)
                            t+=p[j];
                    }

                    if(!visited[t]) {
                        q.push(t);
                        visited[t] = 1;
                    }
                }
            }
        }
        
        // don't forget this; queue still can have valid strings; extract them
        while(!q.empty()) {
            string p = q.front(); q.pop();
            if(valid(p))
                ans.push_back(p);
        }
            
    }
    vector<string> removeInvalidParentheses(string s) {
        bfs(s);
        return ans;
    }
};
