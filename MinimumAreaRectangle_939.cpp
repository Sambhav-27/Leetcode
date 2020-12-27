/**
O(n^2)

Pick two points and assume they are diagonal points then check if the opposite diagonal points exists or not.
For checking points, use an unordered_set.

*/
#define INF 1e9
#define pii pair<int, int>

class MyHashFunction { 
public: 
  
    int operator()(const pii& p) const
    { 
        hash<int> hashInt;
        return hashInt(p.first) ^ hashInt(p.second);
    } 
}; 

class Solution {
public:
    int minAreaRect(vector<vector<int>>& a) {
        
        unordered_set<pii, MyHashFunction> s;
        for(auto p: a) {
            s.insert({p[0], p[1]});
        }
        
        int n=a.size();
        int ans = INF;
        for(int i=0; i<n; ++i) {
            for(int j=i+1; j<n; ++j) {
                int x1 = a[i][0];
                int y1 = a[i][1];
                
                int x2 = a[j][0];
                int y2 = a[j][1];
                
                if(s.find({x1,y2}) != s.end() && s.find({x2,y1}) !=s.end()) {
                    int area = abs(x2-x1) * abs(y2-y1);
                    if(area != 0) // don't forget this
                    ans = min(ans, area);
                }
            }
        }
        if(ans == INF)
            ans = 0;
        return ans;
    }
};
