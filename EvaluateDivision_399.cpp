/*
Both of the dfs funcs below work.
simple dfs from src to dst; no need to calculate shortest path cause result will be same from any path.

map each string to an int to construct graph.

cases like disconnected graph, same num & denom; divide by zero
*/

#define pii pair<int, double>
#define N 105
#define pb push_back
#define eps 0.00001

vector<pii> gr[N];
int nodes =1;
map<string, int> m;
bool visited[N];

class Solution {
public:
    
    int getNodeNumber(string name) {
        if(m.find(name) != m.end())
            return m[name];
        m.insert({name, nodes});
        return nodes++;
    }
    
    int getExistingNode(string name) {
        if(m.find(name) != m.end())
            return m[name];
        return -1;
    }
    
    // will return whether dst found in the subtree & the answer from src to dst
    // ans is calculated as wt of cur node * ans of child(only if dst lies in the subtree of child)
    pair<bool, double> dfs(pii v, int dst) {
        visited[v.first] = true;
        
        if(v.first == dst) {
            return {true, v.second};
        }
        
        
        for(auto c: gr[v.first]) {
            if(!visited[c.first]) {
                auto cur = dfs(c, dst);
                if(cur.first) { // found in this subtree
                    return {true, v.second * cur.second};
                }
            }
        }
        
        return {false, 0};
    }
    
    bool dfs(pii v, int dst, double &ans) {
        visited[v.first] = true;
        
        if(v.first == dst) {
            return true;
        }
        
        bool found = false;
        
        for(auto c: gr[v.first]) {
            if(!visited[c.first]) {
                auto cur = dfs(c, dst, ans);
                if(cur) { // found in this subtree
                    found = true;
                    ans *= c.second;
                }
            }
        }
        
        return found;
    }
    
    
    vector<double> calcEquation(vector<vector<string>>& eqs, vector<double>& values, vector<vector<string>>& queries) {
        
        nodes =1;
        m.clear();
        fill(visited, visited+N, false);
        for(int i=0; i<N;++i)
            gr[i].clear();
        
        for(int i=0; i<eqs.size(); ++i) {
            auto eq = eqs[i];
            double wt = values[i];
            
            int src = getNodeNumber(eq[0]);
            int dst = getNodeNumber(eq[1]);
            
            gr[src].pb({dst, wt});
            if(wt != 0)
                gr[dst].pb({src, 1/wt});
        }
        
        
        vector<double> ans;
        for(auto q: queries) {
            fill(visited, visited+nodes, false);
            int src = getExistingNode(q[0]);
            int dst = getExistingNode(q[1]);

            double x = -1.0;
            bool found = false;
            if(src != -1 && dst != -1) {
                if(src != dst) {
                    auto curans = dfs({src, 1.0}, dst);
                    found = curans.first;
                    x = curans.second;
                    
                    // double ans = 1.0;
                    // found = dfs({src, 1.0}, dst, ans);
                    // x = ans;
                        
                }
                else { // same src & dst & both present in graph
                    x = 1.0;
                    found = true;
                }
            }
            else { // node not in graph
                x = -1.0;
            }
            
            if(!found)
                x = -1.0;
            ans.pb(x);
            
        }
        return ans;
    }
};
