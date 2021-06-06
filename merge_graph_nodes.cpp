/*

https://leetcode.com/discuss/interview-question/715406/Facebook-merge-graph-nodes

*/

struct Node {
    string name;
    unordered_set<Node> children;
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        
        unordered_map<Node, vector<Node>> parents; // calculate parents in another func
        
        vector<Node> nodes; // all nodes
        
        for(auto node: nodes) {
            if(parents.find(node) == parents.end())
                continue;
            
            if(node.children.size() == 1 && parents[node.children[0]].size() == 1)  {
                string rename;
                rename += node.name;
                
                Node decend = node.children[0];
                
                while(parents[decend].size() == 1) {
                    rename += decend.name;
                    
                    parents.erase(decend);
                    if(decend.children.size() != 1) break;
                    decend = decend.children[0];
                }
                
                Node merge = new Node(rename, decend.children);
                
                parents[merge] = parents[node];
                
                for(Node grandchild : decend.children) {
                    parents[grandchild] = vector<string>{merge.name};
                }
                
                for(string parent : parents[node]) {
                    parent.children.erase(node);
                    parent.children.add(node);
                }
                
                parents.remove(node);
            }
        }
    }
};
