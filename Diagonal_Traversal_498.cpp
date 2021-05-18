/*
https://leetcode.com/problems/diagonal-traverse/

Notice it is spiral traversal.
Time: O(n *m)

For every elemnt, put its right element for next line. Also, put the bottom element of the last element.


*/

struct Node {
    int x,y;
    Node() {}
    Node(int x, int y): x(x), y(y){}
};


class Solution {
public:
    
    int n,m;
    bool safe(int x, int y) {
        return x>=0 && x<n && y>=0 && y<m;
    }
    
    void insert(vector<Node> & a, Node cur, int line) {

        if(safe(cur.x, cur.y+1)) {
            a.push_back(Node(cur.x, cur.y+1));
        }
    }
    
    vector<int> findDiagonalOrder(vector<vector<int>>& a) {
        n = a.size();
        m = a[0].size();
        vector<int> ans;
        
        vector<Node> v;
        
        v.push_back(Node(0,0));
        
        int line = 0;
        while(v.size() > 0) {
            vector<Node> next(0);
            
            if(line%2 == 0) { // going up
               for(int i=0; i<v.size(); ++i) {
                
                    Node cur = v[i];
                    ans.push_back(a[cur.x][cur.y]);

                    if(safe(cur.x+1, cur.y) && cur.x == line) { // down element first
                        next.push_back(Node(cur.x+1, cur.y));
                    }
                    insert(next, cur, line);

                } 
            }
            else {
                for(int i= v.size()-1; i>=0; --i) { // going down
                
                    Node cur = v[i];
                    ans.push_back(a[cur.x][cur.y]);

                    insert(next, cur, line);

                    if(safe(cur.x+1, cur.y) && cur.x == line) { // down element at last
                        next.push_back(Node(cur.x+1, cur.y));
                    }
                }
                reverse(next.begin(), next.end()); // don't forget this

            }
            v = next;
            line++;
            
        }
        return ans;
    }
};
