#define DL '$'
#define SEP '|'

class Codec {
public:
    
    // instead of a string, we can just use a vector of strings & avoid the separator
    string s;
    void fun(TreeNode* root) {
        if(!root) {
            s += DL;
            s += SEP; // don't forget sep after null children
            return;
        }
        
        s += to_string(root->val);
        s += SEP;
            
        fun(root->left);
        fun(root->right);
    }

    
    TreeNode* defun(string s, int &index) {
        if(index == s.length() || s[index] == DL) {
            index++;
            return NULL;
        }
        
        string val;
        while(index < s.length() && s[index] != SEP) {
            val += s[index++];
        }
        
        TreeNode * root = new TreeNode(stoi(val));
        
        index++; // notice that the recursive children are not 2*i, 2*i+1; It's just a simple increment on string
        root->left = defun(s, index);
        
        index++;
        root->right = defun(s, index);
        
        return root;
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        s = "";
        fun(root);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int index = 0;
        return defun(data, index); // we cannot just pass 1 when using pass by reference cause 1 is temp variable
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
