/**

1. Spaces only after words; No space after last word;
2. One space should occur after every word.
*/

#define pb push_back

class Solution {
public:
    
    string handleOneWord(vector<string> a, int w) {
        string s = a[0];
        while(s.length() != w)
            s += " ";
        return s;
    }
    
    void removeEndSpace(vector<string> &a) {
        int n = a.size();
        string x = a[n-1];
        x.pop_back();
        a[n-1]= x;
    }
    
    vector<string> addSpace(vector<string> a, int space, int extra) {
        int i=0;
        vector<string> ans;
        
        for(i=0; i<a.size(); ++i) {
            string s = a[i];
            
            if(i == a.size()-1) { // don't add space after last word in line
                ans.pb(s);
                continue;
            }
            
            for(int j=0; j<space; ++j) {
                s += " ";
            }
            if(i+1 <= extra)
                s+= " ";
            
            ans.pb(s);
        }
        return ans;
    }
    
    string getString(vector<string> a) {
        string s;
        for(string x: a)
            s+= x;
        return s;
    }
    
    string handleLastLine(vector<string> a, int spaces) {
        string s = getString(a);
        for(int i=0; i<spaces; ++i)
            s+=" ";
        
        return s;
    }
    
    vector<string> fullJustify(vector<string>& words, int w) {
        
        int len =0;
        vector<string> ans;
        vector<string> line;
        for(int i=0; i<words.size();) {
            string s = words[i];
            
            if(len + s.length() <= w) {
                s += " ";
                len += s.length();
                line.pb(s);
                ++i;
            }
            else {
               
                // remove space from end of last word; 
                removeEndSpace(line);
                len--;
                
                if(line.size() == 1) {
                    // line has only word, all spaces at end
                    ans.pb(handleOneWord(line, w));
                }
                else {
                    int total = w - len;
                    int slots = line.size()-1;

                    int spaces = total/slots;
                    int extra = total%slots;

                    line = addSpace(line, spaces, extra);

                    ans.pb(getString(line));
                }
                
                line.clear();
                len = 0;
            }
        }
        
        // remove space from end of last word; 
        removeEndSpace(line);
        len--;
        string x = handleLastLine(line, w-len);
        ans.pb(x);
        
        return ans;
    }
};
