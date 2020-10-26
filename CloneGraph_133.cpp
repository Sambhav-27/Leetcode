/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

#define N 105
#define pb push_back
vector<bool> visited(N);
map<int, Node*> m;

Node* getNode(Node * node) {
    Node * t = new Node();
    t -> val = node -> val;
    t->neighbors = vector<Node*>();
    return t;
}

class Solution {
public:
    
    void dfs(Node * node, Node* cloneRoot) {
        visited[node->val] =1;
        
        for(Node * c: node->neighbors) {
            if(!visited[c->val]) { // visited array can be reduced by the map
                
                Node * cloneChild =  new Node(c->val);
                m[c->val] = cloneChild;
                
                cloneRoot->neighbors.pb(cloneChild);
                
                dfs(c, cloneChild);
            }
            else {
                Node * cloneChild = m[c->val]; // we need map to get the alraedy created node
                cloneRoot->neighbors.pb(cloneChild); // bewarehere, add only the cloned node
            }
        }
    }
    
    Node* cloneGraph(Node* node) {
        
        fill(visited.begin(), visited.end(), 0);
        m.clear();
        
        if(!node) return node;
        
        // create root node
        Node * cloneRoot = new Node(node->val);
        m[node->val] = cloneRoot;
        dfs(node, cloneRoot);
        
        return cloneRoot;
    }
};
