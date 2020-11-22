// just split the string by '/'
// and pop back from ans when /.. encountered.
// keep a vector not a string to pop back whole word instead of just a character.
// stack can also be used

class Solution {
public:
    
    vector<string> split(string s, char sep) {
        vector<string> splits;
        stringstream stream(s);
        
        string intermediate;
        while(getline(stream, intermediate, sep)) {
            splits.push_back(intermediate);
        }
        return splits;
    }
    
    string simplifyPath(string path) {
        
        vector<string> splits = split(path, '/');
        vector<string> ans;
        
        for(string s: splits){
            if(s == "..") {
                if(ans.size() > 0)
                ans.pop_back();
            }
            else if(s == "." || s == "") {
                // do nothing
            }
            else {
                ans.push_back(s);
            }
        }
        string x;
        for(string s: ans) {
            x+= "/";
            x+= s;
        }
        
        if(x == "") x = "/";
        return x;
    }
};
