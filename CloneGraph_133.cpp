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

/*


Just do a dfs a create a copy of all the nodes.

Just keep track of all the nodes that you have created before; Do not recreate a node;
Add the children irrespective of whether they have been visited before or not because we need to add all the edges.


*/


class Solution {
    
public:

     vector<bool> visited = vector<bool>(104, 0); // if declared inside a class as only "vector<bool> visited(104, 0)" then it gets treated as a function declaration and it doesn't work 
    unordered_map<int, Node*> m;


    void dfs(Node* node, Node* cloneRoot) {
        visited[node->val] = 1;

        for(auto child: node->neighbors) {
            Node* cloneChild; 
            
            if(m.find(child->val) != m.end()) { // node already exists
                cloneChild = m[child->val];
            }
            else {
                cloneChild = new Node(child->val);    // don't create new Node with original's neighbors; let it fill using dfs.
                m[child->val] = cloneChild; // don't forget to add to map
            }
            
            cloneRoot->neighbors.push_back(cloneChild);


            if(!visited[child->val]) {

                dfs(child, cloneChild);
            }
            
        }

    }

    Node* cloneGraph(Node* node) {

        if(!node) return NULL;

        Node* cloneRoot = new Node(node->val);
        m[node->val] = cloneRoot; // don't forget to add root to map

        dfs(node, cloneRoot);

        return cloneRoot;
        
    }
};


-----------------------------











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
