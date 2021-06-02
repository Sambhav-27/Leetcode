/**
https://www.lintcode.com/problem/892/

Takes care of all cases:
- When we don't know order of some letters.
- When invalid sequence/cycle is present
- when prefix of a word occurs after the word.

Time: O(E + V) + O(nm)
V = total distinct chars
E = total edges; total rules; which can in worst case be V*V

n = total words;
m = letters in each word
*/

class Solution {
public:
    unordered_map<char, vector<char>> gr;

    unordered_map<char, bool> visited, recurstack;
    stack<char> order;

    // also checks if cycle exists in the graph
    bool dfs(char v){
        visited[v]=1;
        recurstack[v] = 1;
        for(auto ch: gr[v]) {
            if(visited[ch] && recurstack[ch]) {
                order.push(v);
                return 1;
            }
            
            if(!visited[ch]) {
                if(dfs(ch)) {
                    order.push(v);
                    return 1;
                }
                
            }
        }
        recurstack[v] = 0;
        order.push(v);
        return 0;
    }

    string fun(vector<string> &dict) {

        int i,j,n1,n2;
        for(i=0;i<dict.size()-1;++i){
            string w1=dict[i];
            string w2=dict[i+1];
            n1=w1.length();
            n2=w2.length();

            for(j=0;j<min(n1,n2);++j){
                if(w1[j]!=w2[j]){
                    gr[w1[j]].push_back(w2[j]);
                    break;
                }
            }
            // to check if next word is a prefix of current word
            // Ex; cur = abc next = ab
            // then return ""
            if(j == n2 && n2 < n1) { 
                return "";
            }
        }
        
        // add letters whose order we don't know about
        // add to graph; can't just create a string cause it will have duplicates
        for(auto word: dict) {
            for(auto ch: word) {
                if(gr.find(ch) == gr.end()) {
                    gr[ch] = vector<char>();
                }
            }
        }
        
  
        // traverse from back cause we want the lexicographically smallest string
        // and our dfs puts everything in stack & we later on reverse
        for(char ch = 'z'; ch>='a'; --ch) {
            if(!visited[ch] && gr.find(ch) != gr.end()) {
                if(dfs(ch)) {    
                    return "";
                }
            }
        }

        string ans;
        while(!order.empty()) {
            ans += order.top();
            order.pop();
        }
        return ans;   
    }

    string alienOrder(vector<string> &words) {
        // Write your code here
        return fun(words);
    }
};
