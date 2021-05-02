/*

https://leetcode.com/problems/minimum-height-trees/submissions/
Find minimum height of tree by selecting a root;
Return all the roots which give this minimum ht.

Height = max distance between root & any other node;

Time: bfs: O(E+V)

Notice that answer can have only 1 or 2 nodes. not more than 2.
To minimize the ht of DAG, we will try to make the middle node as the root.


So, start from the leaves. Remove all the leaves.
And then we have new leaves => Remove those leaves.
Keep on doing this until graph has 1 or 2 nodes.


How to do it in bfs:
1. Push all leaves to a vector.
2. For each of these nodes, consider them as parent & remove them from the graph. Add their children for the next iteraation. Add only those children who will becomes leaves after removal of parent.
3. If at any stage,count of children == 0  then we stop.
Children will be 0 when graph has 2 or 3 nodes.


test Cases:

1---2


1----0-----2



0---1---2---4---6
    |
    3
    |
    5
    
    
Diagram: https://leetcode.com/problems/minimum-height-trees/discuss/76055/Share-some-thoughts

https://leetcode.com/problems/minimum-height-trees/discuss/76064/C%2B%2B-BFS-short-clean-solution-with-explanation


*/



class Solution {
public:
    
    unordered_map<int, unordered_set<int>> gr; // we will remove from this graph later on
    
    vector<int> fun() {
       
        vector<int> leaves;
        for(auto x: gr) { // x will be a pair
            
            if(gr[x.first].size() == 1) { // since graph is undirected, we can just check outdegree
                leaves.push_back(x.first);
            }
        }
        
        // we might revisit visited nodes again; so no visited array.
        // bfs traversal level wise from leaves
        while(1) { 
            
            vector<int> next;
            for(auto p : leaves) {
                
                for(auto c: gr[p]) {
                    gr[c].erase(p); // remove the leaf irrespective of whether we are adding its children
                    if(gr[c].size() == 1) { // if c becomes a new leaf
                        next.push_back(c);
                    }
                }
                
                gr.erase(p); // remove leaf
            }
            
            if(next.size() == 0)
                return leaves;
            leaves = next;

        }
        
        return vector<int>(0);
        
    }
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        if(n == 1) { // don't forget this
            return vector<int>{0};
        }
        
        for(auto edge: edges) {
            gr[edge[0]].insert(edge[1]);
            gr[edge[1]].insert(edge[0]);
            
        }
        return fun();
        
    }
};
